#include <QCoreApplication>
#include <iostream>
#include "uniqueptr.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // без умного указателя
    int *ptr = new int(5);
    cout << *ptr << endl;
    delete ptr;

    //заворачиваем ptr2 в умный указатель и проверяем действительно ли он уничтожился
    int *ptr2 = new int(6);
    cout << *ptr2 << endl;

    SmartPointer<int>* SP = new SmartPointer<int>(ptr2);
    delete SP;

    cout << *ptr2 << endl;

    return a.exec();
}
