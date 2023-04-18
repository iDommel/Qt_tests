#include "mygridwidget.h"
#include "Data.h"
#include "inspectionwidget.h"
#include "ui_mygridwidget.h"
#include <QLabel>

#include "startScreen/inspectionWidgets/markinginspectionwidget.h"

MyGridWidget::MyGridWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MyGridWidget), m_row(0)
{
    ui->setupUi(this);

    // Create a new widget to hold the InspectionWidgets
    QWidget *scrollWidget = new QWidget();
    QGridLayout *scrollLayout = new QGridLayout(scrollWidget);
    scrollLayout->setAlignment(Qt::AlignTop);
    scrollWidget->setLayout(scrollLayout);
    if(true) { return; }
    // Set the scrollable area's widget to the new widget
    ui->scrollArea->setWidget(scrollWidget);

    connect(ui->pushButton, &QPushButton::clicked, this,
            [=]() { setData(generateRandomNewData()); });

    scrollLayout->addWidget(
        new InspectionWidget(PaintInspection, scrollWidget));
    scrollLayout->addWidget(new MarkingInspectionWidget(scrollWidget));
    scrollLayout->addWidget(
        new InspectionWidget(DefectInspection, scrollWidget));
    scrollLayout->addWidget(new InspectionWidget(DentInspection, scrollWidget));
    scrollLayout->addWidget(
        new InspectionWidget(LightningInspection, scrollWidget));
}

MyGridWidget::~MyGridWidget()
{
    if(ui) delete ui;
}

void MyGridWidget::setData(const Data &data)
{
    // Get all the child InspectionWidget widgets
    QList<InspectionWidget *> gridElements =
        ui->scrollArea->findChildren<InspectionWidget *>();

    // Update the data for each InspectionWidget widget
    for(auto &element : gridElements)
    {
        // Set the data for the current InspectionWidget widget
        element->setData(data);
    }
}
