#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "mainwindowpulsegenerator.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class StartWindow;
}
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_B_idealSpectra_clicked();

    void on_B_PulseGenerator_clicked();

private:
    Ui::StartWindow *ui;
    MainWindow *m_MainWindow;
    MainWindowPulseGenerator *m_MainWindowPulseGenerator;
};

#endif // STARTWINDOW_H
