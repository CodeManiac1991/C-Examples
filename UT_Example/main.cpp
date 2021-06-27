#include <QCoreApplication>
#include <iostream>
#include <cassert>
#include <math.h>

using namespace std;

class Calculator {
public:
    int Divide(int a, int b)  {

        int result = 0;
        if (b!=0){
            result = a/b;
        }else {
            return 0;/// Спокойно возвращаем 0, так как при любом раскладе деления a/b число будет >=1
        }
        return result;
    }
};

class UnitTest
{
private:
    Calculator *calc;

public:
    UnitTest(){
      calc = new Calculator();
    }

    ~UnitTest(){
      delete calc;
    }

    void OneDividedByOne() {
        assert(calc->Divide(1, 1) == 1);
        cout << "OneDividedByOne - Good!\n";
    }

    void TwoDividedByOne() {
        assert(calc->Divide(2, 1) == 2);
        cout << "TwoDividedByOne - Good!\n";
    }

    void OneDividedByZero() {
        assert(calc->Divide(1, 0) == 0);
        cout << "OneDividedByZero - Good!\n";
    }
};

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    UnitTest *UT = new UnitTest();
    UT->OneDividedByOne();
    UT->TwoDividedByOne();
    UT->OneDividedByZero();
    delete UT;

    return 0;
}
