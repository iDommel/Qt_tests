
#include "markinginspectionwidget.h"
#include "Data.h"
#include "ui_gridelement.h"
#include <QHBoxLayout>

MarkingInspectionWidget::MarkingInspectionWidget(QWidget *parent):
    GridElement(MarkingInspection, parent)
{
    QHBoxLayout *stickersLayout = new QHBoxLayout(this);

    m_stickersLabel = new QLabel("Stickers (Validated / Analysed)", this);
    m_stickersValue = new QLabel("(? / ?)", this);

    stickersLayout->addWidget(m_stickersLabel);
    stickersLayout->addWidget(m_stickersValue);

    ui->mainLayout->addLayout(stickersLayout);
}

void MarkingInspectionWidget::setData(const Data &data)
{
    QString progressStatusValue = "Not Done";
    if (data.markingInspectionDone) {
        progressStatusValue = "Done on: " + data.markingInspectionDate.toString("dd/MM/yyyy hh:mm:ss");
    }
    m_progressStatusValue->setText(progressStatusValue);
    m_progressLabel->setText("markingInspectionProgression: ");
    m_progressAmount->display(data.markingInspectionProgression * 100);

    QString stickerString = QString("( %1 / %2 )")
        .arg(data.amountOfValidatedStickers)
        .arg(data.amountOfAnalyzedStickers);
    m_stickersValue->setText(stickerString);
}
