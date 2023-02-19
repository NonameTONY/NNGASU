#include <iostream>
#include <string>

using namespace std;

class Prog{
    private:
        int num; /* Кол-во видов продуктов в магазине */
        string name; /* Название продукта */
        int kolvo; /* Кол-во выбранного продукта */
        int price; /* Цена выбранного продукта */
    public:
        void getNum(int x){ num = x; }

        string *n = new string[num]; 
        int *k = new int[num];
        int *p = new int[num];

        void Zap(){
            for(int i = 0; i < num; i++){
                name = "";
                cin >> name;
                n[i] = name;
                cin >> kolvo;
                k[i] = kolvo;
                cin >> price;
                p[i] = price;
            }
        }

        void Print(){
            for(int i = 0; i < num; i++){
                cout << i+1 << ") " << *(n+i) << " " << *(p+i) << "руб " << *(k+i) << "шт\n";
            }
        }

        void Ch(int x, int y, int z){
            switch(x){
                case 1:
                    p[y-1] = z;
                case 2:
                    k[y-1] = z;
            }
        }

        void PP(int vib){
                int pp = p[vib-1];
                int kk = k[vib-1];
                int sum = pp*kk;

                cout << "Сумма всех выбранных товаров = " << sum << "руб\n";
        }

        void PB(){
            int pp;
            int kk;
            int sum = 0;

            for(int i = 0; i < num; i++){
                pp = p[i];
                kk = k[i];
                sum += pp*kk;
            }

            cout << "Сумма всех товаров на базе = " << sum << "руб\n";
        }
};

int main(){
    Prog p;
    int v;
    int x, a, b, c;

    while(true){
        cout << "Выберете команду:\n\n1 - Заполнение базы\n2 - Вывод базы\n3 - Изменить цену или кол-во выбранного товара\n4 - Сумма всех выбранных товаров\n5 - Сумма всех товаров на базе\n\n";
        cin >> v;

        if (v == 1){
            system("clear");
            cout << "Введите кол-во видов продуктов: ";
            cin >> x;
            p.getNum(x);
            p.Zap();
            system("clear");
        } else if (v == 2){
            system("clear");
            p.Print();
            cout << endl;
        } else if (v == 3){
            system("clear");
            p.Print();
            cout << "\nВыберете товар: ";
            cin >> a;
            cout << "\nЧто вы хотите изменить:\n1 - Цену\n2 - Кол-во\n\n";
            cin >> b;
            cout << "\nВведите нужное значение: ";
            cin >> c;
            p.Ch(b, a, c);
            system("clear");
        } else if (v == 4){
            system("clear");
            p.Print();
            cout << "\nВыберете товар: ";
            cin >> x;
            p.PP(x);
            cout << endl;
        } else if (v == 5){
            system("clear");
            p.PB();
            cout << endl;
        }
    }

    return 0;
}
