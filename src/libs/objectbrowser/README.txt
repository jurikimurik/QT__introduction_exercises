*******************************************************
*** QObjectBrowser                                    *
*** Utworzone przez by Jeremy Magland on 13 June 2007         *
*** Zmodyfikowane przez krawek on 15 June 2007                *
*** Zmodyfikowane przez magland on 18 June 2007 - widget tree *
*** Zmodyfikowane przez magland on 19 June 2007               
*** Zmodyfikowane przez Alan Ezust in July 2010, May 2011
    Wymaga Qt 4.6 z powodu wykorzystania QScopedPointer.
	Buduje się pod windows jako biblioteka eksportująca symbole.
    Dodana akcja przełączająca widok: QObjectBrowserAction
        która tworzy qobjectbrowser w sposób leniwy, na żądanie. 
    Przeglądarka ObjectBrowser zamieniona w QWidget zamiast głównego okna.
    Nowe właściwości dla nazwy obiektu w widoku drzewiastym.
    Pozwala na dodawanie obiektów QObjectTreeModel
    Pokazuje qApp na liście obiektów. 
    
*******************************************************
Oryginalny kod:
http://www.qtcentre.org/threads/7539-QObjectBrowser

QObjectBrowser to przydatny kod pozwalający na przeglądanie
widżetów QWidget i obiektów QObject w czasie działania aplikacji.

*******************************************************
Instalacja:
	Wywołaj qmake i make w głównym katalogu objectbrowser.
	* biblioteka zostanie utworzona w głównym katalogu

*******************************************************
Użycie #1: w aplikacji dodaj następujący kod:
	QObjectBrowser *browser=new QObjectBrowser;
	browser->showNormal();
*******************************************************
Użycie #2: Poniższa linia dodaje do menu akcję pozwalającą 
			na uruchomienie przeglądarki:
    viewMenu->addAction(new QObjectBrowserAction(this));

Licencja: GPL

Możesz dowolnie modyfikować źródła i publikować wyniki swojej pracy 
na forum QtCentre... lub możesz wysłać je bezpośrednio do mnie -
wtedy ja je opublikuję.

J. Magland
