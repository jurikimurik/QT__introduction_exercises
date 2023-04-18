#include <QtWidgets>
#include "actiontableeditor.h"
#include "qobjectbrowser.h"
#include "application.h"
#include "fileprint.xpm"

ApplicationWindow::ApplicationWindow(QWidget* parent)
    : QMainWindow(parent)
{


    setWindowModified(false);
    setObjectName(qApp->applicationName());
    printer = new QPrinter( QPrinter::HighResolution );

    QAction * fileNewAction;
    QAction * fileOpenAction;
    QAction * fileSaveAction, * fileSaveAsAction, * filePrintAction;
    QAction * fileCloseAction, * fileQuitAction;

    fileNewAction = new QAction( qApp->style()->standardIcon(QStyle::SP_FileDialogNewFolder),
                                 "&Nowy", this);

    fileNewAction->setStatusTip("nowy...");
    fileNewAction->setShortcut(tr("Ctrl+N"));
    connect( fileNewAction, SIGNAL( triggered() ) , this,
             SLOT( newDoc() ) );

    fileOpenAction = new QAction( qApp->style()->standardIcon(QStyle::SP_DirOpenIcon),
                                  "&Otwórz...", this);
    fileOpenAction->setStatusTip("open");
    fileOpenAction->setShortcut(tr("Ctrl+O"));

    connect( fileOpenAction, SIGNAL( triggered() ) , this, SLOT( choose() ) );

    const char * fileOpenText = "<p><img source=\"fileopen\"> "
                     "Wciśnij ten przycisk, by otworzyć <em>nowy plik</em>. <br>"
                     "Możesz również wybrać polecenie <b>Otwórz</b> "
                     "z menu <b>Plik</b>.</p>";

    fileOpenAction->setWhatsThis( fileOpenText );

    fileSaveAction = new QAction( qApp->style()->standardIcon(QStyle::SP_DialogSaveButton),
                                  "Zapisz", this);
    fileSaveAction->setShortcut(tr("Ctrl+S"));
    fileSaveAction->setStatusTip(tr("zapisz plik"));


    connect( fileSaveAction, SIGNAL( triggered() ) , this, SLOT( save() ) );

    const char * fileSaveText = "<p>Wciśnij ten przycisk, by zapisać plik, "
                     "który edytujesz. Zostaniesz poproszony o podanie nazwy.\n"
                     "Może także wybrać polecenie <b>Zapisz</b> z "
                     "menu <b>Plik</b>.</p>";
    fileSaveAction->setWhatsThis( fileSaveText );

    fileSaveAsAction = new QAction( qApp->style()->standardIcon(QStyle::SP_DialogSaveButton),
                                    "Zapisz j&ako...", this);
    fileSaveAsAction->setStatusTip("Zapisz plik jako");

    connect( fileSaveAsAction, SIGNAL( triggered() ) , this,
             SLOT( saveAs() ) );
    fileSaveAsAction->setWhatsThis( fileSaveText );

    filePrintAction = new QAction( QIcon(QPixmap(fileprint)), "Drukuj...", this);
    filePrintAction->setShortcut(tr("Ctrl+p"));

    connect( filePrintAction, SIGNAL( triggered() ) , this,
             SLOT( print() ) );

    const char * filePrintText = "Wciśniej ten przycisk, by wydrukować plik, "
                     "który edytujesz.\n Możesz również wybrać polecenie Drukuj "
                     "z menu Plik.";
    filePrintAction->setWhatsThis( filePrintText );

    fileCloseAction = new QAction( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon), "&Zamknij", this);
    fileCloseAction->setShortcut(tr("Ctrl+W"));
    fileCloseAction->setStatusTip("Zamknij");
    fileCloseAction->setWhatsThis("Zamknij plik");

    connect( fileCloseAction, SIGNAL( triggered() ) , this,
             SLOT( close() ) );

    fileQuitAction = new QAction( qApp->style()->standardIcon(QStyle::SP_DialogCloseButton),"Wyjdź", this);
    fileQuitAction->setShortcut(tr("Ctrl+Q"));
    fileQuitAction->setWhatsThis("wyjdź");
    fileQuitAction->setStatusTip("wyjdź");
    fileQuitAction->setStatusTip(tr("Ctrl+Q"));
    connect( fileQuitAction, SIGNAL( triggered() ) , qApp,
             SLOT( closeAllWindows() ) );

    // dodaj do paska narzędzi popularne akcje

    QToolBar * fileTools = new QToolBar("operacje na plikach" , this);
    fileTools->setWindowTitle("Operacje na plikacj" );
    fileTools->addAction(fileOpenAction);
    fileTools->addAction(fileSaveAction);
    fileTools->addAction(filePrintAction);
    fileTools->addAction(QWhatsThis::createAction(this));

    // dodaj wszystkie akcje do menu

    QMenu* fileMenu = new QMenu("Plik", this);
    menuBar()->addMenu(fileMenu);
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileSaveAction);
    fileMenu->addAction(fileSaveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(filePrintAction);
    fileMenu->addSeparator();
    fileMenu->addAction(fileCloseAction);
    fileMenu->addAction(fileQuitAction);

    menuBar()->addSeparator();

    QMenu *toolsMenu = new QMenu("Narzędzia", this);
    menuBar()->addMenu(toolsMenu);

    QAction *editShortcutsAction = new QAction(tr("&Edycja skrótów"), this);
    editShortcutsAction->setShortcut(tr("Ctrl+Alt+S"));
    connect(editShortcutsAction, SIGNAL(triggered()), this, SLOT(editShortcuts()));
    toolsMenu->addAction(editShortcutsAction);

    QAction *objectBrowserAction = new QAction(tr("Przeglądarka &obiektów"), this);
    connect(objectBrowserAction, SIGNAL(triggered()), this, SLOT(objectBrowser()));
    toolsMenu->addAction(objectBrowserAction);

    // add a help menu

    QMenu * help = new QMenu( "Pomoc", this );
    menuBar()->addMenu(help);

    help->addAction( "O aplikacji", this, SLOT(about()), tr("F1"));
    help->addAction( "O Qt", qApp, SLOT(aboutQt()) );
    help->addSeparator();
    help->addAction( "Co to jest?", this, SLOT(whatsThis()),
                      tr("Shift+F1"));

    // create and define the central widget

    textEdit = new QTextEdit( this);
    connect (textEdit, SIGNAL(textChanged()), this, SLOT(setWindowModified()));
    textEdit->setWindowTitle("edytor" );
    textEdit->setFocus();
    setCentralWidget( textEdit );
    statusBar()->showMessage( "Gotowe", 2000 );
    ActionTableEditor::restoreShortcuts();

    resize( 450, 600 );
}


ApplicationWindow::~ApplicationWindow()
{
    delete printer;
}

void ApplicationWindow::whatsThis() {
    QWhatsThis::enterWhatsThisMode();
}

void ApplicationWindow::objectBrowser() {
    QObjectBrowser *browser=new QObjectBrowser();
    browser->showNormal();
}


void ApplicationWindow::newDoc()
{
    ApplicationWindow *ed = new ApplicationWindow;
    ed->show();
}

void ApplicationWindow::choose()
{
    QString fn = QFileDialog::getOpenFileName(this, "Wybierz plik", QString::null, QString::null);
    if ( !fn.isEmpty() )
	load( fn );
    else
    statusBar()->showMessage( "Anulowano ładowanie", 2000 );
}


void ApplicationWindow::editShortcuts()
{
    ActionTableEditor aed(this);
    aed.exec();
}


void ApplicationWindow::load( const QString &fileName )
{
    QFile f( fileName );
    if ( !f.open( QIODevice::ReadOnly))	return;

    QTextStream ts( &f );
    textEdit->setText( ts.readAll() );
    setWindowFilePath(fileName );
    setWindowModified(false);
    statusBar()->showMessage( "Załadowano dokument " + fileName, 2000 );
}


void ApplicationWindow::save()
{
    if ( filename.isEmpty() ) {
        saveAs();
        return;
    }

    QString text = textEdit->toPlainText();
    QFile f( filename );
    if ( !f.open( QIODevice::WriteOnly ) ) {
        statusBar()->showMessage( QString("Nie udało się zapisać do %1").arg(filename),
			      2000 );
        return;
    }

    QTextStream t( &f );
    t << text;
    f.close();

    setWindowModified( false );
    setWindowFilePath( filename );

    statusBar()->showMessage( QString( "Zapisano plik %1" ).arg( filename ), 2000 );
}


void ApplicationWindow::saveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, "Zapisz plik tekstowy" );
    if ( !fn.isEmpty() ) {
        filename = fn;
        save();
    } else {
        statusBar()->showMessage( "Anulowano zapis", 2000 );
    }
}


void ApplicationWindow::print()
{
    // TODO
}

void ApplicationWindow::closeEvent( QCloseEvent* ce )
{
    if ( !isWindowModified() ) {
        ce->accept();
        return;
    }

    switch( QMessageBox::information( this, qApp->applicationName(),
				      "Dokument zmienił się od ostatniego zapisu ",
				      "Zapisz teraz", "Anuluj", "Wyjdź bez zapisu",
				      0, 1 ) ) {
    case 0:
        save();
        ce->accept();
        break;
    case 1:
    default: // zdroworozsądkowo
        ce->ignore();
        break;
    case 2:
        ce->accept();
        break;
    }
}


void ApplicationWindow::about()
{
    QMessageBox::about( this, qApp->applicationName(),
			"Ten przykład przedstawia proste zastosowanie "
			"QMainWindow,\nQMenuBar i QToolBar.");
}


