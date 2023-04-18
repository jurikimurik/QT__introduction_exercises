#include "shapes.h"
#include <math.h>
    double Circle::area() {
        return(M_PI * m_Radius * m_Radius); /* Stała M_PI pochodzi z pliku <math.h> 
					wchodzącego w skład biblioteki standardowej. */
    }

    double Rectangle::area() {
        return (m_Height * m_Width);
    }

    double Square::area() {
        return (Rectangle::area());         /* Wywołanie wersji bazowej. */
    }
//end

    QString Circle::getName() {
        return (" KOŁO ");
    }
    QString Circle::getDimensions(){
        return QString(" Promień = %1 ").arg(m_Radius);
    }

    QString Rectangle::getName() {
        return (" PROSTOKĄT ");
    }
    QString Rectangle::getDimensions() {
        return QString(" Wysokość = %1 Szerokość = %2 ").
               arg(m_Height).arg(m_Width);
    }
    QString Square::getName() {
        return (" KWADRAT ");
    }
    QString Square::getDimensions() {
        return QString(" Wysokość = %1  ").arg(m_Height);
    }



