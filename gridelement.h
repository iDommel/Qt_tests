#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QHBoxLayout>
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
    virtual void setData(const Data &data);
protected:
    Ui::GridElement *ui;
    InspectionType type;

    QLabel* m_progressStatusLabel;
    QLabel* m_progressStatusValue;
    QLabel* m_progressLabel;
    QLCDNumber* m_progressAmount;
    QHBoxLayout* m_horizontalLayout;
private:
};

#endif // GRIDELEMENT_H
