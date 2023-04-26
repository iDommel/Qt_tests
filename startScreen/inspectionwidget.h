#ifndef INSPECTIONWIDGET_H
#define INSPECTIONWIDGET_H

#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

namespace Ui
{
class InspectionWidget;
}

class Data;
class Data;
enum class InspectionType;

class InspectionWidget : public QWidget
{
    Q_OBJECT

public:
    // Test comment on the same line
    explicit InspectionWidget(InspectionType inspectionType, QWidget *parent = nullptr);
    ~InspectionWidget();
    virtual void setData(const Data &data);
    // Test comment on a different line

protected:
    Ui::InspectionWidget *ui;
    InspectionType type;

    QLabel *m_progressStatusLabel;
    QLabel *m_progressStatusValue;
    QLabel *m_progressLabel;
    QPushButton *m_buttonLocal;
    QPushButton *m_buttonCloud;
    QPushButton *m_buttonNew;
    QLCDNumber *m_progressAmount;

private:
    void generateButtonLayout();
    void generateInfoLayout();
};

#endif // INSPECTIONWIDGET_H
