
#ifndef STARRATING_H
#define STARRATING_H

#include <QMetaType>
#include <QPointF>
#include <QVector>
#include <QPolygonF>
#include <QPainter>

/* Oparte na przykładach z dystrybucji Qt */
class StarRating {
public:
    enum EditMode { Editable, ReadOnly };

    /** Definiuje konstruktor konwertujący z int do StarRating(int, 5) */
    StarRating(int starCount = 1, int maxStarCount = 5);

    void paint(QPainter* painter, const QRect& rect,
               const QPalette& palette, EditMode mode) const;
    QSize sizeHint() const;
    int starCount() const { return m_stars; }
    int maxStarCount() const { return m_maxStars; }
    void setStarCount(int starCount) { m_stars = starCount; }
    void setMaxStarCount(int maxStarCount) { m_maxStars = maxStarCount; }

private:
    QPolygonF m_starPolygon;
    QPolygonF m_diamondPolygon;
    int m_stars;
    int m_maxStars;
};

inline bool operator<(const StarRating& l, const StarRating& r) {
    return l.starCount() < r.starCount();
}

// 
/** Dodaje do systemu typów QVariant
	Nie zapomnij zarejestrować qRegisterMetaType<StarRating>("StarRating") w programie
    przed pierwszym użyciem. */
Q_DECLARE_METATYPE(StarRating)

#endif

