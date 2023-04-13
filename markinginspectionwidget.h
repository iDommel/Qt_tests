
#ifndef MARKINGINSPECTIONWIDGET_H
#define MARKINGINSPECTIONWIDGET_H

#include "gridelement.h"



class MarkingInspectionWidget : public GridElement
{
public:
    MarkingInspectionWidget(QWidget* parent = nullptr);
    void setData(const Data& data) override;
private:
    QLabel* m_stickersLabel;
    QLabel* m_stickersValue;
};

#endif // MARKINGINSPECTIONWIDGET_H
