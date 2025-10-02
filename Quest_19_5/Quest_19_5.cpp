#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>
#include <windows.h> // для SetConsoleOutputCP

class WhatWhereWhen {
private:
    std::vector<bool> playedSectors; // Отслеживание сыгравших секторов
    int currentSector; // Текущий сектор (0-12)
    int playerScore; // Счет игрока
    int viewersScore; // Счет телезрителей
    bool gameOver; // Флаг окончания игры
    std::string basePath; // Базовый путь к файлам

public:
    WhatWhereWhen() {
        // Настройка консоли для русского языка
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        std::locale::global(std::locale("rus_rus.1251"));

        playedSectors = std::vector<bool>(13, false);
        currentSector = 0;
        playerScore = 0;
        viewersScore = 0;
        gameOver = false;
        basePath = "C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Faile\\";
    }

    // Вращение волчка (выбор сектора)
    void spinWheel(int offset) {
        // Вычисляем новый сектор
        int newSector = (currentSector + offset) % 13;
        if (newSector < 0) newSector += 13;

        // Ищем следующий неигравший сектор
        int attempts = 0;
        while (playedSectors[newSector] && attempts < 13) {
            newSector = (newSector + 1) % 13;
            attempts++;
        }

        // Если все секторы сыграли, игра заканчивается
        if (playedSectors[newSector]) {
            std::cout << "Все секторы уже сыграли! Игра завершена.\n";
            gameOver = true;
            return;
        }

        currentSector = newSector;
        playedSectors[currentSector] = true;

        std::cout << "Выпал сектор: " << (currentSector + 1) << "\n";
    }

    // Чтение вопроса из файла
    std::string readQuestion() {
        std::string questionFilename = basePath + "q" + std::to_string(currentSector + 1) + ".txt";

        // Открываем файл в правильной кодировке
        std::ifstream questionFile(questionFilename, std::ios::binary);

        if (!questionFile.is_open()) {
            return "Не удалось загрузить вопрос для сектора " + std::to_string(currentSector + 1);
        }

        // Читаем файл как бинарный и конвертируем в UTF-8
        std::string question;
        std::string line;
        while (std::getline(questionFile, line)) {
            question += line + "\n";
        }

        questionFile.close();
        return question;
    }

    // Чтение ответа из файла
    std::string readAnswer() {
        std::string answerFilename = basePath + "a" + std::to_string(currentSector + 1) + ".txt";

        // Открываем файл в правильной кодировке
        std::ifstream answerFile(answerFilename, std::ios::binary);

        if (!answerFile.is_open()) {
            return "ERROR"; // Если файл не открылся
        }

        std::string answer;
        std::getline(answerFile, answer);

        answerFile.close();
        return answer;
    }

    // Проверка существования файла
    bool fileExists(const std::string& filename) {
        std::ifstream file(filename);
        return file.good();
    }

    // Проверка ответа игрока
    void checkAnswer(const std::string& playerAnswer) {
        std::string correctAnswer = readAnswer();

        if (correctAnswer == "ERROR") {
            std::cout << "Ошибка загрузки ответа! Балл получают телезрители.\n";
            viewersScore++;
            return;
        }

        // Приводим оба ответа к нижнему регистру для сравнения
        std::string playerAnswerLower = toLower(playerAnswer);
        std::string correctAnswerLower = toLower(correctAnswer);

        if (playerAnswerLower == correctAnswerLower) {
            playerScore++;
            std::cout << "Правильно! Вы заработали 1 балл.\n";
        }
        else {
            viewersScore++;
            std::cout << "Неправильно! Балл получают телезрители.\n";
            std::cout << "Правильный ответ: " << correctAnswer << "\n";
        }

        // Проверяем условия победы
        if (playerScore >= 6) {
            std::cout << "\n*** ПОБЕДА ИГРОКА! ***\n";
            gameOver = true;
        }
        else if (viewersScore >= 6) {
            std::cout << "\n*** ПОБЕДА ТЕЛЕЗРИТЕЛЕЙ! ***\n";
            gameOver = true;
        }
    }

    // Вспомогательная функция для приведения к нижнему регистру (только для английских букв)
    std::string toLower(const std::string& str) {
        std::string result = str;
        for (char& c : result) {
            // Преобразуем только английские буквы
            if (c >= 'A' && c <= 'Z') {
                c = std::tolower(c);
            }
        }
        return result;
    }

    // Проверка существования файлов
    bool checkFilesExist() {
        bool allFilesExist = true;
        for (int i = 1; i <= 13; i++) {
            std::string questionFile = basePath + "q" + std::to_string(i) + ".txt";
            std::string answerFile = basePath + "a" + std::to_string(i) + ".txt";

            if (!fileExists(questionFile)) {
                std::cout << "Ошибка: отсутствует файл вопроса " << questionFile << "\n";
                allFilesExist = false;
            }
            if (!fileExists(answerFile)) {
                std::cout << "Ошибка: отсутствует файл ответа " << answerFile << "\n";
                allFilesExist = false;
            }
        }

        if (allFilesExist) {
            std::cout << "Все файлы вопросов и ответов найдены!\n";
        }
        return allFilesExist;
    }

    // Основной игровой цикл
    void playGame() {
        std::cout << "=== ДОБРО ПОЖАЛОВАТЬ В ИГРУ 'ЧТО? ГДЕ? КОГДА?' ===\n\n";

        // Проверяем существование файлов
        if (!checkFilesExist()) {
            std::cout << "Не все файлы вопросов и ответов найдены!\n";
            std::cout << "Убедитесь, что файлы называются: q1.txt, a1.txt, q2.txt, a2.txt, ... q13.txt, a13.txt\n";
            return;
        }

        while (!gameOver) {
            std::cout << "\n--- Текущий счет ---\n";
            std::cout << "Игрок: " << playerScore << " | Телезрители: " << viewersScore << "\n\n";

            // Вращение волчка
            int offset;
            std::cout << "Введите смещение для вращения волчка: ";
            std::cin >> offset;
            std::cin.ignore(); // Очищаем буфер

            spinWheel(offset);

            if (gameOver) break;

            // Чтение и вывод вопроса
            std::string question = readQuestion();
            std::cout << "\n--- ВОПРОС ---\n";
            std::cout << question << "\n";

            // Получение ответа от игрока
            std::string playerAnswer;
            std::cout << "Ваш ответ: ";
            std::getline(std::cin, playerAnswer);

            // Проверка ответа
            checkAnswer(playerAnswer);
        }

        // Финальные результаты
        std::cout << "\n=== ИГРА ОКОНЧЕНА ===\n";
        std::cout << "Финальный счет:\n";
        std::cout << "Игрок: " << playerScore << " | Телезрители: " << viewersScore << "\n";

        if (playerScore > viewersScore) {
            std::cout << "ПОБЕДИЛ ИГРОК! ПОЗДРАВЛЯЕМ!\n";
        }
        else {
            std::cout << "ПОБЕДИЛИ ТЕЛЕЗРИТЕЛИ!\n";
        }
    }
};

int main() {
    WhatWhereWhen game;
    game.playGame();
    return 0;
}