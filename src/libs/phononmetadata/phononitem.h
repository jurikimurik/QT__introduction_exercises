#ifndef PHONONITEM_H
#define PHONONITEM_H
#include <phonon>
#include "metadataobject.h"

namespace Phonon {
    class MetaDataLoader;
};

/** Nakładka na Phonon::MediaSource.
    Pobiera metadane z plików multimedialnych
	w sposób nieblokujący, przy użyciu Phonon API.
	Phonon tworzy co najmniej jeden wątek na każde pobranie metadanych.

	Nie twórz w sposób bezpośredni instancji tej klasy - skorzystaj z MetaDataLoader.
    
    Przetestowane dla Linuksa, Qt 4.7.1. Nie działa z plikami MP3s w systemie Windows,
    podobnie jak przykładowy odtwarzacz z Qt 4.7 (w sensie pobierania metadanych)

    @see MetaDataLoader::get()
    @version 1.0  2010-10-05
*/
//start id="phononitem"
class PhononItem : public MetaDataObject {
    Q_OBJECT
public:
    friend class Phonon::MetaDataLoader;
    virtual ~PhononItem();
//end
    /** Zmienia nazwę pliku. Czyści zasoby.
        Nie inicjalizuje pobierania metadanych. */
    virtual void setFileName(QString name);
    virtual Preference preference() const ;
    virtual QString genre() const;
    virtual QString artist() const;
    virtual QString albumTitle() const;
    virtual QString trackTitle() const;
    virtual QString trackNumber() const;
    virtual QTime trackTime() const;
    virtual QString comment() const;
    Phonon::MediaSource source() {
        return m_mediaSource;
    }
//start id="phononitem"
    /** @return false jeśli danych nie ma w bazie.
     W przypadku poprawnych plików pobierze dane
     w sposób nieblokujący */
    bool checkMetaData() const;

protected:
    /** @see MetaDataLoader::get() */
    explicit PhononItem(QString path=QString(), QObject* parent=0);
    void fetchMetaData();
//end
private slots:
    void setTotalTime(qint64 tt);
    void metaStateChanged(Phonon::State newState, Phonon::State oldState);
//start id="phononitem"
signals:
    void fetched(bool success = true);
private:
    bool m_timeSet, m_loaded;
    QString extendedComment;
    Phonon::MediaSource m_mediaSource;
    Phonon::MediaObject *m_metaMedia;
};
//end


#endif // PHONONITEM_H
