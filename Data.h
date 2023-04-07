
#ifndef DATA_H
#define DATA_H
#include <QString>

class Data {
public:
    Data(QString, QString, int);

    QString firstName;
    QString lastName;
    int age;
};

Data generateRandomData();

#endif // DATA_H
