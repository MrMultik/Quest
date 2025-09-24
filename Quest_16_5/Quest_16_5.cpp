#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

enum switches {
    LIGHTS_INSIDE = 1 << 0,
    LIGHTS_OUTSIDE = 1 << 1,
    HEATERS = 1 << 2,
    WATER_PIPE_HEATING = 1 << 3,
    CONDITIONER = 1 << 4
};

int main() {
	setlocale(LC_ALL, "");
    int switches_state = 0;
    double color_temp = 5000.0; // текущая цветовая температура (K)

    std::cout << "Симуляция умного дома на 48 часов. Для каждого часа введите в одну строку через пробел:\n";
    std::cout << "temperature_inside temperature_outside movement(yes/no) lights(on/off)\n";
    std::cout << "Пример: 10 10 yes on\n\n";

    for (int hour = 0; hour < 48; ++hour) {
        int hour_of_day = hour % 24;
        // Сброс цветовой температуры в 00:00
        if (hour_of_day == 0) {
            color_temp = 5000.0;
            // (Если свет включён и это изменение состояния цвета - ниже выведем)
        }

        std::cout << "Time " << (hour_of_day < 10 ? "0" : "") << hour_of_day << ":00 - ввод: ";
        std::string line;
        // читаем целую строку (может быть пустая в случае EOF)
        if (!std::getline(std::cin, line) || line.empty()) {
            // Если предыдущая >> оставила символы, попробуем ещё раз
            if (!std::getline(std::cin, line) || line.empty()) {
                std::cerr << "Нет ввода — завершаю симуляцию." << std::endl;
                return 1;
            }
        }

        std::stringstream ss(line);
        double temp_inside, temp_outside;
        std::string movement_str, lights_str;
        if (!(ss >> temp_inside >> temp_outside >> movement_str >> lights_str)) {
            std::cerr << "Неправильный ввод. Ожидалось: inside outside movement lights" << std::endl;
            return 1;
        }

        bool movement = (movement_str == "yes");
        bool lights_input_on = (lights_str == "on");

        // Переменные для отслеживания изменений
        int old_state = switches_state;

        // 1) Включение/выключение обогрева водопровода по температуре снаружи
        if (temp_outside < 0.0) {
            switches_state |= WATER_PIPE_HEATING;
        }
        else if (temp_outside > 5.0) {
            switches_state &= ~WATER_PIPE_HEATING;
        }
        // 2) Наружный свет: вечер — от 16:00 до 5:00 (то есть hour >= 16 or hour < 5)
        bool is_evening = (hour_of_day >= 16) || (hour_of_day < 5);
        if (is_evening && movement) {
            switches_state |= LIGHTS_OUTSIDE;
        }
        else {
            switches_state &= ~LIGHTS_OUTSIDE;
        }
        // 3) Отопление в помещении: включить если <22, выключить если >=25
        if (temp_inside < 22.0) {
            switches_state |= HEATERS;
        }
        else if (temp_inside >= 25.0) {
            switches_state &= ~HEATERS;
        }
        // 4) Кондиционер: включается если >=30, выключается если <=25 (в условии — при 25 отключается)
        if (temp_inside >= 30.0) {
            switches_state |= CONDITIONER;
        }
        else if (temp_inside <= 25.0) {
            switches_state &= ~CONDITIONER;
        }
        // 5) Внутренний свет управляется входом пользователя (on/off)
        if (lights_input_on) {
            switches_state |= LIGHTS_INSIDE;
        }
        else {
            switches_state &= ~LIGHTS_INSIDE;
        }

        // Выводим события — только те, где состояние изменилось
        auto print_if_changed = [&](int flag, const std::string& name_on, const std::string& name_off) {
            bool before = (old_state & flag);
            bool after = (switches_state & flag);
            if (before != after) {
                if (after) std::cout << name_on << std::endl;
                else std::cout << name_off << std::endl;
            }
            };

        print_if_changed(WATER_PIPE_HEATING, "Water pipe heating ON!", "Water pipe heating OFF!");
        print_if_changed(LIGHTS_OUTSIDE, "Lights outside ON!", "Lights outside OFF!");
        print_if_changed(HEATERS, "Heaters ON!", "Heaters OFF!");
        print_if_changed(CONDITIONER, "Conditioner ON!", "Conditioner OFF!");
        print_if_changed(LIGHTS_INSIDE, "Lights ON!", "Lights OFF!");

        // Обновление цветовой температуры:
        // Каждый день с 16:00 до 20:00 (четыре часа) цвет плавно меняется с 5000K до 2700K.
        if (hour_of_day >= 16 && hour_of_day < 20) {
            double fraction = (hour_of_day - 16) / 4.0; // 0.0 .. 0.75 (в строгой дискретной часовой модели)
            // но чтобы получить 2700 в 20:00, если hour==19 -> fraction=0.75, not 1.0.
            // Более корректно: за 4 шагa (16,17,18,19) хотим значения от 5000 до 2700 при счёте с шагом i=0..4:
            // Для простоты сделаем линейную интерполяцию по часу + часть до следующего часа не моделируем.
            // Используем fraction = (hour_of_day + 0.0 - 16) / 4.0
            color_temp = 5000.0 - fraction * (5000.0 - 2700.0);
            // Если hour_of_day == 19, color_temp = 5000 - 3/4*(2300)=5000-1725=3275 -> at 20:00 we will keep or set 2700 explicitly
        }
        else if (hour_of_day >= 20 || hour_of_day < 16) {
            // После 20:00 color temp should remain at 2700 if it reached there, 
            // but we reset at 00:00 to 5000. The task wording says "from 16:00 to 20:00 should change from 5000K to 2700K" 
            // For discrete hourly steps we set exactly 2700 at hour==20.
            if (hour_of_day >= 20) color_temp = 2700.0;
        }

        // Если в 00:00, то reset уже выполнен в начале итерации
        if (hour_of_day == 0) {
            // color_temp уже 5000
        }

        // Если свет внутри включён, показываем текущую цветовую температуру
        if (switches_state & LIGHTS_INSIDE) {
            // Округлим до целого K для удобства вывода
            int ctemp_int = static_cast<int>(std::round(color_temp));
            std::cout << "Color temperature: " << ctemp_int << "K" << std::endl;
        }

        // Продолжаем к следующему часу
    }

    std::cout << "Симуляция завершена (48 часов)." << std::endl;
    return 0;
}
