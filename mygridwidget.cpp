#include "mygridwidget.h"
#include "ui_mygridwidget.h"
#include "gridelement.h"
#include "Data.h"
#include <QLabel>

MyGridWidget::MyGridWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyGridWidget),
    m_row(0)
{
    ui->setupUi(this);

    // Create a new widget to hold the GridElements
    QWidget* scrollWidget = new QWidget();
    QGridLayout* scrollLayout = new QGridLayout(scrollWidget);
    scrollLayout->setAlignment(Qt::AlignTop);
    scrollWidget->setLayout(scrollLayout);

    // Set the scrollable area's widget to the new widget
    ui->scrollArea->setWidget(scrollWidget);

    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        // Create a new GridElement and add it to the new widget
        GridElement* gridElement = new GridElement(scrollWidget);
        gridElement->setData(generateRandomData());
        scrollLayout->addWidget(gridElement, m_row / 2, m_row % 2);
        m_row++;
    });
}

MyGridWidget::~MyGridWidget()
{
    if (ui)
        delete ui;
}

void MyGridWidget::setData(const QVector<Data> &data)
{
    for (auto &el: data) {
        GridElement *newEl = new GridElement();
        newEl->setData(el);
        ui->gridLayout->addWidget(newEl, m_row++, 0);
    }
}


void MyGridWidget::addData(const Data &data)
{
    GridElement *newEl = new GridElement();

    newEl->setData(data);
    ui->gridLayout->addWidget(newEl, m_row++, 0);
}
