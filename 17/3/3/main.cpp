#include <QApplication>
#include <QMap>
#include "randomcollagecreator.h"
QTextStream cout(stdout);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    int width = -1;
    int height = -1;
    QString input;
    QString output;

    QStringList arguments = app.arguments();
    try {
        for(int i = 0; i < arguments.size(); ++i)
        {
            if(arguments[i] == "-h")
                height = arguments[++i].toInt();

            if(arguments[i] == "-w")
                width = arguments[++i].toInt();

            if(arguments[i] == "-i")
                input = arguments[++i];

            if(arguments[i] == "-o")
                output = arguments[++i];
        }

        if(width == -1 || height == -1 || input.isEmpty() || output.isEmpty())
            throw std::runtime_error("Needed arguments has not been proveided.");
    } catch (...) {
        cout << "Wrong arguments!" << "\n";
        return EXIT_FAILURE;
    }

    RandomCollageCreator creator(width, height, input, output);
    creator.generateImage();
}
