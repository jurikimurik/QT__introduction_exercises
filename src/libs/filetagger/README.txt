Podejście alternatywne względem phononmetadata,
działające w systemach windows, mac i linux

Biblioteka wymaga biblioteki taglib 1.6, którą można zbudować pod windows
    i która jest dostępna w większości dystrybucji linuksa i macports/fink:
    http://taglib.github.io/

Instalacja debian/ubuntu/fink:
    apt-get install libtag1-dev libtag1-doc libtag1

Budowanie i instalacja pod windows:
  pobierz i zainstaluj cmake
  Wybierz katalog instalacyjny, którego nazwa nie zawiera spacji.
       Ustaw zmienną środowiskową TAGLIB_DIR, wskazującą ten katalog. 
  Postępuj według instrukcji pod adresem:
        http://www.joelverhagen.com/blog/2010/11/how-to-compile-taglib-on-windows/
  w cmake-gui, po konfiguracji:
        ustaw CMAKE_INSTALL_PREFIX na TAGLIB_DIR
  make
  make install
  copy %TAGLIB_DIR%\lib*.* %CPPLIBS%

Niektóre przykłady mogą przełączać się pomiędzy tą biblioteką a phonon w zależności od tego, 
czy przed wywołaniem qmake ustawiona została zmienna środowiskowa USE_TAGLIB

