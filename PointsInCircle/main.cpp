#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QTextStream>

using namespace std;

struct Point{
    float x;
    float y;
    //float r;
};

QString printQuad(Point Arr[4]);
QString printQuad(Point Arr[4])
{
    QString qsTemp;
    Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
        curPoint = Arr[i];
        qsTemp=qsTemp.arg(curPoint.x).arg(curPoint.y)/*.arg(curPoint.r)*/;
    }
}

int main(/*int argc, char *argv[]*/)
{   
    QString message;
    QString qsFileName = "PointsInCircle.txt";
    qsFileName = "PointsInCircle.txt";
    QFile file(qsFileName);
    if (!file.exists()){
        message = "Can't find file %1 to read\n";
        message = message.arg(qsFileName);
        qDebug() << message;
        return -1;
    }

      if(!file.open(QFile::ReadOnly | QFile::Text))  {
          message = "Can't open the file %1 for reading\n";
          message = message.arg(qsFileName);
          qDebug() << message;
          return -1;
  }
    Point quadOne[100];
    char buf[4096];
    int readCount;
    QString qsBuf;
    QStringList qslPoint;
    float X,Y,R;
    int i=0;
    QCoreApplication a(/*argc, argv*/);
    qDebug() << "-Test: Points in circle-";
    qDebug() << " ";
    qDebug() << "Circle Points: ";
    qDebug() << " ";

    readCount = file.readLine(buf, sizeof(buf));
    buf[readCount-1] = 0;
    qsBuf = buf;
    qslPoint = qsBuf.split(' ');
    cout << " X: " << qPrintable(qslPoint[0]);
    cout << " Y: " << qPrintable(qslPoint[1]);
    cout << " R: " << qPrintable(qslPoint[2])<< endl;
    qDebug() << " ";
    qDebug() << "All Points: ";
    qDebug() << " ";
    while (!file.atEnd()){
        readCount = file.readLine(buf, sizeof(buf));
        buf[readCount-1] = 0;
        qsBuf = buf;
        qslPoint = qsBuf.split(';');
        cout << " X: " << qPrintable(qslPoint[0]);
        cout << " Y: " << qPrintable(qslPoint[1])<< endl;
        //float X1 = qslPoint[0];
        //float Y1 = qslPoint[1];
        //R=20.0;
        quadOne[i].x=X;
        quadOne[i].y=Y;

        //NEZAKON4ENNOE: NAXOZHDENIE PODXODJAZHEI TO4KI
        /*
        float FD;
        FD = sqrt((12.0 - X1)^2 + (10.0 - Y1)^2);

        if (FD<=R)
        {
           //To4ka zapisqvaetsja v fail
           //d = sqrt( (xc - x)^2 + (yc - y)^2 )

           //float FD = sqrt((12.0 - Point[0])^2 + (10.0 - Point[1])^2);
           //cout << " FD: "<< FD << endl; //Dlja proverki
        }
        else
        {
           //To4ka ne zapisqvaetsja v fail
            break;
        */
        i++;
        }

    qDebug() << " ";
    qDebug() << "Points in Circle: ";
    qDebug() << " ";

    return(0);
}

//NEZAKON4ENNOE: ZAPISJ V FAIL TO4EK VNUTRI KRUGA
/* QString filename = "OutputPointsInCircle.txt";
 QFile outputfile(filename);
 if (outputfile.open(QIODevice::ReadWrite)) {
     QTextStream stream(&file);
     stream << "Points in Circle:  " << endl;
     file.close();
 } */
