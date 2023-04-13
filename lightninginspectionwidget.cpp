
#include "ui_gridelement.h"
#include "lightninginspectionwidget.h"
#include "Data.h"

LightningInspectionWidget::LightningInspectionWidget(QWidget *parent):
    GridElement(LightningInspection, parent)
{

}

void LightningInspectionWidget::setData(const Data &data)
{
    QString progressStatusValue = "Not Done";
    if (data.lightningInspectionDone) {
        progressStatusValue = "Done on: " + data.lightningInspectionDate.toString("dd/MM/yyyy hh:mm:ss");
    }
    m_progressStatusValue->setText(progressStatusValue);
    m_progressLabel->setText("lightningInspectionProgression: ");
    m_progressAmount->display(data.lightningInspectionProgression * 100);
}

