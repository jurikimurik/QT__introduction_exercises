#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QRegularExpression>
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

void wypiszDopasowania(QRegularExpression exp, QString from)
{
    cout << "Dla wyrazenia regularnego " << exp.pattern() << " wyniki sa nastepujace: ";
    auto matches = exp.globalMatch(from);
    while(matches.hasNext()) {
        auto match = matches.next();
        cout << match.captured(0);
    }
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QString path = QFileDialog::getOpenFileName();
    QFile plik(path);

    if(!plik.open(QIODevice::ReadOnly)) {
        qDebug() << "NIE UDALO SIE OTWORZYC PLIKU: " << path;
        return EXIT_FAILURE;
    }

    QTextStream reader(&plik);
    QString data = reader.readAll();

    QRegularExpression exp_a(R"(\b(.)\1\w+\n)");
    wypiszDopasowania(exp_a, data);

    QRegularExpression exp_b(R"(\b.*[A-Z]\n)");
    wypiszDopasowania(exp_b, data);

    QRegularExpression exp_c(R"(\b\w*(.)\1\w*(.)\2\w*\n)");
    wypiszDopasowania(exp_c, data);
}
