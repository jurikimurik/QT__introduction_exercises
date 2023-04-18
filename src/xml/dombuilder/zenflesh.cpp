#include <QTextStream>
#include <docbookdoc.h>
/** Przykładowy program tworzy dokumenty w sposób deklaratywny, 
   przy użyciu biblioteki docbook i parsera oraz generatora Qt XML DOM. */

#include <QTextStream>
#include <docbookdoc.h>

class ZenFlesh : public DocbookDoc {
    public: ZenFlesh();
};

ZenFlesh::ZenFlesh() : 
    DocbookDoc("Zen z krwi i kości") {

    chapter("101 opowieści zen");
    section("Filiżanka herbaty");
    para("Nan-in zaproponował mu herbatę.");
    section("Wspaniałe fale");
    QDomElement p = para("O-nami usiadł, by rozpocząć medytację. "
            "Próbował wyobrazić sobie siebie jako morskie fale.");
    setRole(p, "remark");
    chapter("Bezbramna brama");
    formalpara("Bezbramna brama",
      "By przejść przez bezbramną bramę, musisz mieć");
    bold(" bezmyślny umysł.");

    section("Pies Joshu");
    para("Czy pies ma naturę Buddy, czy nie?");

    section("Lis Haykujo");
    QDomElement fp = formalpara("To wyjątkowy temat", 
       "Który powinien mieć atrybut role= remark");
    setRole(fp, "remark");
}

int main() {
   QTextStream cout(stdout);
   ZenFlesh book;
   cout << book << endl;
}

