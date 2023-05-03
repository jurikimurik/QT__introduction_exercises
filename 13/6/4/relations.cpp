#include "relations.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

Relations::Relations(QObject* parent) : QAbstractTableModel(parent), m_columns(2)
{

}

void Relations::enterRelation()
{
    cout << "Wprowadz relacje (w postaci *lancuch*=*lancuch*) (q - skonczyc): " << Qt::flush;
    QString line;
    cin.readLineInto(&line);

    if(line != "q")
        processLine(line);
    else
        exit(EXIT_SUCCESS);
}

void Relations::processLine(QString line)
{
    //Jezeli chodzi o cofniecie
    if(line.contains("takeback")) {
        int i = line.remove("takeback").trimmed().toInt();
        takeback(i);
        return;
    }

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
    buffor.push_back(left + "=" + right);
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

void Relations::takeback(int n)
{
    if(n-1 < 0 || n-1 >= buffor.size()) {
        cout << "Zly numer dzialania!" << Qt::endl << Qt::flush;
        return;
    }

    QStringList cofanieKtorych = buffor.at(n-1).split("=");
    if(cofanieKtorych.size() != 2) {
        cout << "Nie bylo to tworzenie relacji!" << Qt::endl << Qt::flush;
        return;
    }
    relations.remove(cofanieKtorych.at(0), cofanieKtorych.at(1));
    relations.remove(cofanieKtorych.at(1), cofanieKtorych.at(0));

    cout << "Relacja " << cofanieKtorych.at(0) << "=" << cofanieKtorych.at(1) << " zostala usunieta!" << Qt::endl
         << Qt::flush;

}

QStringList Relations::relationTo(QString what)
{
    QStringList lista;
    for(const auto& toRelation : relations.values(what))
    {
        lista << toRelation;
    }
    return lista;
}

void Relations::setRelations(const QMultiMap<QString, QString> &newRelations)
{
    relations = newRelations;
}

QMultiMap<QString, QString> Relations::getRelations() const
{
    return relations;
}

void Relations::addRelation(QString from, QString to)
{
    relations.insert(from, to);
}

int Relations::rowCount(const QModelIndex &parent) const
{
    return relations.size();
}

int Relations::columnCount(const QModelIndex &parent) const
{
    return m_columns;
}

Qt::ItemFlags Relations::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return 0;

    if(index.data().toString() == index.parent().data().toString)
        return 0;


    if(index.column() == 2)
        return Qt::ItemIsUserCheckable;
    else
        return Qt::ItemIsEnabled;

}
