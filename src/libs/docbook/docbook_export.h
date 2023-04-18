#ifndef DOCBOOK_EXPORT_H
#define DOCBOOK_EXPORT_H


#include <qglobal.h>
/* To makro służy do budowania bibliotek DLL w systemie Windows. */

#ifndef Q_OS_WIN
#define DOCBOOK_EXPORT
#elif defined(DOCBOOK_DLL)
#define DOCBOOK_EXPORT Q_DECL_EXPORT
#else
#define DOCBOOK_EXPORT Q_DECL_IMPORT
#endif


#endif        //  #ifndef DOCBOOK_EXPORT_H

