#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H

#include <QWidget>
namespace Ui {
class GridElement;
}

class Data;
enum InspectionType;

class GridElement : public QWidget
{
    Q_OBJECT

public:
    explicit GridElement(InspectionType inspectionType, QWidget *parent = nullptr);
    ~GridElement();
    void setData(const Data &data);
    void setInspectionType(InspectionType inspectionType);
private:
    Ui::GridElement *ui;
    InspectionType type;
};

#endif // GRIDELEMENT_H
