#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QRegularExpression>
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

void wypiszDopasowania(QRegularExpression exp, QString from, int which_one = 1)
{
    cout << "Dla wyrazenia regularnego " << exp.pattern() << " wyniki sa nastepujace: ";
    auto matches = exp.globalMatch(from);
    while(matches.hasNext()) {
        auto match = matches.next();
        cout << match.captured(which_one) << endl;
    }
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QString path = QFileDialog::getOpenFileName(nullptr, "Open HTML", "~/", "HTML files (*.html)");
    QFile plik(path);

    if(!plik.open(QIODevice::ReadOnly)) {
        qDebug() << "NIE UDALO SIE OTWORZYC PLIKU: " << path;
        return EXIT_FAILURE;
    }

    QTextStream reader(&plik);
    QString data = reader.readAll();
    qDebug() << data;

    QRegularExpression link(R"(<a\s+(?:[^>]*?\s+)?href=(["'])(.*?)\1)");
    wypiszDopasowania(link, data, 2);

    QRegularExpression label(R"(>(\w*)<\/a>)");
    wypiszDopasowania(label, data, 1);

}
