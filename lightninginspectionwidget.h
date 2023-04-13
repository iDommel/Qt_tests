
#ifndef LIGHTNINGINSPECTIONWIDGET_H
#define LIGHTNINGINSPECTIONWIDGET_H

#include "gridelement.h"



class LightningInspectionWidget : public GridElement
{
public:
    LightningInspectionWidget(QWidget* parent = nullptr);
    void setData(const Data& data) override;
};

#endif // LIGHTNINGINSPECTIONWIDGET_H
