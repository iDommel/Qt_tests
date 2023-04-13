#include "mygridwidget.h"
#include "ui_mygridwidget.h"
#include "inspectionwidget.h"
#include "Data.h"
#include <QLabel>

#include "inspectionWidgets/defectinspectionwidget.h"
#include "inspectionWidgets/paintinspectionwidget.h"
#include "inspectionWidgets/dentinspectionwidget.h"
#include "inspectionWidgets/markinginspectionwidget.h"
#include "inspectionWidgets/lightninginspectionwidget.h"

MyGridWidget::MyGridWidget(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::MyGridWidget),
                                              m_row(0)
{
    ui->setupUi(this);

    // Create a new widget to hold the InspectionWidgets
    QWidget *scrollWidget = new QWidget();
    QGridLayout *scrollLayout = new QGridLayout(scrollWidget);
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

void MyGridWidget::setData(const Data &data)
{
    // Get all the child InspectionWidget widgets
    QList<InspectionWidget *> gridElements = ui->scrollArea->findChildren<InspectionWidget *>();

    // Update the data for each InspectionWidget widget
    for (auto &element : gridElements) {
        // Set the data for the current InspectionWidget widget
        element->setData(data);
    }
}
