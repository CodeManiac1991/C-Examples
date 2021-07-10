#include <QCoreApplication>
#include "cnstrs.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Example_1 e1 {2,3}; //ПРИМЕР СПИСКА ИНИЦИАЛИЗАЦИИ

    //КОНСТРУКТОР КОПИРОВАНИЯ
    Example_3 e3(0,0);
    Example_3 e3_1(e3);

    Entity ent("Hello move!");
    ent.PrintName();

    return a.exec();
}
