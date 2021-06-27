#include <QCoreApplication>
#include <iostream>

using namespace std;

///Шаблон функции ввода массива с разными типами и его отображения
template <typename T>
void getArray(const T * array, int count){
    /// Отображаем
    cout << "Massive:";
    for (int data=0; data<count; data++) cout<<"  "<< array[data];
    cout << endl;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    // определим размер массивов и элементы
    const int iSize = 6;
    int   iArr[iSize] = {1,2,3,4,5,6};
    float fArr[iSize] = {1.1,2.2,3.3,4.4,5.5,6.6};
    char cArr[iSize] = {'A','B','C','D','E','F'};


    // вызываем шаблонную функцию
    getArray(iArr, iSize);
    getArray(fArr, iSize);
    getArray(cArr, iSize);

    return 0;
}
