#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "window1.h"
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_pushButton_clicked();  // Button für das Öffnen von window1
    void returnToStartWindow2();
private:
    Ui::MainWindow *ui;
    window1 *m_window1;  // Zeiger auf das zweite Fenster
};
#endif // MAINWINDOW_H
