#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
    , m_MainWindow(nullptr)
    , m_MainWindowPulseGenerator(nullptr)
{
    ui->setupUi(this);
    ui->B_PulseGenerator->setProperty("class", "titleButton");
    ui->B_idealSpectra->setProperty("class", "titleButton");
}

StartWindow::~StartWindow()
{
    delete ui;
    if (m_MainWindow) {
        delete m_MainWindow;  // Freigeben, wenn das zweite Fenster existiert
    }
}


void StartWindow::on_B_idealSpectra_clicked()
{
    // Erstelle und zeige das Programmfenster (window1)
    if (!m_MainWindow) {
        m_MainWindow = new MainWindow(this);
    }
    m_MainWindow->show();  // Zeige das Fenster
    this->hide();  // Verstecke das Startfenster, wenn das Programmfenster angezeigt wird

}


void StartWindow::on_B_PulseGenerator_clicked()
{
    // Erstelle und zeige das Programmfenster (window1)
    if (!m_MainWindowPulseGenerator) {
        m_MainWindowPulseGenerator = new MainWindowPulseGenerator(this);
    }
    m_MainWindowPulseGenerator->show();  // Zeige das Fenster
    this->hide();  // Verstecke das Startfenster, wenn das Programmfenster angezeigt wird
}

