
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testframe.h"
#include "mygridwidget.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TestFrame *frame = new TestFrame(this);
    frame->setLabelText("Hello world");
    MyGridWidget *grid = new MyGridWidget(this);

    ui->centralwidget->layout()->addWidget(grid);
    ui->centralwidget->layout()->addWidget(frame);
}

MainWindow::~MainWindow()
{
    delete ui;
}


