#include "gridelement.h"
#include "ui_gridelement.h"
#include "Data.h"

GridElement::GridElement(InspectionType inspectionType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridElement)
{
    ui->setupUi(this);
    setInspectionType(inspectionType);
}

GridElement::~GridElement()
{
    if (ui)
        delete ui;
}

void GridElement::setInspectionType(InspectionType inspectionType)
{
    type = inspectionType;
    // hide everything by default
    ui->PaintProgressionValue->hide();
    ui->PaintProgressionLabel->hide();
    ui->PaintStatusValue->hide();
    ui->PaintStatusLabel->hide();
    ui->DefectStatusLabel->hide();
    ui->DefectStatusValue->hide();
    ui->MarkingStatusLabel->hide();
    ui->MarkingStatusValue->hide();
    ui->DentStatusLabel->hide();
    ui->DentStatusValue->hide();
    switch (inspectionType) {
        case PaintInspection:
            ui->PaintProgressionValue->show();
            ui->PaintStatusLabel->show();
        break;
        case MarkingInspection:
            ui->MarkingStatusLabel->show();
            ui->MarkingStatusValue->show();
        break;
        case DentInspection:
            ui->DentStatusLabel->show();
            ui->DentStatusValue->show();
        break;
        case DefectInspection:
            ui->DefectStatusLabel->show();
            ui->DefectStatusValue->show();
        break;
        default:
            break;
    }
}

void GridElement::setData(const Data &data)
{
    ui->InspectionType->setText(getInspectionName(type));
    switch (type) {
        case PaintInspection:
            ui->PaintProgressionValue->display(data.paintInspectionProgression);
            ui->PaintStatusLabel->setText(data.paintInspectionDone ? "Done" : "Not done");
            break;
        case MarkingInspection:
            ui->MarkingStatusValue->setText(data.markingInspectionDone ? "Done" : "Not done");
            break;
        case DefectInspection:
            ui->DefectStatusValue->setText(data.defectInspectionDone ? "Done" : "Not done");
            break;
        case DentInspection:
            ui->DentStatusValue->setText(data.dentInspectionDone ? "Done" : "Not done");
            break;
        default:
            break;
    }
}
