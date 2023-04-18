#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <QString>
#include <QImage>
#include <functional>

const int imageSize = 100;
//start
/** Funktor, który tylko ładuje obraz */
class Load : public std::unary_function<QString, QImage> {         /* Definiuje wynikowy typ result_type. */
public:
    QImage operator() (const QString& imageFileName) const {
        return QImage(imageFileName);
    }
};

/** Funktor, który tylko skaluje obraz */
class Scale {
    public:
    typedef QImage result_type;                                    /* Cecha wymagana przez obiekty funktory. */
    QImage operator() (QImage image) const {
        for (int i=0; i<10; ++i) {
            QImage copy = image.copy();
            copy.scaled(100, 100, Qt::KeepAspectRatio);
        }
        if (image.width() < image.height()) {
            return image.scaledToHeight(imageSize,
                                        Qt::SmoothTransformation);
        }
        else {
            return image.scaledToWidth(imageSize, 
                                       Qt::SmoothTransformation);
        }
    }
};

/** Pojedynczy funktor ładujący i skalujący */
class LoadAndScale : public std::unary_function<QString, QImage> { /* Również definiuje result_type. */
public:
    Scale scale;
    QImage operator() (const QString& imageFileName) const {
        QImage image(imageFileName);
        return scale(image);
    }
};
//end
#endif // FUNCTORS_H




