#include <iostream>
#include <stdio.h>
#include <mutex>
#include <thread> // нужен для работы с потоками
#include <chrono> // нужен для работы со временем

using namespace std;
mutex mtx,mtx2;
recursive_mutex rmtx;

void DoWork(){
        for (size_t i=0;i<10 ;i++ ) {
            printf("\ndowork\tID thread = %d",std::this_thread::get_id());
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
}

void algs(float a, float b){
        printf("\na+b = %f", a+b);
        this_thread::sleep_for(chrono::milliseconds(1000));
        printf("\na-b = %f", a-b);
        this_thread::sleep_for(chrono::milliseconds(1000));
        printf("\na*b = %f", a*b);
        this_thread::sleep_for(chrono::milliseconds(1000));
        printf("\na/b = %f", a/b);
        this_thread::sleep_for(chrono::milliseconds(1000));
}

///программа с возвратом по ссылке
void incrs(float &c, int count){
        for (int i = 0; i < count; ++i) {
            c++;
        }
}

void infiniteCycle(){
        for (size_t i=0; true; i++) {
            printf("\ninfinite work");
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
}

int backVar(int a, int b){
    return a+b;
}

class MyThreadClass
{
public:
    void method1(){
            this_thread::sleep_for(chrono::milliseconds(7000));
            printf("\nMethod 1");
    };

    void method2(int a){
            this_thread::sleep_for(chrono::milliseconds(7000));
            printf("\nMethod 2: %d\n",a);
    };

    int method3(int a, int b){
            this_thread::sleep_for(chrono::milliseconds(7000));
            printf("\nMethod 3");
        return a+b;
    }

};

void PrintBox(char ch){
    mtx.lock();
    cout<<"\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout<<endl;
    }
    cout<<endl;
    mtx.unlock();
}

void PrintBox_2(char ch){

    {
    lock_guard<mutex> guard(mtx); // освобождение мьютекса произойдет после выхода из области видимости

    cout<<"\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout<<endl;
    }
    cout<<endl;
    } // скобочками можно ограничивать область видимости

}

void DeadLockExample(){
    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(1)); //очень важна, очасти является причиной блокировки
    mtx.lock();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<"-";
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout<<endl;
    }
    cout<<endl;

    mtx.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
    mtx2.unlock();
}

void DeadLockExample2(){
    mtx.lock();
    this_thread::sleep_for(chrono::milliseconds(1)); //это связано с скоростью создания потоков в определенной последовательности
    mtx2.lock();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<"=";
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout<<endl;
    }
    cout<<endl;

    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
    mtx.unlock();
}

void RecurciveMutexExample(int a){
    rmtx.lock();
    cout<<a<<" ";
    this_thread::sleep_for(chrono::milliseconds(300));
    if(a<=1){
        cout<<endl;
        rmtx.unlock();
        return;
    }

    a--;
    RecurciveMutexExample(a);
    rmtx.unlock();
}


void UniqueLockExample(char ch)
{
    unique_lock<mutex> ul(mtx, std::defer_lock);

    this_thread::sleep_for(chrono::milliseconds(2000));

    ul.lock();

    cout<<"\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout<<endl;
    }
    cout<<endl;

    ul.unlock();

    this_thread::sleep_for(chrono::milliseconds(2000));
}
