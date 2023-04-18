#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include "dobjs_export.h"
//start
#include <QObject>
#include <QVariant>
#include <QMetaProperty>

/** @short Wspólna klasa bazowa struktur, które można klonować i które mogą stosowac mechanizm refleksji.
    Zawiera trochę metod pomocniczych ułatwiających dostęp do metadanych, 
	wykorzystywanych przez inne klasy, takie jak DataObjectTableModel.

	Nie musisz dziedziczyć z tej klasy w Twoim kodzie
    - klasa QObject może się okazać wystarczająca.
    
    DataObject pochodzi z zamierzchłych czasów Qt3, gdy klasa QObject była mniej rozbudowana.
*/
//end

class DOBJS_EXPORT DataObject : public QObject {
	Q_OBJECT

public:
	//start
public:
	Q_INVOKABLE explicit DataObject(QString name);
	Q_INVOKABLE explicit DataObject(QObject* parent=0);
	virtual ~DataObject();
	virtual bool readFrom(const QObject& source);

	/**
	 zapisuje wszystkie właściwości w QObject
	 @return true jeśli udało się ustawić właściwości
	 */
	virtual bool writeTo(QObject& dest) const;

	/**
	 przechodzi przez wayward i kradnie jego dzieco,
	 jako ich rodzica ustawiając this
	 @param wayward - inny QObject, którego dzieci chcemy dodać do this.
		  wayward straci dzieci.
	 */
	void adoptChildren(QObject* wayward);

	/**
	  @param compareChildren jeśli true, dzieci zostaną sprawdzone rekurencyjnie
	  @return true jeśli other ma te same wartości właściwości co this
	  */
	static bool equals(const QObject& left, const QObject& right, bool compareChildren=true) ;



	DataObject& operator=(const DataObject& other);


	/**
	 Nie możemy wirtualnie przesłonić QObject::className(), jednak i tak przesłonimy tę metodę.
	 W DataObject jest ona wirtualna, więc może zwrócić coś innego w klasach pochodnych. 

	 @return nazwa klasy aktualnego obiektu
	 */
	virtual QString className() const;


	/**
	 @return lista nazw właściwości; w ten sposób użytkownik klasy DataObject nie musi korzystać z @ref QMetaObject jedynie w celu pobrania tej listy
	*/
	virtual QStringList propertyNames() const;
	static QStringList propertyNames(const QObject*);

	/* publiczne funkcje pomocnicze zwracająca QMetaProperty dla danej nazwy właściwości (lub indeksu).
	*/
	virtual QMetaProperty metaProperty(const QString& propname) const;
	virtual QMetaProperty metaProperty(int i) const;

	/**
	@return liczba właściwości.
	 @param superclass uwzględnij w wyniku właściwości odziedziczone z nadklasy
	 (obecnie ignorowane)
	*/
	virtual uint numProperties() const;

	/**
	@return reprezentacja obiektu w formacie XML, czytelnym zarówno dla człowieka, jak i dla maszyny
	*/
	virtual QString toString() const;

	/** metoda przeładowana z myślą o QString */
	virtual QVariant property( QString name ) const;
	virtual QVariant property( const char* name) const;
	/**
	  Polimorficzna metoda clone() - jej poprawne zachowanie polega na 
	  skopoiwaniu wszystkich właściwości z *this do nowej kopii.
	  @return świeżo zaalokowana kopia *this

	  Klasy pochodne powinny ją przesłaniać.

	  @param deep jeśli true, tworzy klony wszystkich dzueci 
			 i odtwarza drzewo.
	  */
	virtual DataObject* clone(bool deep=false) const;
signals:
	/** Emitowane do zainteresowanych modeli
		(w szczególności DataObjectTableModel)
		*/
	void dataObjectChanged(const QString& name);
public slots:

	/**
	 * metoda przeładowana z myślą o QString
	  @param propertyName nazwa właściwości, która ma zostać ustawiona
	  @param value wartość do nadania właściwości
	  @return true jeśli wartość zachowuje ograniczenia (wyrażenie regularne) dla tej właściwości.

	  UWAGA: W wersji Qt3 te metody QObject były wirtualne, ale od Qt4 już takie nie są.
	  Oznacza to, że metody te nie zostaną wywołane, jeśli skorzystać z interfejsu QObject.
 */
	virtual bool setProperty(const QString &propName, const QVariant &qv);
	virtual bool setProperty(const char* propName, const QVariant& qv);

};
//end
DOBJS_EXPORT bool operator==(const QObject& left, const QObject& right) ;


#endif        //  #ifndef DATAOBJECT_H
