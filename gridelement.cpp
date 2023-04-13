#include "gridelement.h"
#include "ui_gridelement.h"
#include "Data.h"

GridElement::GridElement(InspectionType inspectionType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridElement)
{
    ui->setupUi(this);

    type = inspectionType;
    ui->InspectionType->setText(getInspectionName(type));

    m_horizontalLayout = new QHBoxLayout(this);

    m_progressLabel = new QLabel("Progress amount:", this);
    m_progressAmount = new QLCDNumber(this);
    m_progressStatusLabel = new QLabel("Progress status: ", this);
    m_progressStatusValue = new QLabel("Undefined");

    m_horizontalLayout->addWidget(m_progressStatusLabel);
    m_horizontalLayout->addWidget(m_progressStatusValue);
    m_horizontalLayout->addWidget(m_progressLabel);
    m_horizontalLayout->addWidget(m_progressAmount);

    ui->mainLayout->addLayout(m_horizontalLayout);
}

GridElement::~GridElement()
{
    if (ui)
        delete ui;
}

void GridElement::setData(const Data &)
{
}
