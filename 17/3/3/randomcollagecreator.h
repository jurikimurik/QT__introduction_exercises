#ifndef RANDOMCOLLAGECREATOR_H
#define RANDOMCOLLAGECREATOR_H

#include <QImage>
#include <QRect>
#include <QString>
#include <random>

const QStringList IMAGE_FORMATS = {
  "png", "jpg", "jpeg"
};

class RandomCollageCreator
{
public:
    RandomCollageCreator(int width, int height, const QString &inputFolder, const QString &outputFolder);
    void generateImage();

    bool isReady() const;

private:
    void loadImages();
    void transformImagesRandomly();
    void createOutputImage();
    void saveToFile();
private:
    int m_width;
    int m_height;
    QString m_inputFolder;
    QString m_outputFolder;

    QVector<QImage> m_images;
    QImage m_finalOutput;

    bool m_isReady;
};

#endif // RANDOMCOLLAGECREATOR_H
