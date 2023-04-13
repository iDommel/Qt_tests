
#ifndef DEFECTINSPECTIONWIDGET_H
#define DEFECTINSPECTIONWIDGET_H
#include <QLabel>
#include <QLCDNumber>
#include <QProgressBar>
#include <QHBoxLayout>
#include "gridelement.h"

namespace Ui {
    class GridElement;
}

class DefectInspectionWidget : public GridElement
{
public:
    DefectInspectionWidget(QWidget* parent = nullptr);
    void setData(const Data& data) override;
private:
};

#endif // DEFECTINSPECTIONWIDGET_H
