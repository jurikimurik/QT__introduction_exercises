#include "person.h"
#include <QTextStream>
#include <vector>
#include <random>
using namespace Qt;


int main()
{

    vector<Person> persony = {Person("Jean-Lue Picard"), Person("Wesley Crusher"), Person("Bakou Le-le"), Person("Karol Krolewicz")};

    vector<Position> stanowiska_gwiezdne = {Position("Tester mieczy", "Testuje mieczy laserowe"), Position ("Szturmowiec", "Stara sie strzelac"),
                                            Position ("Dzedai", "Zdadziecki dzedai na naszej stronie")};

    vector<Position> stanowskia_borg = {Position("Duch", "Wedruje w nieznane."), Position("Wojownik", "Wielki wojownik duchowy"),
                                        Position("Mag", "Strzela kulkami. Wow!")};

    vector<Employer> zatrudniaczy = {Employer("Flota Gwiezdna", "Kosmos"), Employer("Borg", "Nieznany dzial")};

    std::default_random_engine dre(std::time(nullptr));
    for(auto& elem : persony)
    {
        std::uniform_int_distribution zatr_rand(0ul, zatrudniaczy.size()-1);
        std::uniform_int_distribution stan_rand(0ul, stanowiska_gwiezdne.size()-1);

        if(zatr_rand(dre) == 0)
        {
            elem.setPosition(zatrudniaczy[0], stanowiska_gwiezdne[stan_rand(dre)]);
        } else {
            elem.setPosition(zatrudniaczy[1], stanowskia_borg[stan_rand(dre)]);
        }
    }

    for(const auto& elem : persony)
    {
        cout << elem.toString() << endl;
    }


}

