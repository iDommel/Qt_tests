
#ifndef MARKINGINSPECTIONWIDGET_H
#define MARKINGINSPECTIONWIDGET_H

#include <startScreen/inspectionwidget.h>

class MarkingInspectionWidget : public InspectionWidget
{
public:
    MarkingInspectionWidget(QWidget *parent = nullptr);
    void setData(const Data &data) final;

private:
    void generateStickersLayout();

    QLabel *m_stickersValue;
    QLabel *m_stickersLabel;
};

#endif // MARKINGINSPECTIONWIDGET_H
