#include "countryprops.h"

CountryProps::CountryProps(QString name) : c_countryName(name)
{
    // For better visual style.
    using namespace std;

    //INSERTING DEFAULT VALUES
    insert(Type::Country, make_pair("Country", ".*"));
    insert(Type::Address, make_pair("Address", ".*"));
    insert(Type::City, make_pair("City", ".*"));
    insert(Type::Name, make_pair("Name", ".*"));
    insert(Type::Phone, make_pair("Phone", ".*"));
    insert(Type::State, make_pair("State", ".*"));
    insert(Type::Zip, make_pair("Zip", ".*"));
}

void CountryProps::set(Type type, QString labelName, QString regex)
{
    insert(type, std::make_pair(labelName, regex));
}

QString CountryProps::getC_countryName() const
{
    return c_countryName;
}
