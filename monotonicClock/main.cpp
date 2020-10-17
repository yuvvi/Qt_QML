#include <QCoreApplication>
#include <time.h>
#include <QDebug>

void printAbstimeFromTime()
{
    struct timespec abstime;
    clock_gettime(CLOCK_REALTIME, &abstime);
    qDebug()<<"\nVKP::printAbstimeFromTime(end):sec "<<abstime.tv_sec<<" ,nanoSec "<<abstime.tv_nsec<<" ,milli "<<abstime.tv_nsec/1000<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printAbstimeFromTime();
    return a.exec();
}
