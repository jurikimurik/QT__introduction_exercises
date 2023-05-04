#include "relations.h"

#include <QDebug>

QTextStream cout(stdout);
QTextStream cin(stdin);

Relations::Relations(QObject* parent) : QAbstractTableModel(parent), m_columns(2)
{
    relations = {qMakePair("a", "a"), qMakePair("b", "b"),
                 qMakePair("c", "c"), qMakePair("d", "d"),
                 qMakePair("a", "b"), qMakePair("b", "a")};
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

QStringList Relations::relationTo(QString what) const
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
    return relations.uniqueKeys().size();
}

int Relations::columnCount(const QModelIndex &parent) const
{
    return m_columns;
}

QVariant Relations::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= rowCount()) return QVariant();
    int col = index.column();
    if (col >= columnCount()) return QVariant();

    if (role == Qt::DisplayRole) {
        return relations.uniqueKeys().at(row);
    }


    if(role == Qt::CheckStateRole) {
        if(col == 1 && selectedIndex.isValid())
        {
            QString key = selectedIndex.data().toString();
            auto relacje = relationTo(key);
            if(relacje.contains(index.data().toString()))
                return Qt::Checked;
            else
                return Qt::Unchecked;
        }

    }



    return QVariant();
}

Qt::ItemFlags Relations::flags(const QModelIndex &index) const
{

    if(!index.isValid())
        return Qt::ItemFlags::fromInt(0);

    Qt::ItemFlags flagi = QAbstractTableModel::flags(index);

    if (index.column() != 0) {
        return flagi | Qt::ItemIsUserCheckable;
    } else {
        return flagi;
    }

    return Qt::ItemIsEnabled;


}

bool Relations::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << value.toString();
    if(!index.isValid() || selectedIndex.data() == index.data()) {
        return false;
    }


    if(role == Qt::CheckStateRole && index.column() == 1)
    {
        emit dataChanged(index,index,{role});
    }
    return true;
}

void Relations::showRelation(const QModelIndex &index)
{
    selectedIndex = index;
    emit dataChanged(index, index);
}
