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
        cout << match.captured(0) << endl;
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

    //https://medium.com/analytics-vidhya/coding-the-impossible-palindrome-detector-with-a-regular-expressions-cd76bc23b89b (Tony Tonev)
    QRegularExpression exp_d(R"(\b(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*(?:(\w)[ \t,'"]*\11?[ \t,'"]*\10|\10?)[ \t,'"]*\9|\9?)[ \t,'"]*\8|\8?)[ \t,'"]*\7|\7?)[ \t,'"]*\6|\6?)[ \t,'"]*\5|\5?)[ \t,'"]*\4|\4?)[ \t,'"]*\3|\3?)[ \t,'"]*\2|\2?))?[ \t,'"]*\1\b)");
    wypiszDopasowania(exp_d, data);

    // MODIFIED: https://stackoverflow.com/questions/14343273/regex-for-words-containing-letters-in-alphabetic-order-java
    QRegularExpression exp_e(R"(\b(a*b*c*...z*)\n)");
    wypiszDopasowania(exp_e, data);
}
