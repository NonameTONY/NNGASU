#include <iostream>
#include <string>

using namespace std;

class Dog {
    private:
        string size; /* Выбранный размер */
        string color; /* Цвет */
    public:
        /* Задаём и выводим размер */
        void setSize(string s){
            size = s;
        }
        string getSize(){
            return size;
        }
        /* Задаём и выводим цвет */
        void setColor(string s){
            color = s;
        }
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
        /* Задаём и выводим имя */
        void setName(string s){
            name = s;
        }
        string getName(){
            return name;
        }
        /* Задаём и выводим телефон владельца */
        void setPhone(string s){
            phone = s;
        }
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
    Dog dog;
    PetDog pet;

    string a, b, c, d;

    cout << "Введите размер собаки: ";
    cin >> a;
    dog.setSize(a);

    cout << "Введите цвет собаки: ";
    cin >> b;
    dog.setColor(b);

    cout << "Введите кличку собаки: ";
    cin >> c;
    pet.setName(c);

    cout << "Введите телефон его/её владельца: ";
    cin >> d;
    pet.setPhone(d);

    cout << endl;
    pet.Info();

    return 0;
}