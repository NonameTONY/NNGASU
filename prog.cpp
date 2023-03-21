#include <iostream>
#include <string>
using namespace std;

class Binary {
private:
    string secret;
public:
    Binary(string s) {
        secret = s;
    }
    friend void display(Binary b);
};

void display(Binary b) {
    cout << "Двоичный код: ";
    for (int i = 0; i < b.secret.length(); i++) {
        cout << bitset<8>(b.secret[i]).to_string();
    }
    cout << endl;
}

int main() {
    string x;
    cout << "Введите слово: ";
    getline(cin, x);
    Binary b(x);
    display(b);
    return 0;
}
