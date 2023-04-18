#ifndef CUSTOMER_EXPORT

#include <QtGlobal>

/** Definicja makra eksportującego symbole do DLL w systemie Windows */

#ifndef Q_OS_WIN
#define CUSTOMER_EXPORT
#elif defined(CUSTOMER_DLL)
#define CUSTOMER_EXPORT Q_DECL_EXPORT
#else
#define CUSTOMER_EXPORT Q_DECL_IMPORT
#endif


#endif        //  #ifndef CUSTOMER_EXPORT

