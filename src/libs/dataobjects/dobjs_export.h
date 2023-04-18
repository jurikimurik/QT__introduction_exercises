#include <QtGlobal>
#ifndef DOBJS_EXPORT
/* To makro służy do budowania DLL w systemie Windows. */
#ifndef Q_OS_WIN
#define DOBJS_EXPORT
#elif defined(DATAOBJECTS_DLL)
#define DOBJS_EXPORT Q_DECL_EXPORT
#else
#define DOBJS_EXPORT Q_DECL_IMPORT
#endif
#endif
