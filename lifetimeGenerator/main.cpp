#include "startwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("://Icon256.ico"));
    a.setStyleSheet(
    /* Allgemeines Stylesheet */
        "QWidget {"
        "    background-color: #2F2F2F;"   /* Helleres Dunkelgrau als Hintergrund */
        "    color: #E0E0E0;"              /* Heller Text für besseren Kontrast */
        "    font-family: Arial, sans-serif;"
        "    font-size: 14px;"
        "}"

        "QPushButton {"
        "    background-color: #3A3A3A;"   /* Dunklerer Grau für den Button */
        "    color: #E0E0E0;"
        "    border-radius: 8px;"          /* Leicht abgerundete Ecken */
        "    border: 1px solid #4CAF50;"   /* Grüner Rahmen für Akzent */
        "    padding: 8px 16px;"
        "    font-size: 14px;"
        "    font-weight: bold;"
        "}"
        /* Labels mit der Property 'class' = 'title' */
        "QPushButton[class='titleButton'] {"
        "    background-color: #3A3A3A;"   /* Dunklerer Grau für den Button */
        "    color: #E0E0E0;"
        "    border-radius: 15px;"          /* Leicht abgerundete Ecken */
        "    border: 3px solid #4CAF50;"   /* Grüner Rahmen für Akzent */
        "    padding: 8px 16px;"
        "    font-size: 25px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #4CAF50;"   /* Grüne Akzentfarbe beim Hover */
        "    color: white;"                /* Weißer Text bei Hover */
        "}"

        "QPushButton:pressed {"
        "    background-color: #388E3C;"   /* Dunkleres Grün, wenn gedrückt */
        "}"

        "QLabel {"
        "    font-size: 14px;"
        "    font-weight: normal;"
        "    color: #E0E0E0;"             /* Heller Text */
        "}"
        /* Labels mit der Property 'class' = 'title' */
        "QLabel[class='title'] {"
        "    font-size: 24px;"       /* Größerer Text für Überschrift */
        "    font-weight: bold;"     /* Fettschrift */
        "    text-transform: uppercase;"  /* Großschreibung für den Text */
        "    color: #FFFFFF;"        /* Weißer Text */
        "}"
        "QLineEdit {"
        "    border: 2px solid #4CAF50;"   /* Grüner Rand */
        "    border-radius: 8px;"
        "    padding: 6px;"
        "    background-color: #3A3A3A;"   /* Dunkelgrauer Hintergrund */
        "    font-size: 14px;"
        "    color: #E0E0E0;"             /* Heller Text */
        "}"

        "QLineEdit:focus {"
        "    border: 2px solid #81C784;"   /* Hellgrüner Rand beim Fokussieren */
        "}"

        "QComboBox {"
        "    border: 2px solid #4CAF50;"   /* Grüner Rand */
        "    border-radius: 8px;"
        "    padding: 6px;"
        "    background-color: #3A3A3A;"   /* Dunkelgrauer Hintergrund */
        "    font-size: 14px;"
        "    color: #E0E0E0;"              /* Heller Text */
        "}"

        "QComboBox::drop-down {"
        "    border: none;"
        "    background-color: #4CAF50;"
        "    width: 30px;"
        "}"

        "QComboBox::down-arrow {"
        "    image: url(:/icons/down-arrow.png);"  /* Stelle sicher, dass du ein Icon im Ressourcenpfad hast */
        "    width: 14px;"
        "    height: 14px;"
        "}"

        "QProgressBar {"
        "    border: 2px solid #4CAF50;"
        "    border-radius: 8px;"
        "    text-align: center;"
        "    color: white;"
        "    background-color: #2F2F2F;"   /* Gleicher Hintergrund wie das Fenster */
        "}"

        "QProgressBar::chunk {"
        "    background-color: #4CAF50;"
        "    border-radius: 8px;"
        "}"

        "QScrollBar:vertical {"
        "    border: 1px solid #4CAF50;"
        "    background-color: #2F2F2F;"
        "    width: 16px;"
        "    margin: 22px 0 22px 0;"
        "    border-radius: 8px;"
        "}"

        "QScrollBar::handle:vertical {"
        "    background-color: #4CAF50;"
        "    min-height: 20px;"
        "    border-radius: 8px;"
        "}"

        "QScrollBar:horizontal {"
        "    border: 1px solid #4CAF50;"
        "    background-color: #2F2F2F;"
        "    height: 16px;"
        "    margin: 0px 22px 0 22px;"
        "    border-radius: 8px;"
        "}"

        "QScrollBar::handle:horizontal {"
        "    background-color: #4CAF50;"
        "    min-width: 20px;"
        "    border-radius: 8px;"
        "}"

        "QMenuBar {"
        "    background-color: #3A3A3A;"
        "    color: #E0E0E0;"
        "}"

        "QMenuBar::item {"
        "    background-color: #3A3A3A;"
        "    padding: 6px 12px;"
        "    color: #E0E0E0;"
        "}"

        "QMenuBar::item:selected {"
        "    background-color: #4CAF50;"
        "}"

        "QMenu {"
        "    background-color: #2F2F2F;"
        "    border: 1px solid #4CAF50;"
        "    padding: 8px;"
        "    color: #E0E0E0;"
        "}"

        "QMenu::item:selected {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "}"

        "QTabBar::tab {"
        "    background-color: #3A3A3A;"
        "    color: #E0E0E0;"
        "    padding: 8px;"
        "    border: 1px solid #4CAF50;"
        "    border-bottom: none;"
        "    border-radius: 8px 8px 0 0;"
        "}"

        "QTabBar::tab:selected {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "}"

        "QCheckBox {"
        "    color: #E0E0E0;"
        "    font-size: 14px;"
        "}"

        "QCheckBox::indicator {"
        "    width: 16px;"
        "    height: 16px;"
        "}"

        "QCheckBox::indicator:unchecked {"
        "    border: 1px solid #4CAF50;"
        "    background-color: #3A3A3A;"
        "    border-radius: 4px;"
        "}"

        "QCheckBox::indicator:checked {"
        "    background-color: #4CAF50;"
        "    border: 1px solid #388E3C;"
        "    border-radius: 4px;"
        "}"

    );
    StartWindow w;
    w.show();
    return a.exec();
}
