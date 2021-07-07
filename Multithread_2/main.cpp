#include <QCoreApplication>
#include "algs.cpp"

/*
Многопоточное программирование (thread)

есть процесс. В процессе может быть от 1 потока и больше
ПРОЦЕССЫ ПО СУТИ МЕЖДУ СОБОЙ НЕЗАВИСИМЫ

printf позволит оставить напечатанные в консоли строки нетронутыми,
то есть защищенными от вмещательства парралельной работой потоков!!!

std::ref - нужен для того,чтобы можно было работать со значениями в отдтеельном потоке по ссылке

о защите разделяемых данных и синхронизация потоков.
mutex - это такой некий сигнал, который говорит всем потокам что ресурс занят и его трогать нельзя
если мьютекс не освобождать это может привести к бесконечному ожиданию потоков

lock_guard - это класс, задачей которого является
захватить mutex в конструкторе и освободить его в деструкторе

deadlock или взаимная блокировка - когда каждому из двух или более потоков требуется доступ
к дввум или более ресурсам
и они начинают брать их непоследовательно без ожидания, чем блокируют друг другу последовательности исполнения алгоритмов

recursive_mutex или рекурсивная блокировка,
используется когда нам по какойто причине
вдруг стало нужно несколько раз произвести
захват одного и того же мьютекса

ВАЖНО: сколько раз был захвачен рекурсивный мьютекс,
столько же он и должен был быть раз освобожден

unique_lock похож на lock_guard. Только у него еще существуют методы lock и unlock,
позволяющий обойтий без скобок области видимости {}
Также у него можно блокировать lock в конструкторе
*/

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    float a=5.0;
    int result,result2;
    MyThreadClass m;

    printf("\nSTART");

    //thread main(infiniteCycle);
    thread th(algs,5.0,5.0);
    thread th2(DoWork);
    thread th3(incrs,std::ref(a),50);
    thread th4([&result]() { result = backVar(100,100); }); // здесь описано как например с помощью лямбды вернуть результат функции
    thread th5([&]() { result2 = m.method3(2,5); });
    thread th6 (&MyThreadClass::method1,m);
    thread th7 (&MyThreadClass::method2,m,5555);

    th7.join();
    th6.join();
    th5.join(); printf("\nresult2=%d",result2);
    th4.join(); printf("\nresult=%d\n",result);
    th3.join(); printf("\na=%f",a);
    th2.join();
    th.join();
    //main.join();

    cout<<"\n";
    thread th14(RecurciveMutexExample,10);
    thread th15(RecurciveMutexExample,10);
    th14.join();
    th15.join();

    thread th16(UniqueLockExample,'^');
    th16.join();

    thread th8 (PrintBox,'@');
    thread th9 (PrintBox,'*');
    th9.join();
    th8.join();

    thread th10(PrintBox_2,'$');
    thread th11(PrintBox_2,'&');
    th10.join();
    th11.join();

    thread th12(DeadLockExample);
    thread th13(DeadLockExample2);
    th12.join();
    th13.join();

    printf("\nEND\n");

    return 0;
}
