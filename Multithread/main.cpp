#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>

using std::cout;

void process(int a)
{
    cout<<"Thread "<<std::this_thread::get_id()<<","; // получаем id потока
    for (int i = 0; i < 10000; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(800));
        a = rand();
        cout<<a<<"0 ";
    }
    cout<<"\n";
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    //Создаем поток выполняющий функцию process и передаем в нее параметр var
    srand(time(NULL));
    int var = 0;

    std::thread simple_thread(process, std::ref(var));

    cout<<"Thread "<<std::this_thread::get_id()<<", "; // получаем id потока
    for (int i = 0; i < 10000; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(800));
        cout<<"1";
    }
    cout<<"\n";

    if(simple_thread.joinable()){
        /*
            после включения detach - поток отсоединяется от главного потока
            и контроллировать его больше нельзя, поэтому использование join после detach бессмысленно
            и вызовет ошибку
        */
    //simple_thread.detach(); // завершит исполнение всех потоков после отработки main
    simple_thread.join(); // после завершения main дождется завершения остальных потоков
    }

    return 0;
}
