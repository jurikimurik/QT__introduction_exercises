#ifndef TIMEDISPLAY_H
#define TIMEDISPLAY_H

#include "metadataexport.h"
#include <QTimeEdit>

/** QTimeEdit tylko do odczytu, wyświetlający długość nagrania */
class METADATAEXPORT TimeDisplay : public QTimeEdit {
	Q_OBJECT
public:
        TimeDisplay(QWidget* parent=0);
};

#endif        //  #ifndef TIMEDISPLAY_H

