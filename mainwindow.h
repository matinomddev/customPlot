#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QRandomGenerator>
#include <QTimer>
#include <QFont>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGenerate_clicked();

    void on_btnClear_clicked();

    void on_btnExit_clicked();

    void on_btnXLFont_clicked();

    void on_btnYLFont_clicked();

    void on_btnXTicklabelFont_clicked();

    void on_btnYTicklabelFont_clicked();

    void on_btnBgColor_clicked();

    void on_btnBgImage_clicked();

    void on_btnPenColor_clicked();

    void on_btnXAxisColor_clicked();

    void on_btnYAxisColor_clicked();

    void on_btnXGridColor_clicked();

    void on_btnYGridColor_clicked();

    void on_btnXZeroLineColor_clicked();

    void on_btnYZeroLineColor_clicked();

    void on_btnSave_clicked();

    void on_btnOpen_clicked();

    void on_comboPointSize_currentTextChanged(const QString &arg1);

    void on_btnPointColor_clicked();

    void on_lineTime_textChanged(const QString &arg1);

    void on_lineCount_textChanged(const QString &arg1);

    void on_lineMin_textChanged(const QString &arg1);

    void on_lineMax_textChanged(const QString &arg1);

    void on_btnSavePlotAsPdf_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *plot;
    int count;
    int min;
    int max;
    int millySec;
    std::unique_ptr<QVector<double>> xData;
    std::unique_ptr<QVector<double>> yData;
    bool isGenerating = false;
    QTimer *timer;
    QCPSelectionRect *zoomRect;

    void generateRandomData();
    bool eventFilter(QObject *obj, QEvent *event);
    void errorMessage(QString text);
};
#endif // MAINWINDOW_H
