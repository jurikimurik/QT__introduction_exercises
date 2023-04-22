#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), 
                                 ui(new Ui::MainWindow), m_expInterval(0),
                              m_randStr(), m_trials(0), m_correctChars(0),
                                     m_totTrials(0), m_totCorrectChars(0) {

    //initialize ui
    ui->setupUi(this);
    ui->displayLabel->hide();
    ui->responseLabel->hide();
    ui->nextButton->hide();
    m_randStr.setStringLength(5);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::changeEvent(QEvent* e) {
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_exposureSlider_valueChanged(int value) {
    ui->exposureLCD->display(value); 
    m_expInterval = value;
}

void MainWindow::on_lengthSlider_valueChanged(int value) {
    ui->lengthLCD->display(value);
    m_randStr.setStringLength(value);
}

void MainWindow::on_startButton_clicked() {
    //ukryj przycisk start
    ui->startButton->hide();

    //pokaż panel gry
    ui->displayLabel->show();
    ui->targetString->show();
    ui->responseLabel->show();
    ui->responseString->show();
    ui->nextButton->show();

    //wyłącz ustawienia
    ui->groupBox->setEnabled(false);

    m_trials = 0;

    //inicjalizuj system oceniania
    m_correctChars = 0;

    // rozpocznij próby
    processTrial();
}

//start
void MainWindow::processTrial() {
    //wyczyść pole odpowiedzi
    ui->responseString->setText("");
    //wyświetl losowy łańcuch znaków
    ui->targetString->setText(m_randStr.generateString());
    ui->responseString->setEnabled(false);
    ui->nextButton->setEnabled(false);
    //zliczaj liczbę prób
    m_trials++;
    m_totTrials++;
    ui->nextButton->setText(QString("String %1").arg(m_trials));
    //rozpocznij wyświetlanie
    QTimer::singleShot(m_expInterval, this, SLOT(timerDisplayRandStr()));
}


void MainWindow::timerDisplayRandStr() {
    ui->targetString->setText(QString(""));
    //włącz edycję odpowiedzi i przycisk następny
    ui->responseString->setEnabled(true);
    ui->responseString->setFocus();
    ui->nextButton->setEnabled(true);
}

//end

void MainWindow::on_responseString_returnPressed() {
    on_nextButton_clicked();  //Wciśnięcie enter ma ten sam efekt, co kliknięcie przycisku następny.
}


void MainWindow::on_nextButton_clicked() {
    int goodChars(m_randStr.numCorrectChars(ui->responseString->text()));
    int lenTarget(ui->lengthLCD->value());
    m_correctChars += goodChars;
    m_totCorrectChars += goodChars;
    ui->correctCharFraction->setText(QString("%1 / %2").arg(m_correctChars).arg(lenTarget * m_trials));
    ui->cumulativeFraction->setText(QString("%1 / %2").arg(m_totCorrectChars).arg(lenTarget * m_totTrials));

    if(m_trials == ui->trialsSpinBox->value()) {
        //ukryj panel gry
        ui->startButton->show();
        //pokaż przycisk start
        ui->displayLabel->hide();
        ui->targetString->hide();
        ui->responseLabel->hide();
        ui->responseString->hide();
        ui->nextButton->hide();
        //Włącz ustawienia
        ui->groupBox->setEnabled(true);
    }
    else
        processTrial();
}


