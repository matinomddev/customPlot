/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *layoutPlot;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExit;
    QPushButton *btnGenerate;
    QPushButton *btnClear;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineTime;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineCount;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineMin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineMax;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineXLabel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QPushButton *btnXLFont;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QPushButton *btnXTicklabelFont;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QPushButton *btnXAxisColor;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_17;
    QPushButton *btnXGridColor;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_19;
    QPushButton *btnXZeroLineColor;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineYLabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QPushButton *btnYLFont;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QPushButton *btnYTicklabelFont;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_16;
    QPushButton *btnYAxisColor;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_18;
    QPushButton *btnYGridColor;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_20;
    QPushButton *btnYZeroLineColor;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QPushButton *btnBgColor;
    QPushButton *btnBgImage;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QPushButton *btnPenColor;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1243, 943);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        layoutPlot = new QHBoxLayout();
        layoutPlot->setObjectName("layoutPlot");

        horizontalLayout_2->addLayout(layoutPlot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        btnExit = new QPushButton(centralwidget);
        btnExit->setObjectName("btnExit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy);
        btnExit->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"background-color: red;"));

        horizontalLayout_8->addWidget(btnExit);


        verticalLayout->addLayout(horizontalLayout_8);

        btnGenerate = new QPushButton(centralwidget);
        btnGenerate->setObjectName("btnGenerate");
        btnGenerate->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"padding: 20px;"));

        verticalLayout->addWidget(btnGenerate);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"padding: 20px;\n"
"background-color: red;"));

        verticalLayout->addWidget(btnClear);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineTime = new QLineEdit(centralwidget);
        lineTime->setObjectName("lineTime");

        horizontalLayout->addWidget(lineTime);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineCount = new QLineEdit(centralwidget);
        lineCount->setObjectName("lineCount");

        horizontalLayout_3->addWidget(lineCount);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        lineMin = new QLineEdit(centralwidget);
        lineMin->setObjectName("lineMin");

        horizontalLayout_5->addWidget(lineMin);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        lineMax = new QLineEdit(centralwidget);
        lineMax->setObjectName("lineMax");

        horizontalLayout_4->addWidget(lineMax);


        verticalLayout->addLayout(horizontalLayout_4);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        lineXLabel = new QLineEdit(centralwidget);
        lineXLabel->setObjectName("lineXLabel");

        horizontalLayout_6->addWidget(lineXLabel);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");

        horizontalLayout_10->addWidget(label_9);

        btnXLFont = new QPushButton(centralwidget);
        btnXLFont->setObjectName("btnXLFont");

        horizontalLayout_10->addWidget(btnXLFont);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        horizontalLayout_11->addWidget(label_11);

        btnXTicklabelFont = new QPushButton(centralwidget);
        btnXTicklabelFont->setObjectName("btnXTicklabelFont");

        horizontalLayout_11->addWidget(btnXTicklabelFont);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");

        horizontalLayout_15->addWidget(label_15);

        btnXAxisColor = new QPushButton(centralwidget);
        btnXAxisColor->setObjectName("btnXAxisColor");

        horizontalLayout_15->addWidget(btnXAxisColor);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");

        horizontalLayout_17->addWidget(label_17);

        btnXGridColor = new QPushButton(centralwidget);
        btnXGridColor->setObjectName("btnXGridColor");

        horizontalLayout_17->addWidget(btnXGridColor);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");

        horizontalLayout_19->addWidget(label_19);

        btnXZeroLineColor = new QPushButton(centralwidget);
        btnXZeroLineColor->setObjectName("btnXZeroLineColor");

        horizontalLayout_19->addWidget(btnXZeroLineColor);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        lineYLabel = new QLineEdit(centralwidget);
        lineYLabel->setObjectName("lineYLabel");

        horizontalLayout_7->addWidget(lineYLabel);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        horizontalLayout_9->addWidget(label_10);

        btnYLFont = new QPushButton(centralwidget);
        btnYLFont->setObjectName("btnYLFont");

        horizontalLayout_9->addWidget(btnYLFont);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        horizontalLayout_12->addWidget(label_12);

        btnYTicklabelFont = new QPushButton(centralwidget);
        btnYTicklabelFont->setObjectName("btnYTicklabelFont");

        horizontalLayout_12->addWidget(btnYTicklabelFont);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");

        horizontalLayout_16->addWidget(label_16);

        btnYAxisColor = new QPushButton(centralwidget);
        btnYAxisColor->setObjectName("btnYAxisColor");

        horizontalLayout_16->addWidget(btnYAxisColor);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");

        horizontalLayout_18->addWidget(label_18);

        btnYGridColor = new QPushButton(centralwidget);
        btnYGridColor->setObjectName("btnYGridColor");

        horizontalLayout_18->addWidget(btnYGridColor);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");

        horizontalLayout_20->addWidget(label_20);

        btnYZeroLineColor = new QPushButton(centralwidget);
        btnYZeroLineColor->setObjectName("btnYZeroLineColor");

        horizontalLayout_20->addWidget(btnYZeroLineColor);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");

        horizontalLayout_13->addWidget(label_13);

        btnBgColor = new QPushButton(centralwidget);
        btnBgColor->setObjectName("btnBgColor");

        horizontalLayout_13->addWidget(btnBgColor);

        btnBgImage = new QPushButton(centralwidget);
        btnBgImage->setObjectName("btnBgImage");

        horizontalLayout_13->addWidget(btnBgImage);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");

        horizontalLayout_14->addWidget(label_14);

        btnPenColor = new QPushButton(centralwidget);
        btnPenColor->setObjectName("btnPenColor");

        horizontalLayout_14->addWidget(btnPenColor);


        verticalLayout->addLayout(horizontalLayout_14);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1243, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        btnGenerate->setText(QCoreApplication::translate("MainWindow", "Generate Data", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear Data", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Generate Setting</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Generate Time (milly sec) :</p></body></html>", nullptr));
        lineTime->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Count :</p></body></html>", nullptr));
        lineCount->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Min :    ", nullptr));
        lineMin->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Max :   ", nullptr));
        lineMax->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Plot Setting</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X Label :", nullptr));
        lineXLabel->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "X Label Font and Color :", nullptr));
        btnXLFont->setText(QCoreApplication::translate("MainWindow", "Select Font", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X Ticklabel Font and Color :", nullptr));
        btnXTicklabelFont->setText(QCoreApplication::translate("MainWindow", "Select Font", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "X Axis Color :", nullptr));
        btnXAxisColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "X Grid Color :", nullptr));
        btnXGridColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "X Zero Line Color :", nullptr));
        btnXZeroLineColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y Label :", nullptr));
        lineYLabel->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y Label Font and Color :", nullptr));
        btnYLFont->setText(QCoreApplication::translate("MainWindow", "Select Font", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Y Ticklabel Font and Color :", nullptr));
        btnYTicklabelFont->setText(QCoreApplication::translate("MainWindow", "Select Font", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Y Axis Color :", nullptr));
        btnYAxisColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Y Grid Color :", nullptr));
        btnYGridColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Y Zero Line Color :", nullptr));
        btnYZeroLineColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Select Background :", nullptr));
        btnBgColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        btnBgImage->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Pen Color :", nullptr));
        btnPenColor->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
