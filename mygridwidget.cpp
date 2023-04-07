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

//    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
//        GridElement *gridElement = new GridElement(, scrollWidget);
//        gridElement->setData(generateRandomInspectionSummary());
//        scrollLayout->addWidget(gridElement, m_row / 2, m_row % 2);
//        m_row++;
//    });
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        setData(generateRandomInspectionSummary());
    });
    scrollLayout->addWidget(new GridElement(PaintInspection, scrollWidget));
    scrollLayout->addWidget(new GridElement(MarkingInspection, scrollWidget));
    scrollLayout->addWidget(new GridElement(DefectInspection, scrollWidget));
    scrollLayout->addWidget(new GridElement(DentInspection, scrollWidget));
    scrollLayout->addWidget(new GridElement(LightningInspection, scrollWidget));
}

MyGridWidget::~MyGridWidget()
{
    if (ui)
        delete ui;
}

void MyGridWidget::setData(const Data &data) {
    // Get all the child GridElement widgets
    QList<GridElement*> gridElements = ui->scrollArea->findChildren<GridElement*>();

    // Update the data for each GridElement widget
    for (auto &element: gridElements) {
        // Set the data for the current GridElement widget
        element->setData(data);
    }
}
