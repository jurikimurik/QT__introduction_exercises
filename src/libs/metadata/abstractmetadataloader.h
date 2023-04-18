#ifndef AMETADATALOADER_H
#define AMETADATALOADER_H

#include "metadatavalue.h"

//start
namespace Abstract {
/** Abstrakcyjny interfejs ładowania metadanych z plików. 
	Stwórz konkretną instancję i dodaj ją jako dziecko do qApp.
	Pobierzesz ją przy użyciu abstrakcyjnej metody instance().
*/
class METADATAEXPORT MetaDataLoader : public QObject {
    Q_OBJECT
public:
    
    explicit MetaDataLoader(QObject *parent = 0) 
    	: QObject(parent) {}
    
    /** @return pierwsza odnaleziona instancja MetaDataLoader będąca dzieckiem qApp */
    static MetaDataLoader* instance();
    /** Zwraca inną instancję tego samego typu */
    virtual MetaDataLoader* clone(QObject* parent=0) = 0;
    virtual ~MetaDataLoader();
    virtual const QStringList& supportedExtensions() = 0;
    /** nieblokująca metoda pobierająca metadane.
        Sygnał fetched() jest emitowany, gdy dane są gotowe.
    */
    virtual void get(QString path) = 0;
    virtual void get(QStringList path) = 0;
    virtual bool isRunning() const = 0;
public slots:
    virtual void cancel() = 0;
    
signals:
    /** Emitowany po pobraniu metadanych przez ten obiekt. */
    void fetched(const MetaDataValue& mdv);
    void progressValueChanged(int);
    void progressRangeChanged(int, int);
    void finished();

};
}

#endif // AMETADATALOADER_H
