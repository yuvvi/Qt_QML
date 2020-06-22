#include <QCoreApplication>
#include <QDebug>

/*Outside variables are not allowed to access in default lambda '[]'*/
void lambda_default(){//[]
    qDebug()<<"------------Default lambda []--------------"<<endl;
    qDebug()<<"---------[](int *a,int *b)"<<endl;
    int x =0, y=0;
    qDebug()<<"Before lambda #x:"<<x<<" #y :"<<y<<endl;
    auto foo= [](int *a,int *b)mutable{++(*a);++(*b);
                    qDebug()<<"In lambda #x:"<<*a<<" #y :"<<*b<<endl;
                    };
    foo(&x,&y);
    qDebug()<<"After lambda #x:"<<x<<" #y :"<<y<<endl<<endl;
    qDebug()<<"---------[](int a,int b)"<<endl;
    qDebug()<<"Before lambda #x:"<<x<<" #y :"<<y<<endl;
    auto foo2= [](int a,int b)mutable{++a;++b;
                    qDebug()<<"In lambda #x:"<<a<<" #y :"<<b<<endl;
                    };
    foo2(x,y);
    qDebug()<<"After lambda #x:"<<x<<" #y :"<<y<<endl;

}

void lambda_callByValue(){//[=]
    qDebug()<<"------------lambda: call by value [=]--------------"<<endl;
    int x =0, y=0;
    qDebug()<<"Before lambda #x:"<<x<<" #y :"<<y<<endl;
    auto foo= [=]()mutable{++x;++y;
                    qDebug()<<"In lambda #x:"<<x<<" #y :"<<y<<endl;
                    };
    foo();
    qDebug()<<"After lambda #x:"<<x<<" #y :"<<y<<endl;

}

void lambda_callByRef(){//[&]
    qDebug()<<"------------lambda: call by ref [&]--------------"<<endl;
    int x =0, y=0;
    qDebug()<<"Before lambda #x:"<<x<<" #y :"<<y<<endl;
    auto foo= [&]()mutable{++x;++y;
                    qDebug()<<"In lambda #x:"<<x<<" #y :"<<y<<endl;
                    };
    foo();
    qDebug()<<"After lambda #x:"<<x<<" #y :"<<y<<endl;

}

void lambda_callByRef_val(){//[x,&y]
    qDebug()<<"------------lambda: call by val & ref [x,&y]--------------"<<endl;
    int x =0, y=0;
    qDebug()<<"Before lambda #x:"<<x<<" #y :"<<y<<endl;
    auto foo= [x,&y]()mutable{++x;++y;
                    qDebug()<<"In lambda #x:"<<x<<" #y :"<<y<<endl;
                    };
    foo();
    qDebug()<<"After lambda #x:"<<x<<" #y :"<<y<<endl;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    lambda_default();
    lambda_callByValue();
    lambda_callByRef();
    lambda_callByRef_val();

    return a.exec();
}
