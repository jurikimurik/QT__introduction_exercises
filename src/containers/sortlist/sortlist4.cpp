#include <QList>
#include <QtAlgorithms>   // for qSort()
#include <QStringList>
#include <QDebug>

class CaseIgnoreString : public QString {
public:
    CaseIgnoreString(const QString& other = QString()) 
    : QString(other) {}
    bool operator<(const QString & other) const {
        return toLower() < other.toLower();
    }
    bool operator==(const QString& other) const {
        return toLower() == other.toLower();
    }
};

int main() {
    CaseIgnoreString s1("Arbuz"), s2("baran"),
                     s3 ("CzajkA"), s4("doberman"), s5 ("Doberman");

    Q_ASSERT(s4 == s5);
    Q_ASSERT(s2 < s3);
    Q_ASSERT(s3 < s4);

    QList<CaseIgnoreString> namelist;

    namelist << s5 << s1 << s3 << s4 << s2;                  ///1

    qSort(namelist.begin(), namelist.end());
    int i=0;
    foreach (const QString &stritr, namelist) {
        qDebug() << QString("namelist[%1] = %2")
                       .arg(i++).arg(stritr) ;
    }

    QStringList strlist;
    strlist << s5 << s1 << s3 << s4 << s2;                  ///2

    qSort(strlist.begin(), strlist.end());
    qDebug() << "Posortowana lista StringList: " + strlist.join(", ");
    return 0;
}


