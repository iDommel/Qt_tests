
#include "ui_gridelement.h"
#include "dentinspectionwidget.h"
#include "Data.h"

DentInspectionWidget::DentInspectionWidget(QWidget *parent):
    GridElement(DentInspection, parent)
{
}

void DentInspectionWidget::setData(const Data &data)
{
    QString progressStatusValue = "Not Done";
    if (data.dentInspectionDone) {
        progressStatusValue = "Done on: " + data.dentInspectionDate.toString("dd/MM/yyyy hh:mm:ss");
    }
    m_progressStatusValue->setText(progressStatusValue);
    m_progressLabel->setText("dentInspectionProgression: ");
    m_progressAmount->display(data.dentInspectionProgression * 100);
}
