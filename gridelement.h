#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H

#include <QWidget>
namespace Ui {
class GridElement;
}

class Data;

class GridElement : public QWidget
{
    Q_OBJECT

public:
    explicit GridElement(QWidget *parent = nullptr);
    ~GridElement();
    void setData(const Data &data);
private:
    Ui::GridElement *ui;
};

#endif // GRIDELEMENT_H
