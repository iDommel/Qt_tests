#include "gridelement.h"
#include "ui_gridelement.h"
#include "Data.h"

GridElement::GridElement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridElement)
{
    ui->setupUi(this);
}

GridElement::~GridElement()
{
    if (ui)
        delete ui;
}

void GridElement::setData(const Data &data)
{
    ui->FirstnameValue->setText(data.firstName);
    ui->LastnameValue->setText(data.lastName);
    ui->AgeValue->display(data.age);
}
