#include <iostream>
#include <QString>
using std::cout;

// Конструктор по умолчанию =========================================================================================
class Example_0
{
public:
    Example_0() {}
};

// Параметризированный конструктор =================================================================================
/*

    можно вызвать либо явно:
    Example_1 e1 = Example_1(0,0);

    либо неявно:
    Example_2 e2(0,0);

*/

class Example_1
 {
    int x,y;
public:
    Example_1(int a, int b) {
        x=a;
        y=b;
    }
};

// Инициализирующий конструктор ====================================================================================
/*
 * это конструктор, который вызывается с одним или несколькими параметрами,
 * при использовании которого происходит инициализация полей класса этими параметрами.
*/
class Example_2
{
    int x,y;
public:

    Example_2(int a=0, int b=0)
        :x(a)
        ,y(b)
    {}
    void set_x(int var){
        x = var;
    };
    void set_y(int var){
        y = var;
    };
};

// Конструктор преобразования
/*
    Это частный случай конструктора инициализации, в котором используется один параметр.
    Смысл конструктора преобразования я считаю в том, что допустим можно много раз перегрузить конструктор с 1-им параметром
    , что сделает класс адаптивным(конфигурирующимся), например доллары принимать не только во float принимать, но и в string
    к примеру. Тогда название  "преобразование" себя оправдывает и "инициализирующий" тоже.
*/
class Curency
{
    long Dollars;
    int Cents;
public:
    Curency(double DolAndCents) {
        Dollars = long(DolAndCents);
        Cents = int((DolAndCents - Dollars)*100+0.5);
    }
    long getDollars()
    {
        return Dollars;
    }
    int getCents()
    {
        return Cents;
    }
};

// Конструктор копирования =======================================================================================
class Example_3
{
    int x,y;
public:
    Example_3(int a, int b)
        :x(a)
        ,y(b)
    {
        cout<<"default constructor\n";
    }
    Example_3(const Example_3 & a )
        :x(a.x)
        ,y(a.y)
    {
        cout<<"copy constructor\n";
    }
    ~Example_3(){
        cout<<"destroy constructor\n";
    }
};


// Конструктор перемещения =======================================================================================

class UString
{
    char *m_Data;
    uint32_t m_Size;
public:
    UString() = default;
    UString(const char* text)
    {
        cout<<"UString Created\n";
        m_Size = strlen(text);
        m_Data = new char[m_Size];
        memcpy(m_Data, text, m_Size);
    }

    //Используем конструктор копирования
    UString(const UString& other)
    {
        cout<<"UString Copy\n";
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    //Используем конструктор перемещения как альтернативу конструктору копирования
    UString(UString&& other) noexcept
    {
        cout<<"UString Move\n";
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;

    }

    ~UString(){
        cout<<"UString destroyed\n";
        delete m_Data;
    }

    void Print(){
        for (uint32_t i = 0; i < m_Size; ++i) {
            cout<<m_Data[i];
        };
    }
};

class Entity
{
    UString m_Name;
public:
    Entity(const UString &name)
        :m_Name(name)
    {
        cout<<"Entity constructor\n";
    }

    // разблокируйте нужную инициализацию, чтобы выбрать требуемый конструктор
    Entity(UString &&name)
        :m_Name((UString&&)name)
        //:m_Name(name)
    {
        cout<<"Entity move constructor\n";
    }

    ~Entity(){
        cout<<"Entity destroy\n";
    }

    void PrintName(){
        m_Name.Print();
    }
};
