
#ifndef PAINTINSPECTIONWIDGET_H
#define PAINTINSPECTIONWIDGET_H
#include <QLabel>
#include <QLCDNumber>
#include <QHBoxLayout>
#include "gridelement.h"



class PaintInspectionWidget : public GridElement
{
public:
    PaintInspectionWidget(QWidget* parent = nullptr);
    void setData(const Data& data) override;
private:
};

#endif // PAINTINSPECTIONWIDGET_H
