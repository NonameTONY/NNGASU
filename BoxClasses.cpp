#include <iostream>
using namespace std;

class Box {
public:
    float length, width, height;
    Box(){ // конструктор по умолчанию
        length = 0;
        width = 0;
        height = 0;
    }
    Box(float l, float w, float h){ // конструктор с параметрами
        length = l;
        width = w;
        height = h;
    }
    void setDimensions(float l, float w, float h){ // метод для задания размеров коробки
        length = l;
        width = w;
        height = h;
    }
    float getVolume(){ // метод для вычисления объема коробки
        return length * width * height;
    }
    bool operator>(Box b){ // перегрузка оператора ">"
        if(length > b.length && width > b.width && height > b.height)
            return true;
        else
            return false;
    }
    float getArea(){ // метод для вычисления площади обычной коробки
        return 2 * (length * width + length * height + width * height);
    }
};

class

FlatBox : public Box { // класс сплющенной коробки, наследуется от класса Box
public:
    FlatBox() : Box(){ // конструктор по умолчанию
        setDimensions(0, 0, 0);
    }
    FlatBox(float l, float w) : Box(l, w, 0){ // конструктор с параметрами
    }
    float getArea(){ // перегрузка метода для вычисления площади сплющенной коробки
        return length * width;
    }
};

int main(){
    int n;
    cout << "Enter the number of boxes: ";
    cin >> n;
    Box* boxes = new Box[n]; // создание динамического массива коробок
    for(int i=0; i<n; i++){
        float l, w, h;
        cout << "Enter the dimensions of box " << i+1 << ": ";
        cin >> l >> w >> h;
        boxes[i].setDimensions(l, w, h);
    }
    Box maxBox;
    for(int i=0; i<n; i++){
        if(boxes

[i] > maxBox)
            maxBox = boxes[i];
    }
    cout << "The largest box is: " << maxBox.getVolume() << endl;

    float totalArea = 0;
    float flatArea = 0;
    for(int i=0; i<n; i++){
        totalArea += boxes[i].getArea();
        if(boxes[i].getVolume() == 0){ // если коробка сплющена
            FlatBox flatBox(boxes[i].length, boxes[i].width); // создание объекта сплющенной коробки
            flatArea += flatBox.getArea();
        }
    }
    cout << "The total area of all boxes is: " << totalArea << endl;
    cout << "The area of all flat boxes is: " << flatArea << endl;

    delete[] boxes; // освобождение памяти, занятой массивом коробок
    return 0;
}