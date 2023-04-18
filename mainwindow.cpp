#include "mainwindow.h"
#include "startscreen/mygridwidget.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyGridWidget *grid = new MyGridWidget(this);

    ui->centralwidget->layout()->addWidget(grid);
}

MainWindow::~MainWindow() { delete ui; }
