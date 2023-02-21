#include <iostream>
#include <string>

using namespace std;

class Dog {
    private:
        string size; /* Выбранный размер */
        string color; /* Цвет */
    public:
        /* Создаём конструктор */
        Dog(string size, string color){
            this-> size = size;
            this-> color = color;
        }
        /* Выводим размер */
        string getSize(){
            return size;
        }
        /* Задаём и выводим цвет */
        string getColor(){
            return color;
        }
        /* Ходит */
        void Walk(){
            cout << "Собака ходит";
        }
        /* Ест */
        void Eat(){
            cout << "Собака любит кушать";
        }
};

class PetDog: public Dog {
    private:
        string name;
        string phone;
    public:
        /* Создаём конструктор */
        PetDog(string size, string color, string name, string phone): Dog(size, color){
            this-> name = name;
            this-> phone = phone;
        }
        /* Выводим имя */
        string getName(){
            return name;
        }
        /* Выводим телефон владельца */
        string getPhone(){
            return phone;
        }
        /* Инфо */
        void Info(){
            cout << "Кличка - " << getName() << endl << "Телефон владельца - " << getPhone();
        }
};

int main() {
    system("clear");

    string a, b, c, d;

    cout << "Введите размер собаки: ";
    cin >> a;

    cout << "Введите цвет собаки: ";
    cin >> b;

    Dog dog(a, b);

    cout << "Введите кличку собаки: ";
    cin >> c;

    cout << "Введите телефон его/её владельца: ";
    cin >> d;

    PetDog pet(a, b, c, d);

    cout << endl;
    pet.Info();

    return 0;
}
