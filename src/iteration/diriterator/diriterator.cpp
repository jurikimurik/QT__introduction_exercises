#include <QtCore>
QTextStream cout(stdout);
QTextStream cerr(stderr);

void addMp3File(QString path) {
    cout << path << endl;
}
void usage() {
    cout << "Zastosowanie:   diriterator [ścieżka]" << endl;
    cout << "      wypisuje listę plików mp3, które uda się znaleźć poniżej [ścieżki] lub w aktualnym katalogu." << endl;
}

//start
int main (int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    QDir dir = QDir::current();
    if (app.arguments().size() > 1) {
        dir = app.arguments()[1];
    }
    if (!dir.exists()) {
        cerr << dir.path() << " nie istnieje!" << endl;
        usage(); 
        return -1;
    }
    QDirIterator qdi(dir.absolutePath(),
            QStringList() << "*.mp3",
            QDir::NoSymLinks | QDir::Files,
            QDirIterator::Subdirectories );
    while (qdi.hasNext()) {
        addMp3File(qdi.next());
    }
}
//end
