
#include "ui_gridelement.h"
#include "defectinspectionwidget.h"
#include "Data.h"

DefectInspectionWidget::DefectInspectionWidget(QWidget* parent):
    GridElement(DefectInspection, parent)
{
}

void DefectInspectionWidget::setData(const Data& data)
{
    QString progressStatusValue = "Not Done";
    if (data.defectInspectionDone) {
        progressStatusValue = "Done on: " + data.defectInspectionDate.toString("dd/MM/yyyy hh:mm:ss");
    }
    m_progressStatusValue->setText(progressStatusValue);
    m_progressLabel->setText("defectInspectionProgression: ");
    m_progressAmount->display(data.defectInspectionProgression * 100);
}

