#ifndef ACTIONEDITOR_EXPORT
/** To makro służy do budowania bibliotek DLLs w systemie Windows.

	Makra poniżej sprawiają, że ACTIONEDITOR_EXPORT będzie mieć właściwą wartość
	w zależności od przypadku użycia (załączenie przez aplikację lub
	budowanie DLL). W systemach innych niż Windows nie wpłynie to na zachowanie programu.
	*/
	
#include <QtGlobal>
#ifndef Q_WS_WIN
#define ACTIONEDITOR_EXPORT
#elif defined(ACTIONEDITOR_DLL)
#define ACTIONEDITOR_EXPORT Q_DECL_EXPORT
#else
#define ACTIONEDITOR_EXPORT Q_DECL_IMPORT
#endif

#endif        //  #ifndef MYEXPORT_H

