#include <QTextStream>
#include <QString>

int main() {
    const char* charstr = "to jest bardzo długi string "
                "ciągnący się przez dwie linie";
    QTextStream cout(stdout);  
    QString str = charstr;   /*Łańcuchy znaków w stylu C można zamienić na typ QString.*/
    cout << str << endl;
    cout << "\nA\tb\\c\'d\"" << endl;
    return 0;
}
