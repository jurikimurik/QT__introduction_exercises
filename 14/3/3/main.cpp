#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include "renamemodel.h"
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    RenameModel model(QString(R"(\bm_*(\w+))"), "m_\\1", QFileDialog::getExistingDirectory());
}
