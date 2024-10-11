/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Window;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *LNumberOfComponents;
    QLabel *label_12;
    QLineEdit *LNumberOfCounts;
    QLabel *label_27;
    QLineEdit *LSpectrumRange;
    QLabel *label_28;
    QLineEdit *LBinning;
    QLabel *label_13;
    QVBoxLayout *verticalLayout;
    QCheckBox *ContiniousLifetime;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *LLifetime1;
    QLabel *label_22;
    QLineEdit *LSigma1;
    QLabel *label_8;
    QLineEdit *LIntensity1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *LLifetime2;
    QLabel *label_23;
    QLineEdit *LSigma2;
    QLabel *label_10;
    QLineEdit *LIntensity2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *LLifetime3;
    QLabel *label_25;
    QLineEdit *LSigma3;
    QLabel *label_7;
    QLineEdit *LIntensity3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *LLifetime4;
    QLabel *label_24;
    QLineEdit *LSigma4;
    QLabel *label_9;
    QLineEdit *LIntensity4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *LLifetime5;
    QLabel *label_26;
    QLineEdit *LSigma5;
    QLabel *label_11;
    QLineEdit *LIntensity5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_15;
    QLineEdit *LFWHM1;
    QLabel *label_16;
    QLineEdit *LFWHM_Intensity1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_17;
    QLineEdit *LFWHM2;
    QLabel *label_18;
    QLineEdit *LFWHM_Intensity2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_19;
    QLineEdit *Lt0_shift;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_21;
    QLineEdit *LBackground;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuBack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(948, 536);
        actionStart_Window = new QAction(MainWindow);
        actionStart_Window->setObjectName("actionStart_Window");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_6->addWidget(label);

        LNumberOfComponents = new QLineEdit(centralwidget);
        LNumberOfComponents->setObjectName("LNumberOfComponents");

        horizontalLayout_6->addWidget(LNumberOfComponents);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        horizontalLayout_6->addWidget(label_12);

        LNumberOfCounts = new QLineEdit(centralwidget);
        LNumberOfCounts->setObjectName("LNumberOfCounts");

        horizontalLayout_6->addWidget(LNumberOfCounts);

        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");

        horizontalLayout_6->addWidget(label_27);

        LSpectrumRange = new QLineEdit(centralwidget);
        LSpectrumRange->setObjectName("LSpectrumRange");

        horizontalLayout_6->addWidget(LSpectrumRange);

        label_28 = new QLabel(centralwidget);
        label_28->setObjectName("label_28");

        horizontalLayout_6->addWidget(label_28);

        LBinning = new QLineEdit(centralwidget);
        LBinning->setObjectName("LBinning");

        horizontalLayout_6->addWidget(LBinning);


        verticalLayout_2->addLayout(horizontalLayout_6);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(16);
        font.setBold(true);
        label_13->setFont(font);

        verticalLayout_2->addWidget(label_13);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ContiniousLifetime = new QCheckBox(centralwidget);
        ContiniousLifetime->setObjectName("ContiniousLifetime");
        QFont font1;
        font1.setBold(true);
        ContiniousLifetime->setFont(font1);

        verticalLayout->addWidget(ContiniousLifetime);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        LLifetime1 = new QLineEdit(centralwidget);
        LLifetime1->setObjectName("LLifetime1");

        horizontalLayout->addWidget(LLifetime1);

        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");

        horizontalLayout->addWidget(label_22);

        LSigma1 = new QLineEdit(centralwidget);
        LSigma1->setObjectName("LSigma1");

        horizontalLayout->addWidget(LSigma1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        horizontalLayout->addWidget(label_8);

        LIntensity1 = new QLineEdit(centralwidget);
        LIntensity1->setObjectName("LIntensity1");

        horizontalLayout->addWidget(LIntensity1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        LLifetime2 = new QLineEdit(centralwidget);
        LLifetime2->setObjectName("LLifetime2");

        horizontalLayout_2->addWidget(LLifetime2);

        label_23 = new QLabel(centralwidget);
        label_23->setObjectName("label_23");

        horizontalLayout_2->addWidget(label_23);

        LSigma2 = new QLineEdit(centralwidget);
        LSigma2->setObjectName("LSigma2");

        horizontalLayout_2->addWidget(LSigma2);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        horizontalLayout_2->addWidget(label_10);

        LIntensity2 = new QLineEdit(centralwidget);
        LIntensity2->setObjectName("LIntensity2");

        horizontalLayout_2->addWidget(LIntensity2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        LLifetime3 = new QLineEdit(centralwidget);
        LLifetime3->setObjectName("LLifetime3");

        horizontalLayout_3->addWidget(LLifetime3);

        label_25 = new QLabel(centralwidget);
        label_25->setObjectName("label_25");

        horizontalLayout_3->addWidget(label_25);

        LSigma3 = new QLineEdit(centralwidget);
        LSigma3->setObjectName("LSigma3");

        horizontalLayout_3->addWidget(LSigma3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        horizontalLayout_3->addWidget(label_7);

        LIntensity3 = new QLineEdit(centralwidget);
        LIntensity3->setObjectName("LIntensity3");

        horizontalLayout_3->addWidget(LIntensity3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        LLifetime4 = new QLineEdit(centralwidget);
        LLifetime4->setObjectName("LLifetime4");

        horizontalLayout_4->addWidget(LLifetime4);

        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");

        horizontalLayout_4->addWidget(label_24);

        LSigma4 = new QLineEdit(centralwidget);
        LSigma4->setObjectName("LSigma4");

        horizontalLayout_4->addWidget(LSigma4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");

        horizontalLayout_4->addWidget(label_9);

        LIntensity4 = new QLineEdit(centralwidget);
        LIntensity4->setObjectName("LIntensity4");

        horizontalLayout_4->addWidget(LIntensity4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        LLifetime5 = new QLineEdit(centralwidget);
        LLifetime5->setObjectName("LLifetime5");

        horizontalLayout_5->addWidget(LLifetime5);

        label_26 = new QLabel(centralwidget);
        label_26->setObjectName("label_26");

        horizontalLayout_5->addWidget(label_26);

        LSigma5 = new QLineEdit(centralwidget);
        LSigma5->setObjectName("LSigma5");

        horizontalLayout_5->addWidget(LSigma5);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        horizontalLayout_5->addWidget(label_11);

        LIntensity5 = new QLineEdit(centralwidget);
        LIntensity5->setObjectName("LIntensity5");

        horizontalLayout_5->addWidget(LIntensity5);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_11->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        verticalLayout_3->addWidget(label_14);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");

        horizontalLayout_7->addWidget(label_15);

        LFWHM1 = new QLineEdit(centralwidget);
        LFWHM1->setObjectName("LFWHM1");

        horizontalLayout_7->addWidget(LFWHM1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");

        horizontalLayout_7->addWidget(label_16);

        LFWHM_Intensity1 = new QLineEdit(centralwidget);
        LFWHM_Intensity1->setObjectName("LFWHM_Intensity1");

        horizontalLayout_7->addWidget(LFWHM_Intensity1);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");

        horizontalLayout_8->addWidget(label_17);

        LFWHM2 = new QLineEdit(centralwidget);
        LFWHM2->setObjectName("LFWHM2");

        horizontalLayout_8->addWidget(LFWHM2);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");

        horizontalLayout_8->addWidget(label_18);

        LFWHM_Intensity2 = new QLineEdit(centralwidget);
        LFWHM_Intensity2->setObjectName("LFWHM_Intensity2");

        horizontalLayout_8->addWidget(LFWHM_Intensity2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");

        horizontalLayout_9->addWidget(label_19);

        Lt0_shift = new QLineEdit(centralwidget);
        Lt0_shift->setObjectName("Lt0_shift");

        horizontalLayout_9->addWidget(Lt0_shift);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setFont(font);

        verticalLayout_4->addWidget(label_20);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");

        horizontalLayout_10->addWidget(label_21);

        LBackground = new QLineEdit(centralwidget);
        LBackground->setObjectName("LBackground");

        horizontalLayout_10->addWidget(LBackground);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_11->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_12->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_12);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 948, 21));
        menuBack = new QMenu(menubar);
        menuBack->setObjectName("menuBack");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBack->menuAction());
        menuBack->addAction(actionStart_Window);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ideal Spectra-Generator", nullptr));
        actionStart_Window->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Number of Components:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Number of Counts:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Spectrum Range (ns)", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Binning (ps)", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Spektrum", nullptr));
        ContiniousLifetime->setText(QCoreApplication::translate("MainWindow", "Continious Lifetime", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lifetime 1 (ns):", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Sigma 1:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Intensity 1:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Lifetime 2 (ns):", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Sigma 2:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Intensity 2:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Lifetime 3 (ns):", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Sigma 3:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Intensity 3:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Lifetime 4 (ns):", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Sigma 4:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Intensity 4:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Lifetime 5 (ns):", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Sigma 5:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Intensity 5:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "IRF", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "FWHM 1 (ns):", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Intensity 1:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "FWHM 2 (ns):", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Intensity 2:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "t0 shift of FWHM 2:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "BG:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        menuBack->setTitle(QCoreApplication::translate("MainWindow", "Optionen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
