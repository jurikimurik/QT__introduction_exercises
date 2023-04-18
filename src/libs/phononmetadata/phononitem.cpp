#include "phononitem.h"
#include <QFile>

PhononItem::~PhononItem() {
    delete m_metaMedia;
}

PhononItem::PhononItem(QString path, QObject* parent)
: MetaDataObject(parent),
 m_timeSet(false), m_loaded(false), m_metaMedia(0) {
    if (path != QString())
        setFileName(path);
}

void PhononItem::setFileName(QString name) {
    QFile qf(name);
    if (!qf.exists()) {
        name = QString();
    }
    m_loaded = false;
    m_timeSet = false;
    if (m_metaMedia != 0) {
        delete m_metaMedia;
        m_metaMedia = 0;
    }
    MetaDataObject::setFileName(name);

}

bool PhononItem::checkMetaData() const {
    /* Dzięki temu możliwe jest pobieranie danych w sposób
	   "leniwy", na żądanie, a nie w czasie tworzenia obiektu.
       Pobieranie metadanych prowadzi do powstania wątku!
    */
    if (fileName() == QString()) return false;
    if (!m_loaded && m_metaMedia == 0) {
       PhononItem* that = const_cast<PhononItem*>(this);
       that->fetchMetaData();
       return false;
    }

    else return true;


}
//start id="get"
void PhononItem::fetchMetaData() {
    delete m_metaMedia;

    m_mediaSource = Phonon::MediaSource(fileName());
    if (m_mediaSource.type() == Phonon::MediaSource::Invalid) {
        qDebug() << "Niepoprawne źródło danych." << fileName();
        emit fetched(false);

    }
    m_metaMedia = new Phonon::MediaObject(this);


    QObject::connect(m_metaMedia, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
                     this, SLOT(metaStateChanged(Phonon::State, Phonon::State)), Qt::QueuedConnection);
    QObject::connect(m_metaMedia, SIGNAL(totalTimeChanged(qint64)),
                     this, SLOT(setTotalTime(qint64)), Qt::QueuedConnection);

    m_metaMedia->setCurrentSource(m_mediaSource);

}
//end
void PhononItem::setTotalTime(qint64 tt) {
    QTime duration(0,0,0,0);
    duration = duration.addMSecs(tt);
    setTrackTime(duration);
//    qDebug() << "setTotalTime: " << duration;
    m_timeSet = true;
    if (m_loaded) {
        emit fetched();

    }
}

void PhononItem::metaStateChanged(Phonon::State newState, Phonon::State oldState) {
    Q_UNUSED(oldState);
  //  static QObjectWriter writer(this, false);

    if (newState == Phonon::ErrorState) {
        qDebug() << "PhononItem: Błąd podczas otwierania pliku: " << fileName();

        emit fetched(false);
        return;
    }

    if (m_metaMedia->currentSource().type() == Phonon::MediaSource::Invalid) {

        emit fetched(false);
        qDebug() << "Niepoprawne metadane: " << fileName();
        return;
    }

    QMap<QString, QString> metaData = m_metaMedia->metaData();

    setArtist(metaData.value("ARTIST"));
    setTrackTitle(metaData.value("TITLE"));
    setAlbumTitle(metaData.value("ALBUM"));
    setGenre(metaData.value("GENRE"));
    QString tn = metaData.value("TRACK-NUMBER");
    if (tn == QString()) tn = metaData.value("TRACKNUMBER");
    setTrackNumber(tn);
    extendedComment = QString();
    QString comment =  metaData.value("COMMENT");
    setComment(comment);
    
    // http://www.freedesktop.org/wiki/Specifications/free-media-player-specs
    QString fmpsRating = metaData.value("FMPS_Rating");
    // ??? Dlaczego to nie działa?
    if (fmpsRating.toDouble() > 0 ) {
        int stars = fmpsRating.toDouble() * 10;
        Preference fmpsPref(stars);
        qDebug() << "FMPS Rating: " << stars;
        setPreference(fmpsPref);
    }

    // Preferencje można uzyskać na różne sposoby.
    else setPreference(comment);

    // Sprawdź preferencje MusicMatch
    if ((preference().intValue() == 0) && metaData.contains("EXTENDED-COMMENT")) {
        extendedComment = metaData.value("EXTENDED-COMMENT");
        int eqidx = extendedComment.indexOf("=");
        if (eqidx > 0)
            extendedComment=extendedComment.mid(eqidx+1);
        Preference p(extendedComment);
        if (p.intValue() > 0) {
            setPreference(p);
            setComment(p.toString());
        }
    }

//start id="notify"
    m_loaded = true;
    if (m_timeSet) {
        emit fetched();
    }
//end

}

QString PhononItem::genre() const {
    checkMetaData();
    return MetaDataObject::genre();
}
QString PhononItem::artist() const {
    checkMetaData();
    return MetaDataObject::artist();
}

QString PhononItem::albumTitle() const {
    checkMetaData();
    return MetaDataObject::albumTitle();
}
QString PhononItem::trackTitle() const {
    checkMetaData();
    return MetaDataObject::trackTitle();
}

QString PhononItem::trackNumber() const {
    checkMetaData();
    return MetaDataObject::trackNumber();
}
QTime PhononItem::trackTime() const {
    checkMetaData();
    return MetaDataObject::trackTime();
}
QString PhononItem::comment() const {
    checkMetaData();
    return MetaDataObject::comment();
}

Preference PhononItem::preference() const {
    checkMetaData();
    return MetaDataObject::preference();
}
