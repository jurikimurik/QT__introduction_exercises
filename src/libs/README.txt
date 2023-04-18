Biblioteki kompilują się w 5.1.1.
Większość klas wymaga co najmniej Qt 4.6.

UWAGA: musisz zdefiniować zmienną środowiskową wskazującą ten katalog:

export CPPLIBS=path/for/built/libs    # bash
set CPPLIBS=X:\path\for\built\libs    # win32 cmd

Jeśli nie chcesz budować niektórych katalogów, możesz
oznaczyć je komentarzem lub usunąć z plików libs.pro i tests/tests.pro

filetagger i mobilitymetadata to alternatywy dla
phononmetadata. potrzebujesz tylko jednej z nich.

Do zbudowania i korzystania z mobilitymetadata lub filetagger 
potrzebujesz dodatkowych bibliotek,
wymienionych i omówionych w plikach README w każdym z katalogów.

filetagger wymaga taglib 1.6.3.
mobilitymetadata wymaga Qt Mobility 1.1.1

Jeśli chcesz zbudować projekty związane z taglib, 
ustaw poniższą zmienną środowiskową przed wywołaniem qmake:

export USE_TAGLIB=true   # linux
set USE_TAGLIB=true      # windows

Dlaczego aż 3 wersje metadataloader?

Pod linuksem wszystkie działają świetnie. Phonon nie sprawia problemów.
Pod windows tylko taglib poprawnie pobierze dane plików MP3, stąd takie zróżnicowanie.
Pod Symbianen najlepiej działa mobilitymetadata. 

