#include <QStringList>
#include <QDebug>

/* Kilka prostych przykładów z QStringList, split i join */

int main() {


    QString winter = "grudzień, styczeń, luty";
    QString spring = "marzec, kwiecień, maj";
    QString summer = "czerwiec, lipiec, sierpień";
    QString fall = "wrzesień, październik, listopad";


    QStringList list;
    list << winter;                            /* Pierwszy operator dodania do listy. */
    list += spring;                            /* Drugi operator dodania do listy. */
    list.append(summer);                       /* Funkcja składowa dodająca do listy. */
    list << fall;

    qDebug() << "Miesiące wiosenne to: " << list[1];

    QString allmonths = list.join(", ");       /* Zamień listę na łańcuch znaków, łącząc elementy łańcuchem ", ". */
    qDebug() << allmonths;

    QStringList list2 = allmonths.split(", "); /* Split to przeciwieństwo join. Każdy miesiąc będzie osobnym elementem. */

    Q_ASSERT(list2.size() == 12);              /* Asercja doprowadzi do przerwania programu, jeśli warunek nie będzie spełniony. */

    foreach (const QString &str, list) {       /* Pętla foreach z Qt, podobna do pętli for znanej z Perla, Pythona i Javy 1.5. */
        qDebug() << QString(" [%1] ").arg(str);
    }

    for (QStringList::iterator it = list.begin();
         it != list.end(); ++it) {             /* Iteracja w stylu C++ STL. */
        QString current = *it;                 /* Wyłuskanie z użyciem wskaźnika. */
        qDebug() << "[[" << current << "]]";
    }

    QListIterator<QString> itr (list2);        /* Iterator w stylu Javy 1.2.  */
    while (itr.hasNext()) {                    /* Iteratory javowe wskazują miejsce pomiędzy elementami listy. */
        QString current = itr.next();
        qDebug() << "{" <<  current << "}";
    }
    return 0;
}
