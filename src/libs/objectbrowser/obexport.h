#ifndef OBJECTBROWSER_EXPORT
#include <QtGlobal>

/* To makro służy do budowania bibliotek DLL w systemie Windows. */
#ifndef Q_OS_WIN
#define OBJECTBROWSER_EXPORT
#elif defined(OBJECTBROWSER_DLL)
#define OBJECTBROWSER_EXPORT Q_DECL_EXPORT
#else
#define OBJECTBROWSER_EXPORT Q_DECL_IMPORT
#endif


#endif        //  #ifndef OBEXPORT_H

