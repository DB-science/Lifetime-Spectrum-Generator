/********************************************************************************
** Form generated from reading UI file 'window1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW1_H
#define UI_WINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window1
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *chartPlaceholder;
    QPushButton *saveButton;

    void setupUi(QDialog *window1)
    {
        if (window1->objectName().isEmpty())
            window1->setObjectName("window1");
        window1->resize(1316, 753);
        verticalLayout = new QVBoxLayout(window1);
        verticalLayout->setObjectName("verticalLayout");
        chartPlaceholder = new QWidget(window1);
        chartPlaceholder->setObjectName("chartPlaceholder");

        verticalLayout->addWidget(chartPlaceholder);

        saveButton = new QPushButton(window1);
        saveButton->setObjectName("saveButton");

        verticalLayout->addWidget(saveButton);


        retranslateUi(window1);

        QMetaObject::connectSlotsByName(window1);
    } // setupUi

    void retranslateUi(QDialog *window1)
    {
        window1->setWindowTitle(QCoreApplication::translate("window1", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("window1", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window1: public Ui_window1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW1_H
