#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Input vector size: ";
    cin >> n;

    vector<int> v(n);
    cout << "Input numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int x;
    cout << "Input number to delete: ";
    cin >> x;

    int write = 0;
    for (int read = 0; read < v.size(); ++read) {
        if (v[read] != x) {
            v[write] = v[read];
            write++;
        }
    }

    // удаляем «хвост» с помощью pop_back()
    while (v.size() > write) {
        v.pop_back();
    }

    cout << "Result: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
