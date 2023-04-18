#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <QString>

//start
class Matrix {
public:
    Matrix(int rows, int cols);                 /* Alokuje wszystkie komórki i ustawia ich wartość na 0. */
    Matrix(const Matrix& mat);                  /* Konstruktor kopiujący; klonuje mat. */
    ~Matrix();
    double& operator()(int i, int j);
    double operator()(int i, int j) const;
    // Some useful Matrix operations
    Matrix& operator=(const Matrix& mat);       /* Usuwa zawartość gospodarza; klonuje mat. */
    Matrix operator+(const Matrix& mat) const;  /* Dodawanie macierzy. */
    Matrix operator*(const Matrix& mat) const;  /* Mnożenie macierzy. */
    bool operator==(const Matrix& mat) const;
    int getRows() const;
    int getCols() const;
    QString toString() const;
private:
    int m_Rows, m_Cols;
    double  **m_NumArray;
    //Some refactoring utility functions
    void sweepClean();                          /* Usuwa wszystkie komórki gospodarza. */
    void clone(const Matrix& mat);              /* Wykonuje kopię gospodarza, korzystając z nowej pamięci. */
    double rcprod(int row, const Matrix& mat, int col) const; 
                                                /* Oblicza iloczyn rzędu gospodarza z kolumną mat. */
};
//end
#endif
