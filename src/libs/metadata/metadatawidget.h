#ifndef METADATAWIDGET_H
#define METADATAWIDGET_H


#include <QList>
#include <QWidget>
#include "metadataobject.h"

class QButtonGroup;
class QDataWidgetMapper;

#include "ui_metadatawidget.h"
#include "metadataexport.h"

/** Widżet umożliwiający wyświetlanie i edycję wartości MetaDataObject.
    TODO: Sprawić, by zadziałał z QDataWidgetMapper?
*/
class METADATAEXPORT MetaDataWidget : public QWidget, private Ui::MetaDataWidget {
    Q_OBJECT
public:
    MetaDataWidget(QWidget* parent=0);

    /** Ładuje dane z obiektu do widżetu */

    void clear();
    MetaDataObject* model() const;

public slots:
    void processButton ( QAbstractButton * button );
    void display(const MetaDataValue& mdv);
    void submit();
    void revert();

private:
    MetaDataObject* m_model;
    QDataWidgetMapper* m_Mapper;

};

#endif        //  #ifndef METADATAWIDGET_H
