#include "relations.h"

#include <QDebug>

Relations::Relations()
{

}

void Relations::enterRelation()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    cout << "Wprowadz relacje (w postaci *lancuch*=*lancuch*) (q - skonczyc): " << Qt::flush;
    QString line;
    cin >> line;

    if(line != "q")
        processLine(line);
    else
        exit(EXIT_SUCCESS);
}

void Relations::processLine(QString line)
{
    // Jezeli chodzi tylko o wypisanie
    if(!line.contains("=")) {
        showRelationTo(line);
        return;
    }


    QStringList podzielone = line.split("=");
    QString left = podzielone.at(0).trimmed();
    QString right = podzielone.at(1).trimmed();
    relations.insert(left, right);
    relations.insert(right, left);
}

void Relations::showRelationTo(QString what)
{
    QTextStream cout(stdout);

    what = what.trimmed();
    cout << what << " posiada relacje z: ";
    for(const auto& toRelation : relations.values(what))
    {
        cout << "\t" << toRelation << Qt::endl;
    }
    cout << Qt::endl << Qt::flush;
}
