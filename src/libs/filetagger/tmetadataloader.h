#ifndef METADATALOADER_H
#define METADATALOADER_H

#include <QObject>
#include <QTimer>
#include "metadatavalue.h"
#include "filetagger_export.h"
#include "abstractmetadataloader.h"

namespace TagLib {

//start
/** Odczytuje metadane plików mp3 przy użyciu TagLib 1.6.3.
    http://taglib.github.io/
*/
class FILETAGGER_EXPORT MetaDataLoader 
                          : public Abstract::MetaDataLoader {
    Q_OBJECT
public:
    typedef Abstract::MetaDataLoader SUPER;
    explicit MetaDataLoader(QObject *parent = 0);
    static MetaDataLoader* instance();
    virtual ~MetaDataLoader() {}
    const QStringList &supportedExtensions() ;
    /** nieblokująca metoda pobierająca metadane.
        Syngał fetched() jest emitowany, gdy dane są gotowe.
    */
    MetaDataLoader* clone(QObject *parent) ;
    void get(QString path);
    void get(QStringList path);
    bool isRunning() const {return m_running;}
public slots:
    void cancel();
private slots:
    void checkForWork();

private:
    bool m_running;
    bool m_canceled;
    int m_processingMax;
    QStringList m_queue;
    QTimer m_timer;
};
}

//end

#endif // METADATALOADER_H
