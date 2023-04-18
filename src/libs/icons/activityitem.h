#ifndef ACTIVITYITEM_H
#define ACTIVITYITEM_H
#include "icons_export.h"
#include <QObject>
#include <QStandardItem>

/** QStandardItem z kręcącymi się aktywnościami */
class ICONS_EXPORT ActivityItem : public QObject, public QStandardItem {
    Q_OBJECT
public:
    ActivityItem(QString text);
    /** @return true jeśli ikonka się kręci */
    bool isActive() const;  
public slots:
    /** @param isActive jeśli true, zacznij kręcić ikonką */
    void setActive(bool isActive=true);
protected slots:
    void updateIcon();
private:
    bool m_isActive;
};


#include <QTreeView>
/** A test view for ActivityIcon */
class ICONS_EXPORT ActivityView: public QTreeView {
 Q_OBJECT
public:
    ActivityView(QObject* parent =0);
public slots:
    void itemClicked(QModelIndex);

};


#endif        //  #ifndef ACTIVITYITEM_H
