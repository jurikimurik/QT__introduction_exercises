#ifndef MOBMETAEXPORT

#include <QtGlobal>
/* To makro służy do budowania bibliotek DLL w systemie Windows. */

#ifndef Q_OS_WIN
#define MOBMETAEXPORT
#elif defined(MOBILITYMETADATA_DLL)
#define MOBMETAEXPORT Q_DECL_EXPORT
#else
#define MOBMETAEXPORT Q_DECL_IMPORT
#endif


#endif        //  #ifndef MOBMETAEXPORT


