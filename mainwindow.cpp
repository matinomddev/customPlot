#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIntValidator>
#include <QFontDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    xData = new QVector<double>;
    yData = new QVector<double>;

    plot = new QCustomPlot();
    ui->layoutPlot->addWidget(plot);
    ui->verticalLayout->setAlignment(Qt::AlignTop);

    ui->lineCount->setValidator(new QIntValidator(1, 99999, this));
    ui->lineMax->setValidator(new QIntValidator(1, 99999, this));
    ui->lineMin->setValidator(new QIntValidator(0, 99999, this));
    ui->lineTime->setValidator(new QIntValidator(10, 60000, this));

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::generateRandomData);

    plot->rescaleAxes();

    plot->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
    plot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);

    zoomRect = new QCPSelectionRect(plot);
    plot->setSelectionRect(zoomRect);
    zoomRect->setPen(QPen(Qt::blue));
    zoomRect->setBrush(QBrush(QColor(0, 0, 255, 50)));
    zoomRect->setLayer("overlay");

    plot->axisRect()->setRangeZoomAxes(plot->xAxis, plot->yAxis);

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    plot->setFocusPolicy(Qt::StrongFocus);

    plot->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == plot)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Control){
                ctrlPressed = true;
                plot->setSelectionRectMode(QCP::srmZoom);
            }
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Control){
                ctrlPressed = false;
                plot->setSelectionRectMode(QCP::srmNone);
            }
        }
        else if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            double x = plot->xAxis->pixelToCoord(mouseEvent->pos().x());
            double y = plot->yAxis->pixelToCoord(mouseEvent->pos().y());

            QString text = QString("X: %1\nY: %2")
                               .arg(x, 0, 'f', 2)
                               .arg(y, 0, 'f', 2);

            QToolTip::showText(mouseEvent->globalPosition().toPoint(), text, plot);
        }
    }

    return QMainWindow::eventFilter(obj, event);
}



void MainWindow::generateRandomData(){
    for (int i = 0; i < count; ++i) {
        int value = QRandomGenerator::global()->bounded(min, max);
        xData->append(i);
        yData->append(value);
    }

    plot->addGraph();
    plot->graph(0)->setData(*xData, *yData);
    plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));

    plot->xAxis->setLabel(ui->lineXLabel->text().trimmed());
    plot->yAxis->setLabel(ui->lineYLabel->text().trimmed());

    plot->replot();
}

// QColor MainWindow::SelectColor(){

// }

// QColor MainWindow::SelectPen(){

// }

// QFont MainWindow::SelectFont(){

// }

void MainWindow::on_btnGenerate_clicked()
{
    if(!isGenerating){
        if(ui->lineCount->text().isEmpty()){
            return;
        }
        else if(ui->lineMax->text().isEmpty()){
            return;
        }
        else if(ui->lineMin->text().isEmpty()){
            return;
        }
        else if(ui->lineTime->text().isEmpty()){
            return;
        }
        else if(ui->lineMax->text().toInt() <= ui->lineMin->text().toInt()){
            return;
        }
        else{
            count = ui->lineCount->text().toInt();
            min = ui->lineMin->text().toInt();
            max = ui->lineMax->text().toInt();
            millySec = ui->lineCount->text().toInt();
            isGenerating = true;
            ui->btnGenerate->setText("Stop Generating");

            timer->start(millySec);
        }
    }
    else{
        isGenerating = false;
        ui->btnGenerate->setText("Generate Data");

        timer->stop();
    }
}


void MainWindow::on_btnClear_clicked()
{
    if(!isGenerating){
        xData->clear();
        yData->clear();
        plot->clearGraphs();
        plot->clearItems();
        plot->replot();
    }
}


void MainWindow::on_btnExit_clicked()
{
    QApplication::exit();
}


void MainWindow::on_btnXLFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, plot->xAxis->labelFont(), this, "Choose x axis font");

    if(ok){
        plot->xAxis->setLabelFont(font);

        QColor color = QColorDialog::getColor(plot->xAxis->labelColor(),this, "Choose x axis color");
        if(color.isValid()){
            plot->xAxis->setLabelColor(color);
        }
    }
    plot->replot();
}


void MainWindow::on_btnYLFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, plot->yAxis->labelFont(), this, "Choose y axis label font");

    if(ok){
        plot->yAxis->setLabelFont(font);

        QColor color = QColorDialog::getColor(plot->yAxis->labelColor(),this, "Choose y axis label color");
        if(color.isValid()){
            plot->yAxis->setLabelColor(color);
        }
    }
    plot->replot();
}


void MainWindow::on_btnXTicklabelFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, plot->xAxis->tickLabelFont(), this, "Choose x axis ticklabel font");

    if(ok){
        plot->xAxis->setTickLabelFont(font);

        QColor color = QColorDialog::getColor(plot->xAxis->tickLabelColor(),this, "Choose x axis ticklabel color");
        if(color.isValid()){
            plot->xAxis->setTickLabelColor(color);
        }
    }
    plot->replot();
}


void MainWindow::on_btnYTicklabelFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, plot->yAxis->tickLabelFont(), this, "Choose y axis ticklabel font");

    if(ok){
        plot->yAxis->setTickLabelFont(font);

        QColor color = QColorDialog::getColor(plot->yAxis->tickLabelColor(),this, "Choose y axis ticklabel color");
        if(color.isValid()){
            plot->yAxis->setTickLabelColor(color);
        }
    }
    plot->replot();
}


void MainWindow::on_btnBgColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Background Color");
    if(color.isValid()){
        plot->setBackground(QPixmap());
        plot->setBackground(QBrush(color));
        plot->replot();
    }
}


void MainWindow::on_btnBgImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose Background Image.", "", "Images (*.png *.jpg)");
    if (!fileName.isEmpty()) {
        QPixmap bg(fileName);
        if (!bg.isNull()) {
            plot->setBackground(bg);
            plot->replot();
        }
    }
}


void MainWindow::on_btnPenColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose Graph Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->graph(0)->setPen(pen);
        plot->replot();

    }
}


void MainWindow::on_btnXAxisColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose X Axis Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->xAxis->setBasePen(pen);
        plot->xAxis->setTickPen(pen);
        plot->xAxis->setSubTickPen(pen);
        plot->replot();

    }
}


void MainWindow::on_btnYAxisColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose Y Axis Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->yAxis->setBasePen(pen);
        plot->yAxis->setTickPen(pen);
        plot->yAxis->setSubTickPen(pen);
        plot->replot();

    }
}


void MainWindow::on_btnXGridColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose X Grid Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->xAxis->grid()->setPen(pen);
        plot->replot();

    }
}


void MainWindow::on_btnYGridColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose Y Grid Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->yAxis->grid()->setPen(pen);
        plot->replot();

    }
}


void MainWindow::on_btnXZeroLineColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose X Sub Grid Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->xAxis->grid()->setZeroLinePen(pen);
        plot->replot();

    }
}


void MainWindow::on_btnYZeroLineColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose Y Sub Grid Color");
    if (color.isValid())
    {
        QPen pen(color);

        plot->yAxis->grid()->setZeroLinePen(pen);
        plot->replot();

    }
}

