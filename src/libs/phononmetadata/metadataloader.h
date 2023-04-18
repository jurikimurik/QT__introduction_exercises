#ifndef METADATALOADER_H
#define METADATALOADER_H
#include "phonon_mdexport.h"
#include "phononitem.h"
#include <QSharedPointer>
#include <QSemaphore>
#include <QTimer>
#include <QTime>
#include <QEvent>
#include "metadatavalue.h"
#include "abstractmetadataloader.h"

namespace Phonon {

/** Klasa, która wczytuje tagi metadanych przy użyciu klasy PhononItem.
    W przypadku plików mp3s nie zadziała to pod Windows z powodu ograniczeń
	biblioteki Phonon.
    
    Spróbuj zastosować zamienniki MetaDataLoader z katalogów
	../filetagger i ../mobilitymetadata    
*/
//start
class PHONON_MDEXPORT MetaDataLoader : public Abstract::MetaDataLoader {
	Q_OBJECT
public:
    /** @return instancja singletonowa */
    static MetaDataLoader* instance();
    explicit MetaDataLoader(QObject* parent=0);
    virtual ~MetaDataLoader();
    MetaDataLoader* clone(QObject* parent = 0);
    /** @returns wychodzi natychmiast, a później wysyła sygnał, że metadane są gotowe. */
    void get(QString path);
    bool isRunning() const ;
    void get(QStringList paths);
    /** @return lista rozszerzeń plików wspieranych przez program */
    const QStringList &supportedExtensions() ;
public slots:
    /** Wywołaj, jeśli chcesz zatrzymać pobieranie metadanych */
    void cancel();

private slots:
    void failed();
    void grabFirst();
    void checkForWork();
    void copyData(bool success=true);

private:
    QTimer m_timeOut;
    bool m_isBusy;
    PhononItem m_item;
    QStringList m_queuedPaths;
    int totalFetched;
};
//end
}
#endif // METADATALOADER_H
