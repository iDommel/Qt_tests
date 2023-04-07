#ifndef TESTFRAME_H
#define TESTFRAME_H

#include <QFrame>

namespace Ui {
class TestFrame;
}

class TestFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TestFrame(QWidget *parent = nullptr);
    ~TestFrame();

    void setLabelText(const QString &text);
private slots:
    void buttonA_clicked();
    void buttonB_clicked();
    void buttonCancel_clicked();
    void buttonOk_clicked();
private:
    Ui::TestFrame *ui;
    QString initialText;
};

#endif // TESTFRAME_H
