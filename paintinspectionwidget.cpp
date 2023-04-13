
#include "ui_gridelement.h"
#include "paintinspectionwidget.h"
#include "Data.h"

PaintInspectionWidget::PaintInspectionWidget(QWidget* parent)
: GridElement(PaintInspection, parent)
{
}

void PaintInspectionWidget::setData(const Data &data)
{
    QString progressStatusValue = "Not Done";
    if (data.paintInspectionDone) {
        progressStatusValue = "Done on: " + data.paintInspectionDate.toString("dd/MM/yyyy hh:mm:ss");
    }
    m_progressStatusValue->setText(progressStatusValue);
    m_progressLabel->setText("paintInspectionProgression: ");
    m_progressAmount->display(data.paintInspectionProgression * 100);
}

