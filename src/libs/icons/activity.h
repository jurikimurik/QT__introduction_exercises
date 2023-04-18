#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QPushButton>
#include <QIcon>
#include <QMovie>
#include "icons_export.h"
/** @return Singleton QMovie z kręcącą się ikonką aktywności.
    Współdzielony przez ActivityButton i ActivityItem. */
ICONS_EXPORT QMovie* getMovie();

/** @return QIcon dla aktualnej ramki getMovie() */
ICONS_EXPORT QIcon getCurrentIcon();

/** QPushButton, który pokaże kręcącą się ikonkę, jeśli ustawisz setActive(true) */
class ICONS_EXPORT  ActivityButton : public QPushButton {
    Q_OBJECT
public:
    ActivityButton(QString text, QWidget* parent =0);
    /** @return true jeśli ikonka się kręci */
    bool isActive() const;  
public slots:
    /** @param isActive jeśli true, zacznij kręcić ikonką */
    void setActive(bool isActive);
protected slots:
    void updateIcon();
private:
    bool m_isActive;
};

#endif        //  #ifndef ACTIVITY_H
