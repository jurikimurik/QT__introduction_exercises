#include <QList>
#include <QString>
#include <QFile>
#include <QTime>
#include <QStringList>
#include <QTextStream>

#include "metadatafactory.h"
#include "metadata.h"


MetaDataFactory::MetaDataFactory() {
    int seed = QTime::currentTime().second();
    qsrand(seed);
}

QSharedPointer<MetaData> MetaDataFactory::randomSong(int i) const {
    QSharedPointer<MetaData> retval(new MetaData());
    QString title = QString("TytułNagrania%2 Lista%1").arg(i).arg(qrand()%600);
    QString artist = QString("LosowyArtysta%1").arg(qrand()%20);
    QString album = QString("LosowyAlbum%1").arg(qrand()%20);
    QString genre = QString("Gatunek%1").arg(qrand()%20);
    retval->setArtist(artist);
    retval->setTrackTitle(title);
    retval->setAlbumTitle(album);
    retval->setGenre(genre);
    retval->setTrackNumber(qrand() % 20);
    retval->setTrackTime(QTime(0, qrand()%20, qrand()%60 ));
    StarRating rating(qrand() % 5, 5);
    retval->setRating(rating);
    retval->setFileName("/dev/null");
    return retval;
}

