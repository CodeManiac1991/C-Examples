#include <QCoreApplication>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	// Пример бесконечного цикла
	cout << "Ahha";
	while (true) {
	      Sleep(50);
		cout << " ha";
	}
	
	return a.exec();
}