
#ifndef DATA_H
#define DATA_H
#include <QDateTime>
#include <QMap>
#include <QString>

enum InspectionType
{
    PaintInspection = 0,
    MarkingInspection = 1,
    DefectInspection = 2,
    LightningInspection = 3,
    DentInspection = 4,
    PhotogrammetryInspection = 5,
    OtherInspection = 6
};

InspectionType generateRandomInspectionType();
QString getInspectionName(InspectionType type);

class InspectionData
{
public:
    InspectionData() = default;

    bool inspectionDone = false;
    float inspectionProgression = 0.0;
    QDateTime inspectionDate;

    /// @brief This will stay at -1 for paint and markings
    int analyzedObjects = -1;
    /// @brief This will stay at -1 for paint and markings
    int validatedObject = -1;
};

class Data
{
public:
    InspectionData getInspectionData(const InspectionType &) const;
    QMap<InspectionType, InspectionData> inspectionData = {{PaintInspection, {}},     {MarkingInspection, {}}, {DefectInspection, {}},
                                                           {LightningInspection, {}}, {DentInspection, {}},    {PhotogrammetryInspection, {}},
                                                           {OtherInspection, {}}};
};

Data generateRandomNewData();
InspectionData generateRandomInspectionData();

#endif // DATA_H
