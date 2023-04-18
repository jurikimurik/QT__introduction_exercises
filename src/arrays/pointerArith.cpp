#include <iostream>
//start
int main()  {
    using namespace std;
    int y[] = {3, 6, 9};
    int x = 12;
    int* px;
    px = y;  /* Każda zmienna tablicowa (np. y) 
			jest aliasem dla wskaźnika na pierwszy element tablicy. */
    cout << "Następnie mamy: " << *++px << endl;
    cout << "Następnie mamy: " << *++px << endl;
    cout << "Następnie mamy: " << *++px << endl;
    cout << "Następnie mamy: " << *++px << endl;
    return 0;
}
