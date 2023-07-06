#include "randomcollagecreator.h"

#define DEBUG 0

#if DEBUG == 1
#include <QDebug>
#endif

#include <QDir>
#include <QPainter>

RandomCollageCreator::RandomCollageCreator(int width, int height, const QString &inputFolder, const QString &outputFolder) : m_width(width),
    m_height(height),
    m_inputFolder(inputFolder),
    m_outputFolder(outputFolder),
    m_engine(QTime::currentTime().msec())
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

#if DEBUG == 1
    for(const QString& filePath: filesPathes)
    {
        qDebug() << filePath;
    }
#endif

}

void RandomCollageCreator::transformImagesRandomly()
{
    for(const QImage& image : m_images)
    {
        moreCopies(image, std::uniform_int_distribution(0, 10)(m_engine));
    }

    for(QImage& image : m_images)
    {
        transformRandomly(image);
    }
}

void RandomCollageCreator::createOutputImage()
{
    QImage finalImage(m_width, m_height, QImage::Format_RGB32);
    finalImage.fill(0);
    QPainter painter(&finalImage);
    for(const QImage& image : m_images)
    {
        painter.drawImage(getRandomSizeAndPosition(), image);
    }

    m_finalOutput = finalImage;
}

void RandomCollageCreator::saveToFile()
{
    m_finalOutput.save(m_outputFolder+"super-image.png");
    m_isReady = true;
}

void RandomCollageCreator::moreCopies(const QImage &image, int numberOfCopies)
{
    while(numberOfCopies-- > 0)
    {
        m_images << image;
    }
}

void RandomCollageCreator::transformRandomly(QImage &image)
{
    std::uniform_int_distribution dist(0, 1);
    //Inverting pixels
    if(dist(m_engine))
        image.invertPixels();

    //Mirroring
    if(dist(m_engine))
        image.mirror(dist(m_engine), dist(m_engine));

    //Rgb swapping (from RGB to BGR)
    if(dist(m_engine))
        image.rgbSwap();

    //Color changing
    if(dist(m_engine))
    {
        std::uniform_int_distribution colorDist(0, 256);
        int repeat = colorDist(m_engine);

        for(int i = 0; i < repeat; ++i)
        {
            int r = colorDist(m_engine);
            int g = colorDist(m_engine);
            int b = colorDist(m_engine);
            image.setPixel(std::uniform_int_distribution(0, image.width()-1)(m_engine),
                           std::uniform_int_distribution(0, image.height()-1)(m_engine), qRgb(r, g, b));
        }
    }

}

QRect RandomCollageCreator::getRandomSizeAndPosition()
{
    std::uniform_int_distribution xRand(0, m_width);
    std::uniform_int_distribution yRand(0, m_height);
    return QRect(xRand(m_engine), yRand(m_engine), xRand(m_engine), yRand(m_engine));
}

bool RandomCollageCreator::isReady() const
{
    return m_isReady;
}
