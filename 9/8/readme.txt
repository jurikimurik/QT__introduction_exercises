Lab 2: Formularz zamówienia - pisany ręcznie.

Na tych zajęciach proszę o zaimplementowanie brakujących metod orderform.h
w celu stworzenia okna dialogowego do wprowadzania zamówień (obiekty Order).

Okno powinno mieć co najmniej 3 pola (etykieta + widżet do wprowadzania danych),
na przykład takie:

       QString name //nazwa
       QDate date //data 
       int quantity //ilość
       double unitPrice; //cena jednostkowa
       double totalPrice; //suma


Kod należy zapisać w pliku orderform.cpp.

Użytkownik ma mieć możliwość "zatwierdzenia" lub "anulowania" zamówienia.

Pole totalPrice powinno być tylko do odczytu. Jego wartość jest obliczana na podstawie ilości i ceny jednostkowej.
