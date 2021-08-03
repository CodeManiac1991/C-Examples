#include <QCoreApplication>
#include <QString>
#include <thread>
#include <QDebug>
#include <iostream>
using namespace std;

/*
В данном примере мы заполняем массив миллионом элементов
(возрастами людей) с помощью многопоточности

Далее создаем массив из 130 элементов и
считаем количество значений для каждого возраста
*/

int allAge[1000000];
int countHumans[130];

void createCountHumans(){
    for (int i = 1; i <= 130; ++i) {
        countHumans[i]=0;
    }
}

void getCountHumans(){
    int sum = 0;
    for (int i = 1; i <= 130; ++i) {
        qDebug()<<i<<": "<<countHumans[i];
        sum+=countHumans[i];
    }
    qDebug()<<"Number of people counted:"<< sum;
}

void ThreadHuman(int firstValue, int secondValue, int numberThread)
{
        int ageHuman[secondValue - firstValue];
        srand(time(0));

        for (int i = firstValue; i < secondValue; ++i) {
            ageHuman[i] = 1 + rand() % 130;
            countHumans[ageHuman[i]]+=1;

            if (numberThread == 1){
                //allAge[i] = ageHuman[i];
                QString str = QString::number(i) + ": " + QString::number(ageHuman[i]) + "  Thread: " + QString::number(numberThread);
                cout<<str.toStdString()<<endl;
            }else{
                //allAge[secondValue*(numberThread-1)+i] = ageHuman[i];
                QString str = QString::number(secondValue*(numberThread-1)+i) + ": " + QString::number(ageHuman[i]) + "  Thread: " + QString::number(numberThread);
                cout<<str.toStdString()<<endl;
            }
        }
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    createCountHumans();
        int numPack = 0, countPack = 0;
            while(countPack<10)
            {
                numPack+=1;
                thread TH1(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH2(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH3(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH4(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH5(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH6(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH7(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH8(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH9(ThreadHuman,  0,10000,numPack); numPack+=1;
                thread TH10(ThreadHuman, 0,10000,numPack);

                TH10.join();
                TH9.join();
                TH8.join();
                TH7.join();
                TH6.join();
                TH5.join();
                TH4.join();
                TH3.join();
                TH2.join();
                TH1.join();
                countPack++;
            }
    getCountHumans();

    return 0;
}
