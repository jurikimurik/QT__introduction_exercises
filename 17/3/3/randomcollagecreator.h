#ifndef RANDOMCOLLAGECREATOR_H
#define RANDOMCOLLAGECREATOR_H

#include <QString>



class RandomCollageCreator
{
public:
    RandomCollageCreator(int width, int height, const QString &inputFolder, const QString &outputFolder);
    void generateImage();
private:
    int m_width;
    int m_height;
    QString m_inputFolder;
    QString m_outputFolder;
};

#endif // RANDOMCOLLAGECREATOR_H
