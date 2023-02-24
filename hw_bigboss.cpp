#include <iostream>
#include <string>

using namespace std;

class Worker{
    private:
        int zp; /* Зарплата */
    public:
        /* Конструктор */
        Worker(int zp){
            this->zp = zp;
        }
        /* Выводим зарплату */
        int getZp(){
            return zp;
        }
};

class BigBoss: public Worker{
    private:
        int royalty; /* Доп оплата босса */
        int zpbb; /* Зарпалата босса */
    public:
        /* Конструктор */
        BigBoss(int zp, int royalty, int zpbb): Worker(zp){
            this->royalty = royalty;
            this->zpbb = zpbb;
        }
        /* Счёт зарплаты */
        void setZpBB(){
            zpbb += royalty;
        }
        /* Вывод зарплаты */
        int getZpBB(){
            return zpbb;
        }
};

int main(){
    system("clear");

    int a, b;

    cout << "Введите обычную зарплату: ";
    cin >> a;
    Worker w(a);

    cout << "Введите доп плату босса: ";
    cin >> b;
    BigBoss bb(a, b, a);

    bb.setZpBB();

    cout << endl << "Зарплата обычного работника: " << w.getZp();
    cout << endl << "Зарпалата босса: " << bb.getZpBB();

    return 0;
}
