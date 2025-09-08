#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Допустимые символы для local-part
const string allowed_local = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_`{|}~.-";
// Допустимые символы для domain-part
const string allowed_domain = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";

// Проверка допустимости символа в local-part
bool is_valid_local_char(char c) {
    return allowed_local.find(c) != string::npos;
}

// Проверка допустимости символа в domain-part
bool is_valid_domain_char(char c) {
    return allowed_domain.find(c) != string::npos;
}

// Проверка local-part
bool check_local(const string& local) {
    if (local.empty() || local.size() > 64) return false;
    if (local.front() == '.' || local.back() == '.') return false;
    for (size_t i = 0; i < local.size(); ++i) {
        if (!is_valid_local_char(local[i])) return false;
        if (i > 0 && local[i] == '.' && local[i - 1] == '.') return false;
    }
    return true;
}

// Проверка domain-part
bool check_domain(const string& domain) {
    if (domain.empty() || domain.size() > 63) return false;
    if (domain.front() == '.' || domain.back() == '.') return false;
    for (size_t i = 0; i < domain.size(); ++i) {
        if (!is_valid_domain_char(domain[i])) return false;
        if (i > 0 && domain[i] == '.' && domain[i - 1] == '.') return false;
        if (domain[i] == '_') return false; // _ запрещён
    }
    return true;
}

// Основная функция проверки email
bool is_valid_email(const string& email) {
    size_t at_pos = email.find('@');
    if (at_pos == string::npos) return false;
    if (email.find('@', at_pos + 1) != string::npos) return false; // только один @

    string local = email.substr(0, at_pos);
    string domain = email.substr(at_pos + 1);

    return check_local(local) && check_domain(domain);
}

int main() {
    string email;
    cin >> email;
    cout << (is_valid_email(email) ? "Yes" : "No") << endl;
    return 0;
}