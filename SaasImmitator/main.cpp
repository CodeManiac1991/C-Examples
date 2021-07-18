#include <QCoreApplication>
#include "saasimmitator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //saas example
    SaaSImmitator SSRV;
    SSRV.startServer();

    return a.exec();
}
