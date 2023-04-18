#ifndef METADATALOADERPROGRESSWIDGET_H
#define METADATALOADERPROGRESSWIDGET_H

#include "metadataexport.h"
#include <QWidget>
#include <metadatavalue.h>

class QToolButton;
class QProgressBar;
namespace Abstract {
    class MetaDataLoader;
}

/** Przycisk Anuluj i widżet postępu podłączone do MetaDataLoader.
        TODO: wykorzystaj interfejs Abstract i przenieś do biblioteki MetaData.
*/

class METADATAEXPORT MetaDataLoaderProgressWidget : public QWidget
{
    Q_OBJECT
public:
    /** @param loader jeśli 0, użyje Abstract::MetaDataLoader::instance() */
    
    explicit MetaDataLoaderProgressWidget(Abstract::MetaDataLoader* loader = 0, 
                                         QWidget* parent = 0);
    
    /** Podłącz inny MetaDataLoader do tych samych widżetów */
    void hookup (Abstract::MetaDataLoader* mdl);
    QProgressBar* progressBar() {return m_progressBar;}
    QToolButton* cancelButton() {return m_cancelButton;}
signals:

public slots:
    void updateStatus(const MetaDataValue& mdv);
    void updateRange(int min, int max) ;
private:
    MetaDataValue lastValue;
    QProgressBar* m_progressBar;
    QToolButton* m_cancelButton;
};

#endif // METADATALOADERPROGRESSWIDGET_H
