class Point {                           /* Nagłówek klasy. */
 public:
    Point(int x, int y, int z);         /* Deklaracja konstruktora. */
    int distance(Point other);          /* Deklaracja funkcji. */
    double norm() const {               /* Deklaracja i definicja. */         
        return distance(Point(0,0,0));
    } 
 private:
    int m_Xcoord, m_Ycoord, m_Zcoord;   /* Deklaracja składowej klasy. */
};

