#include "mygridwidget.h"
#include "ui_mygridwidget.h"
#include "gridelement.h"
#include "Data.h"
#include <QLabel>

#include "defectinspectionwidget.h"
#include "paintinspectionwidget.h"
#include "dentinspectionwidget.h"
#include "markinginspectionwidget.h"
#include "lightninginspectionwidget.h"

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
        setData(generateRandomInspectionSummary());
    });

    scrollLayout->addWidget(new PaintInspectionWidget(scrollWidget));
    scrollLayout->addWidget(new MarkingInspectionWidget(scrollWidget));
    scrollLayout->addWidget(new DefectInspectionWidget(scrollWidget));
    scrollLayout->addWidget(new DentInspectionWidget(scrollWidget));
    scrollLayout->addWidget(new LightningInspectionWidget(scrollWidget));
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
