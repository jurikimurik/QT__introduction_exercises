#include <QApplication>
#include <QTreeView>
#include <QSplitter>
#include <QTextStream>
#include <cstdio>
#include "slacker.h"
#include "xmltreemodel.h"
#include <QApplication>
QTextStream cout(stdout);

QWidget* twinview(QDomNode before, QDomNode after) {

    QSplitter* hbox = new QSplitter();

    XmlTreeModel* dtm1 = new XmlTreeModel(hbox);
    XmlTreeModel* dtm2 = new XmlTreeModel(hbox);
    dtm1->setContent(before);
    dtm2->setContent(after);
    QTreeView* tv1 = new QTreeView(hbox);
    tv1->setWhatsThis("Przed");
    tv1->setModel(dtm1);
    QTreeView* tv2 = new QTreeView(hbox);
    tv2->setModel(dtm2);
    tv2->setWhatsThis("Po");
    return hbox;
}

//start
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QString filename;
    if (argc < 2) {
        cout << "Użycie: " << argv[0] << " filename.xml" << endl;
        filename = "samplefile.xml";
    }
    else {
        filename = argv[1];
    }
    QFile f(filename);
    QString errorMsg;
    int errorLine, errorColumn;
    QDomDocument doc("SlackerDoc");
    bool result = doc.setContent(&f, &errorMsg, 
         &errorLine, &errorColumn);             /* Sparsuj plik do postaci drzewa DOM i zapisz drzewo w pustym dokumencie doc. */
    QDomNode before = doc.cloneNode(true);      /* Głęboka kopia. */
    Slacker slack(doc);                         /* Wstaw drzewo do slack. */
    QDomNode after = slack.transform();         /* Rozpocznij odwiedzanie. */
    cout << QString("Before: ") << before << endl;
    cout << QString("After: ") << after << endl;
    QWidget * view = twinview(before, after);   /* Stwórz parę obiektów QTreeView oddzielonych suwakiem, 
		za model przyjmując dokumenty QDomDocuments. */
    view->show();
    app.exec();
    delete view;
}
//end



