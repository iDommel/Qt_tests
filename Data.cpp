#include <cstdlib>
#include <ctime>
#include <string>
#include "data.h"

Data::Data(QString firstname, QString lastname, int age)
    : firstName(firstname), lastName(lastname), age(age)
{
}

Data generateRandomData()
{
    static const char* const FIRSTNAMES[] = { "Alice", "Bob", "Charlie", "David", "Eve" };
    static const char* const LASTNAMES[] = { "Smith", "Johnson", "Williams", "Jones", "Brown" };
    static const int MIN_AGE = 18;
    static const int MAX_AGE = 99;

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Generate random values for the data fields
    QString firstname = FIRSTNAMES[std::rand() % 5];
    QString lastname = LASTNAMES[std::rand() % 5];
    int age = std::rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;

    // Create a Data object with the random values
    return Data(firstname, lastname, age);
}
