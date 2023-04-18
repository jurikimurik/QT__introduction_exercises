#ifndef QOBJECTWRITER_H
#define QOBJECTWRITER_H

#include "dobjs_export.h"
#include <QString>
#include <QStringList>
#include <QObject>
#include <QMap>
#include <QVariant>

/** Prosty sposób dostarczenia dodatkowych "pisarzy" dla konkretnych typów użytkownika */

class DOBJS_EXPORT VariantWriter {
 public:
    /** @return QString() jeśli nie wiesz, jak obsłużyć dany typ */
    virtual QString toString(const QVariant& variant, const QMetaProperty& meta) const = 0;
};

/** Zapisuje właściwośi QObject i obiekty-dzieci w formacie XML,
    który później będzie można wczytać. */
//start
class DOBJS_EXPORT QObjectWriter : public VariantWriter {
 public:
    /** @param vw alternatywny VariantWriter do obsługi typów użytkownika */
    QObjectWriter(const VariantWriter* vw = 0, bool children=true);
    void mapType(QVariant::Type t, VariantWriter* vw);
    virtual QString toString(const QVariant& variant, const QMetaProperty& meta) const;
    virtual QStringList propertyNames(const QObject* obj) const ;
    virtual QString toString(const QObject* obj, int indentLevel = 0) const;
 private:
    const VariantWriter* m_vwriter;
    bool m_children;
    QMap<QVariant::Type, VariantWriter*> m_map;
};
//end
#endif        //  #ifndef QOBJECTWRITER_H
