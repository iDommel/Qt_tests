#ifndef MYGRIDWIDGET_H
#define MYGRIDWIDGET_H

#include <QWidget>

namespace Ui
{
class MyGridWidget;
}
class Data;
class Data;

class MyGridWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyGridWidget(QWidget *parent = nullptr);
    ~MyGridWidget();
    void setData(const Data &data);

private:
    Ui::MyGridWidget *ui;
    int m_row;
    QVector<Data> m_data;
};

#endif // MYGRIDWIDGET_H
