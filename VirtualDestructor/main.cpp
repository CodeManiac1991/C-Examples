#include <QCoreApplication>
#include <iostream>
#include <QTextCodec>

/*
    для того чтобы написать правильный пример виртуального деструктора,
    стоит обратить внимание на то, что следует наследоваться от публичного класса родителя,
    ну и разумеется про слово virtual у родителя также не следует забывать
*/

using std::cout;

class Parent{
public:
    Parent(){
      cout<<"Parent constructor\n";
    }
    virtual ~Parent(){
      cout<<"Parent destructor\n";
    }
};

class Children : public Parent
{
public:
    Children(){
        cout<<"Children constructor\n";
    }
    ~Children(){
        cout<<"Children destructor\n";
    }
};

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    /// Раскомментируйте подходящие для себя варианты для тестов
    //Children* ch = new Children;

    Parent* ch = new Children; // если убрать слово virtual может произойти проблема с памятью(возможно утечка или что-то в этом роде)
    //P.S. то есть в случае выше деструктор ребенка не отработает

    /*
    Также стоит обратить внимание, что ребенок как бы может быть внутри родителя,
    и соответственно по логике не может быть наоборот, тоесть апкаст не произойдет
    когда мы попытаемся сделать родителя в ребенке. Попробуйте в примере ниже:
    */
    //Children* ch = new Parent;
    delete  ch;

    return 0;
}
