#ifndef PUZZLE_H
#define PUZZLE_H

#include <QApplication>
#include <QMainWindow>
#include <QList>
#include <QPushButton>
#include <QActionGroup>
#include <QButtonGroup>

class QGridLayout;

/** Przechowuje wewnętrzną reprezentację przesuwanki, bez wiedzy o widoku */
class PuzzleModel : public QObject {
    Q_OBJECT
  public:
    /** Tworzy przesuwankę w rozmiarze rows*columns */
    PuzzleModel(int rows, int columns, QObject* parent=0);

    /** Zwraca index w m_Positions dla danych r (wiersz), c (kolumna)
    @return 0 jeśli kwadrat jest pusty, lub numer płytki na danej pozycji. */
    int value(int r, int c) const;

    QString toString() const;

	/** @return wymiary przesuwanki */
    int size() const;

    /** Próbuje przesunąć płytkę o wskazanym numerze. 
    @return true jeśli się udało, co jest możliwe tylko,
    jeśli sąsiadem jest pusty kwadrat (0). 
    */    
    bool slide(int tilenum); 

    /** @return true jeśli dwie płtyki ze sobą sąsiadują.
        pos1 i pos2 to pozycje w indeksie (przesunięcie względem 0)
	*/
    bool neighboring(int pos1, int pos2) const;

    int rows() const {return m_Rows;}
    int cols() const {return m_Cols;}

    /** @return indeks w tablicy przechowującej płytkęna pozycji (r,c).
    */
    int index(int r, int c) const;
  public slots:
    void shuffle(); 
  signals:
    void gridChanged();
	
  private:
    QList<int> m_Positions;
    int m_Rows, m_Cols;
};

/** Pojedyncza płytka w GUI dla przesuwanki o rozmiarze 15 */
class Tile : public QPushButton {
    Q_OBJECT
  public:
    Tile(int tileNumber);
    int getNumber() {return m_Number;}
  private:
    int m_Number;
    
};

/** 	 */
class PuzzleView : public QWidget {
    Q_OBJECT
  public:
    PuzzleView(PuzzleModel*);
  public slots:
    void refresh();
    void tryToSlide(QAbstractButton* button);
  private:
    PuzzleModel *m_Model;
    QGridLayout *m_Layout;
    QButtonGroup m_Tiles;
};

/** Klasa kontrolera - zarządza wszystkimi innymi obiektami. */
class PuzzleApp : public QApplication {
    Q_OBJECT
  public:
    PuzzleApp(int argc, char* argv[]);
    void createWidgets();
    void createActions();
  private:
    QMainWindow m_MainWin;
    PuzzleModel *m_Model;
    PuzzleView *m_View;
    QAction* m_Shuffle;
};
#endif        //  #ifndef PUZZLE_H

