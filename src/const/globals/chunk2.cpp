extern const int NN = 22;     // inna stała
extern const int MM;          // błąd
// zadeklaruj stałą globalną — pamięć zaalokowana w innym miejscu
extern const int QQ;    // deklaracja zewnętrzna
void newFunction() {
   int x = QQ + NN;
}
