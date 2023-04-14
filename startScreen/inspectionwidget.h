#ifndef INSPECTIONWIDGET_H
#define INSPECTIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QPushButton>
namespace Ui
{
    class InspectionWidget;
}

class Data;
class Data;
enum InspectionType;

class InspectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InspectionWidget(InspectionType inspectionType, QWidget* parent = nullptr);
    ~InspectionWidget();
    virtual void setData(const Data& data);

protected:
    Ui::InspectionWidget* ui;
    InspectionType type;

    QLabel* m_progressStatusLabel;
    QLabel* m_progressStatusValue;
    QLabel* m_progressLabel;
    QPushButton* m_buttonLocal;
    QPushButton* m_buttonCloud;
    QPushButton* m_buttonNew;
    QLCDNumber* m_progressAmount;

private:
    void generateButtonLayout();
    void generateInfoLayout();
};

#endif  // INSPECTIONWIDGET_H
