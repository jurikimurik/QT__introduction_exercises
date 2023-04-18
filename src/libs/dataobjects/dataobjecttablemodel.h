#ifndef DATAOBJECTTABLEMODEL_H
#define DATAOBJECTTABLEMODEL_H

#include <QSharedPointer>
#include <QAbstractTableModel>
#include <QVariant>
#include <QModelIndex>
#include <QStringList>
#include <QTimer>
using namespace Qt;

#include "dataobject.h"

/**  @short Przykładowy model tablicowy dla QList<QSharedPointer<DataObject> >
     Klasa korzysta z API metawłaścwości w celu pobrania informacji o nagłówku
     tabeli. Wiersze są przechowywane na liście QList<DataObject*>.
*/
//start id=dotm
class DOBJS_EXPORT DataObjectTableModel : public QAbstractTableModel {
    Q_OBJECT
  public:
    /**
      @param headerModel - przykładowa klasa dziedzicząca z DataObject 
       ze zdefiniowanymi właściwościami, wykorzystywana do określenia nazw i typów 
	   w nagłówku tabeli.
       @see extractHeaders()
    */
    explicit DataObjectTableModel(DataObject* headerModel = 0, 
                                  QObject* parent=0);

    /** Wstawia nowy rekord do tabeli
       @param newRecord - DataObject, który ma zostać potraktowany jako wiersz tabeli.
       @param position - numer wiersza, pod który ma zostać wstawiony obiekt. 
	   -1 oznacza wstawienie na końcu.
      */
    virtual bool insertRecord(QSharedPointer<DataObject> newRecord,
                              int position = -1,
                              const QModelIndex& = QModelIndex());

                              /**
       @return każdy DataObject w wersji toString()
    */
    QStringList toStringList() const;

    QString toString() const;

    virtual int fieldIndex(const QString& fieldName) const;

    /** Niszczy wszystkie obiekty DataObjects, 
       które zostały dodane do tego modelu. */
    virtual ~DataObjectTableModel();
//end
//start id=abstract
    /* Metody, które muszą zostać przesłonięte 
       z powodu QAbstractTableModel */
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

    /** @return dane pod tym indeksem
        @param index lokalizacja danych
        @param role jeśli Qt::UserRole, to zwróć nazwę objectName
                obiektu DataObject na pozycji index.row()
    */
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section,
                        Qt::Orientation orientation = Qt::Horizontal,
                        int role = DisplayRole) const;
    ItemFlags flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index, const QVariant& value,
                 int role = EditRole);
    bool insertRows(int position, int rows,
                    const QModelIndex& index = QModelIndex());
    bool removeRows(int position, int rows,
                    const QModelIndex& index = QModelIndex());
//end
    virtual int findRow(const QString& name);
//start id=dotm
  public slots:
    void clear();
    /** Oznacz wiersz odpowiadający temu dataobject jako zmieniony */
    void rowChanged(const QString& fileName);

  protected:
    QList<QSharedPointer<DataObject> > m_Data;
    QList<bool> m_isEditable;
    QStringList m_Headers;
    DataObject* m_Original;
    /** ustawia headerModel w oparciu o nazwy i typy właściwości. 
        TODO: Użyj setRoleNames(roles), funkcji wprowadzonej w Qt 4.6,
		dzięki czemu wszystko zadziała również w widokach QML.
    */
    void extractHeaders(DataObject* hmodel);
  public:

    /** Funkcja pomocnicza dla insertRecord
    */
    DataObjectTableModel& operator<<(QSharedPointer<DataObject> newObj) {
        insertRecord(newObj);
        return *this;
    }
};
//end
#endif

