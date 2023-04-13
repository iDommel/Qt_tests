
#ifndef DENTINSPECTIONWIDGET_H
#define DENTINSPECTIONWIDGET_H

#include "gridelement.h"



class DentInspectionWidget : public GridElement
{
public:
    DentInspectionWidget(QWidget* parent = nullptr);
    void setData(const Data& data) override;
};

#endif // DENTINSPECTIONWIDGET_H
