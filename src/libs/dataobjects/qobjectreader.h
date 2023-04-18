#ifndef DATAOBJECTREADER_H
#define DATAOBJECTREADER_H

//start
#include "dobjs_export.h"
#include <QString>
#include <QStack>
#include <QQueue>
#include <QXmlDefaultHandler>

class AbstractFactory;

/** Parsuje XML i zwraca drzewa obiektów QObject. 
 Klasa pozwala na importowanie danych z pliku XML.
 Tworzy kolejkę dynamicznie alokowanych QObject
 i zwraca je po jednym poprzez importInstance(). 
 Utrzymywane są relacje rodzic-dziecko,
 a właściwości są ustawiane w oparciu o specyfikację wejściową.
 @author Alan Ezust
 
*/
class DOBJS_EXPORT  QObjectReader : public QXmlDefaultHandler {
  public:
    /**
	 Parsuje plik i przechowuje wewnętrznie listę obiektów,
	 które można pobrać korzystając z 
     @ref importInstance()
     @param factory fabryka obiektów, z której chcesz skorzystać
     po napotkaniu znacznika <object>.
     Domyślna fabryka tworzy jedynie instancje
     @ref PropsMap przechowujące właściwości.
    */
    explicit QObjectReader (AbstractFactory* factory=0) : 
                         m_Factory(factory), m_Current(0) { }
    explicit QObjectReader (QString filename, AbstractFactory* factory=0);
    void parse(QString text);
    void parseFile(QString filename);
    /**
        @return korzeń drzewa XML, jeśli istnieje.
        NULL jeśli nie. 
		Jeśli reprezentuje on element z elementami potomnymi,
		zostaną one zwrócone jako jako dzieci.
    */
    QObject* getRoot();
    ~QObjectReader();

    // metody do wywołań zwrotnych z QXmlDefaultHandler
    bool startElement( const QString& namespaceURI,
                       const QString& name,
                       const QString& qualifiedName,
                       const QXmlAttributes& attributes );
    bool endElement(  const QString& namespaceURI,
                      const QString& localName,
                      const QString& qualifiedName);
    bool endDocument();
  private:
    void addCurrentToQueue();
    AbstractFactory* m_Factory;
    QObject* m_Current;
    QQueue<QObject*> m_ObjectList;
    QStack<QObject*> m_ParentStack;
};
//end

#endif        //  #ifndef DATAOBJECTREADER_H
