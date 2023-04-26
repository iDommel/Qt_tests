
#include "markinginspectionwidget.h"
#include "Data.h"
#include "ui_inspectionWidget.h"
#include <QGroupBox>

MarkingInspectionWidget::MarkingInspectionWidget(QWidget *parent) : InspectionWidget(InspectionType::MarkingInspection, parent) { generateStickersLayout(); }

void MarkingInspectionWidget::generateStickersLayout()
{
    QGroupBox *infoBox = new QGroupBox();
    QHBoxLayout *sickersInfoLayout = new QHBoxLayout(infoBox);

    m_stickersLabel = new QLabel("Stickers progress: (Validated/Analysed)", this);
    m_stickersValue = new QLabel("Stickers progress: (?/?)", this);

    sickersInfoLayout->addWidget(m_stickersLabel);
    sickersInfoLayout->addWidget(m_stickersValue);

    ui->mainLayout->addWidget(infoBox);
}

void MarkingInspectionWidget::setData(const Data &data)
{
    InspectionWidget::setData(data);
    InspectionData markingData = data.getInspectionData(InspectionType::MarkingInspection);
    QString stickerString = QString("( %1 / %2 )").arg(markingData.validatedObject).arg(markingData.analyzedObjects);

    m_stickersValue->setText(stickerString);
    qDebug("MarkingInspectionWidget::setData()");
}
