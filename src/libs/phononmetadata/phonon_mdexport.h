#ifndef PHONON_MDEXPORT

#include <QtGlobal>
/* To makro służy do budowania bibliotek DLL w systemie Windows. */
#ifndef Q_OS_WIN
#define PHONON_MDEXPORT
#elif defined(PHONONMETADATA_DLL)
#define PHONON_MDEXPORT Q_DECL_EXPORT
#else
#define PHONON_MDEXPORT Q_DECL_IMPORT
#endif
#endif