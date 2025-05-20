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

private:
    Ui::MainWindow *ui;
    QCustomPlot *plot;
    int count;
    int min;
    int max;
    int millySec;
    QVector<double> *xData;
    QVector<double> *yData;
    bool isGenerating = false;
    QTimer *timer;
    QCPSelectionRect *zoomRect;
    bool ctrlPressed = false;

    void generateRandomData();
    bool eventFilter(QObject *obj, QEvent *event);
};
#endif // MAINWINDOW_H
