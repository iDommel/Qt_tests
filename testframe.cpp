#include "testframe.h"
#include "ui_testframe.h"

TestFrame::TestFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TestFrame)
{
    ui->setupUi(this);
    initialText = ui->label->text();

    connect(ui->pushButton, &QPushButton::clicked, this, &TestFrame::buttonA_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TestFrame::buttonB_clicked);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &TestFrame::buttonOk_clicked);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &TestFrame::buttonCancel_clicked);
}

TestFrame::~TestFrame()
{
    delete ui;
}

void TestFrame::setLabelText(const QString& text) {
    ui->label->setText(text);
}

void TestFrame::buttonA_clicked()
{
    ui->label->setText("Button A clicked");
}

void TestFrame::buttonB_clicked()
{
    ui->label->setText("Button B clicked");
}

void TestFrame::buttonCancel_clicked()
{
    ui->label->setText(initialText);
}

void TestFrame::buttonOk_clicked()
{
    ui->label->setText(ui->label->text() + QString(" Ok!"));
}
