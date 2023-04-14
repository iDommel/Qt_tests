#include "inspectionwidget.h"
#include "ui_inspectionWidget.h"
#include "Data.h"
#include <QGroupBox>

void InspectionWidget::generateInfoLayout()
{
    QGroupBox *infoBox = new QGroupBox();
    QHBoxLayout *inspectionInfoLayout = new QHBoxLayout(infoBox);

    m_progressLabel = new QLabel("Progress amount:", this);
    m_progressAmount = new QLCDNumber(this);
    m_progressStatusLabel = new QLabel("Progress status: ", this);
    m_progressStatusValue = new QLabel("Undefined");

    inspectionInfoLayout->addWidget(m_progressStatusLabel);
    inspectionInfoLayout->addWidget(m_progressStatusValue);
    inspectionInfoLayout->addWidget(m_progressLabel);
    inspectionInfoLayout->addWidget(m_progressAmount);

    ui->mainLayout->addWidget(infoBox);
}

void InspectionWidget::generateButtonLayout()
{
    QGroupBox *buttonBox = new QGroupBox();
    QHBoxLayout *inspectionButtonLayout = new QHBoxLayout(buttonBox);

    m_buttonLocal = new QPushButton("Local");
    m_buttonCloud = new QPushButton("Cloud");
    m_buttonNew = new QPushButton("New");

    inspectionButtonLayout->addWidget(m_buttonLocal);
    inspectionButtonLayout->addWidget(m_buttonCloud);
    inspectionButtonLayout->addWidget(m_buttonNew);
    m_buttonLocal->setDisabled(true);
    m_buttonCloud->setDisabled(true);
    m_buttonNew->setDisabled(true);

    ui->mainLayout->addWidget(buttonBox);
}

InspectionWidget::InspectionWidget(InspectionType inspectionType, QWidget *parent) : QWidget(parent),
                                                                                     ui(new Ui::InspectionWidget)
{
    ui->setupUi(this);

    type = inspectionType;
    ui->InspectionType->setText(getInspectionName(type));

    generateInfoLayout();
    generateButtonLayout();
}

InspectionWidget::~InspectionWidget()
{
    if (ui)
        delete ui;
}

void InspectionWidget::setData(const Data &data)
{
    InspectionData filteredData = data.getInspectionData(type);
    QString progressStatusValue = "Not Done";
    if (filteredData.inspectionDone) {
        progressStatusValue = "Done on: " + filteredData.inspectionDate.toString("dd/MM/yyyy hh:mm:ss");
        m_buttonLocal->setDisabled(false);
        m_buttonCloud->setDisabled(false);
        m_buttonNew->setDisabled(true);
    } else {
        m_buttonLocal->setDisabled(true);
        m_buttonCloud->setDisabled(true);
        m_buttonNew->setDisabled(false);
    }
    m_progressStatusValue->setText(progressStatusValue);
    m_progressLabel->setText("InspectionProgression: ");
    m_progressAmount->display(filteredData.inspectionProgression * 100);
}
