#ifndef MAINWINDOWPULSEGENERATOR_H
#define MAINWINDOWPULSEGENERATOR_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindowPulseGenerator;
}

class MainWindowPulseGenerator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowPulseGenerator(QWidget *parent = nullptr);
    ~MainWindowPulseGenerator();


    // Helper-Funktion, um QLineEdit in double zu konvertieren mit Fehlerbehandlung
    double safeDoubleFromLineEdit(QLineEdit* lineEdit, double defaultValue = 0.0);

    int safeIntFromLineEdit(QLineEdit* lineEdit, int defaultValue = 0);


private slots:
    void on_pushButton_clicked();
    void returnToStartWindow();  // Methode für den Menüeintrag "Zurück zum Start"


private:
    Ui::MainWindowPulseGenerator *ui;
};

#endif // MAINWINDOWPULSEGENERATOR_H
