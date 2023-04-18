Aby skorzystać z narzędzia ModelTest, wykonaj następujące kroki:

1)	Załącz plik pri na końcu Twojego pliku projektu pro przy użyciu polecenia include():

include(../sciezka/do/katalogu/modeltest.pri)

2)	Następnie w pliku źródłowym załącz "modeltest.sh" i utwórz instancję ModelTest z Twoim modelem. Dzięki temu test będzie działał tak samo długo jak Twój model.
Na przykład:

#include <modeltest.h>

QDirModel *model = new QDirModel(this);
new ModelTest(model, this);

3)	To wszystko. Kiedy test natknie się na problem, użyje asercji. Plik modeltest.cpp zawiera nieco wskazówek na temat naprawiania problemów zgłoszonych przez narzędzie testujące.
