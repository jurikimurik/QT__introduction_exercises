#include "randomcollagecreator.h"

#include <QDebug>
#include <QDir>

RandomCollageCreator::RandomCollageCreator(int width, int height, const QString &inputFolder, const QString &outputFolder) : m_width(width),
    m_height(height),
    m_inputFolder(inputFolder),
    m_outputFolder(outputFolder)
{}

void RandomCollageCreator::generateImage()
{
    m_isReady = false;
    loadImages();
    transformImagesRandomly();
    createOutputImage();
    saveToFile();
}

void RandomCollageCreator::loadImages()
{
    QDir directory(m_inputFolder);
    directory.setFilter(QDir::Files);
    QFileInfoList list = directory.entryInfoList();
    QVector<QString> filesPathes;
    for(const QFileInfo &info : list)
    {
        if(IMAGE_FORMATS.contains(info.suffix().toLower()))
            filesPathes << info.absoluteFilePath();
    }

    for(const QString& filePath : filesPathes)
    {
        QImage image(filePath);
        m_images << image;
    }
}

void RandomCollageCreator::transformImagesRandomly()
{

}

void RandomCollageCreator::createOutputImage()
{

}

void RandomCollageCreator::saveToFile()
{
    m_isReady = true;
}

bool RandomCollageCreator::isReady() const
{
    return m_isReady;
}
