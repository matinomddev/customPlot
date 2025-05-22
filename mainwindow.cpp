#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIntValidator>
#include <QFontDialog>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , xData(std::make_unique<QVector<double>>())
    , yData(std::make_unique<QVector<double>>())
{
    ui->setupUi(this);

    plot = new QCustomPlot();
    plot->addGraph();
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

    plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::black, Qt::black, 0));
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
                plot->setSelectionRectMode(QCP::srmZoom);
            }
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Control){
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

    plot->graph(0)->setData(*xData, *yData);

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

void MainWindow::errorMessage(QString text){
    QMessageBox::warning(this, "Error", text);
}

void MainWindow::on_btnGenerate_clicked()
{
    if(!isGenerating){
        if(ui->lineCount->text().isEmpty()){
            errorMessage("Please enter count");
            return;
        }
        else if(ui->lineMax->text().isEmpty()){
            errorMessage("Plese enter maximum value");
            return;
        }
        else if(ui->lineMin->text().isEmpty()){
            errorMessage("Plese enter minimum value");
            return;
        }
        else if(ui->lineTime->text().isEmpty()){
            errorMessage("Plese enter generate time");
            return;
        }
        else if(ui->lineMax->text().toInt() <= ui->lineMin->text().toInt()){
            errorMessage("Maximum value must be greater than minimum value.");
            return;
        }
        else{
            count = ui->lineCount->text().toInt();
            min = ui->lineMin->text().toInt();
            max = ui->lineMax->text().toInt();
            millySec = ui->lineTime->text().toInt();
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
        QCPScatterStyle currentStyle = plot->graph(0)->scatterStyle();
        QPen pen = plot->graph(0)->pen();
        xData->clear();
        yData->clear();
        plot->clearGraphs();
        plot->clearItems();
        plot->addGraph();
        plot->graph(0)->setScatterStyle(currentStyle);
        plot->graph(0)->setPen(pen);
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


void MainWindow::on_btnSave_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filePath = dialog.getSaveFileName(this, "Create new file", "", "CSV File (*.csv)");
    QFile file(filePath);
    QString time = QDateTime::currentDateTime().toString("yyyy / MM / dd - HH : mm");
    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        out << time << "\n";
        for (int i = 0; i < xData->size(); ++i) {
            out << xData->at(i) << "," << yData->at(i) << "\n";
        }
    }
    file.close();
}


void MainWindow::on_btnOpen_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filePath = dialog.getOpenFileName(this, "Open CSV File", "", "CSV File (*.csv)");
    QFile file(filePath);
    if(file.open(QFile::ReadOnly | QFile::Text)){
        xData->clear();
        yData->clear();
        QTextStream in(&file);
        QStringList items = in.readAll().split("\n");
        for (int i = 1; i < items.size() - 1; ++i) {
            QStringList data = items[i].split(",");
            if (data.size() == 2){
                xData->append(data[0].toDouble());
                yData->append(data[1].toDouble());
            }
        }
        QCPScatterStyle currentStyle = plot->graph(0)->scatterStyle();
        plot->clearItems();
        plot->clearGraphs();
        plot->addGraph();
        plot->graph(0)->setData(*xData, *yData);
        plot->graph(0)->setScatterStyle(currentStyle);
    }
    file.close();
}


void MainWindow::on_comboPointSize_currentTextChanged(const QString &arg1)
{
    if (plot->graphCount() == 0) return;

    QCPScatterStyle currentStyle = plot->graph(0)->scatterStyle();
    QColor color = currentStyle.pen().color();
    plot->graph(0)->setScatterStyle(QCPScatterStyle(currentStyle.shape(), color, color, arg1.toInt()));
    plot->replot();
}


void MainWindow::on_btnPointColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose Point Color");
    if(color.isValid()){
        QCPScatterStyle currentStyle = plot->graph(0)->scatterStyle();
        int size = currentStyle.size();
        plot->graph(0)->setScatterStyle(QCPScatterStyle(currentStyle.shape(), color, color, size));
        plot->replot();
    }
}


void MainWindow::on_lineTime_textChanged(const QString &arg1)
{
    if(ui->lineTime->text().isEmpty()){
        ui->lineTime->setStyleSheet("QLineEdit {background-color: red;}");
    }
    else{
        ui->lineTime->setStyleSheet("");
    }
}


void MainWindow::on_lineCount_textChanged(const QString &arg1)
{
    if(ui->lineCount->text().isEmpty()){
        ui->lineCount->setStyleSheet("QLineEdit {background-color: red;}");
    }
    else{
        ui->lineCount->setStyleSheet("");
    }
}


void MainWindow::on_lineMin_textChanged(const QString &arg1)
{
    if(ui->lineMin->text().isEmpty()){
        ui->lineMin->setStyleSheet("QLineEdit {background-color: red;}");
    }
    else{
        ui->lineMin->setStyleSheet("");
    }
}


void MainWindow::on_lineMax_textChanged(const QString &arg1)
{
    if(ui->lineMax->text().isEmpty() || ui->lineMax->text().toInt() <= ui->lineMin->text().toInt()){
        ui->lineMax->setStyleSheet("QLineEdit {background-color: red;}");
    }
    else{
        ui->lineMax->setStyleSheet("");
    }
}


void MainWindow::on_btnSavePlotAsPdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save plot pdf", "", "PDF Files (*.pdf)");

    if(!fileName.isEmpty()){
        if(!fileName.endsWith(".pdf", Qt::CaseInsensitive))
            fileName += ".pdf";

        plot->savePdf(fileName, plot->width(), plot->height());

    }
}

