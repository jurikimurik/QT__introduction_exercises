#ifndef CONTACTFACTORY_H
#define CONTACTFACTORY_H

#include "contact.h"
#include <QString>
#include <fstream>
#include <vector>
#include <random>

class ContactFactory
{
private:
    std::ifstream plik;
    std::vector<std::string> categories, firstNames, secondNames,
        streetAdresses, zipCodes, cities, phones;

    std::vector<std::vector<std::string>*> wskazniki = {&categories, &firstNames, &secondNames, &streetAdresses,
                                          &zipCodes, &cities, &phones};
public:
    ContactFactory(std::string nazwaPliku);

    Contact getRandomContact() const;

    void showDatabase() const;
};

#endif // CONTACTFACTORY_H
