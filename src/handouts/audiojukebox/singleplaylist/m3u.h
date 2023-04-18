#ifndef M3UREADER_H
#define M3UREADER_H

#include <QStringList>
#include <QString>
class QAbstractItemModel;
class PlayListModel;
#include "metadatavalue.h"
#include <QItemSelectionModel>

/** Klasa do zapisu i odczytu list odtwarzania z rozszerzeniem .m3u */

class M3u {
public:
    /** @return liczba elementów na liście odtwarzania
    */
    int readFrom(QString fileName, PlayListModel* destination);
    static QMap<QString, int> headerIndexes(const QAbstractItemModel* m);

    /** @return reprezentacja m3u f, z #extinf */
    static QString m3u(const MetaDataValue& f, QString playListDir = QString());

    void writeTo(const QModelIndexList &qmil, QString fileName) const;

    void writeTo(const QAbstractItemModel* source, QString fileName) const ;
    /** @param source - model zawierający listę odtwarzania do zapisu
        @param playListDir - jeśli podano, zapisuje ścieżki względne do katalogu z listami odtwarzania
    */
    static QStringList toStringList(const QAbstractItemModel* source, QString playListDir = QString());

    static QString toString(const QModelIndex& idx, QMap<QString, int> idxes, QString playListDir) ;

    int readFrom(QStringList lines, PlayListModel* destination, QString playListDir = QString());
};


#endif        //  #ifndef M3UREADER_H

