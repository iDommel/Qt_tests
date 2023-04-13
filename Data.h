
#ifndef DATA_H
#define DATA_H
#include <QString>
#include <QDateTime>

enum InspectionType {
    PaintInspection = 0,
    MarkingInspection = 1,
    DefectInspection = 2,
    LightningInspection = 3,
    DentInspection = 4,
    PhotogrammetryInspection = 5,
    CorrosionInspection = 6,
    NoiseInspection = 7,
    CleanlinessInspection = 8,
    OilInspection = 9,
    OtherInspection = 10
};

InspectionType generateRandomInspectionType();
QString getInspectionName(InspectionType type);

class Data {
public:
    Data() = default;

    // Informations regarding paint inspection
    bool paintInspectionDone = false;
    float paintInspectionProgression = 0.0;
    QDateTime paintInspectionDate;

    //  Informations regarding marking inspection
    bool markingInspectionDone = false;
    float markingInspectionProgression = 0.0;
    QDateTime markingInspectionDate;
    int amountOfAnalyzedStickers = 0;
    int amountOfValidatedStickers = 0;

    //  Informations regarding defect inspection
    bool defectInspectionDone = false;
    float defectInspectionProgression = 0.0;
    QDateTime defectInspectionDate;
    int amountOfAnalyzedZois = 0;
    int amountOfValidatedZois = 0;
    int amountOfCheckedImages = 0;

    //  Informations regarding lightning inspection
    bool lightningInspectionDone = false;
    float lightningInspectionProgression = 0.0;
    QDateTime lightningInspectionDate;
    int amountOfAnalyzedLightning = 0;
    int amountOfValidatedLightning = 0;
    int amountOfCheckedLightningImages = 0;

    //Informations regarding dent inspection
    bool dentInspectionDone = false;
    float dentInspectionProgression = 0.0;
    QDateTime dentInspectionDate;
    int amountOfAnalyzedDent = 0;
    int amountOfValidatedDent = 0;
    int amountOfCheckedDentImages = 0;

    //Informations regarding photogrammetry inspection
    bool photogrammetryInspectionDone = false;
    float photogrammetryInspectionProgression = 0.0;
    QDateTime photogrammetryInspectionDate;
    int amountOfAnalyzedPhotogrammetry = 0;
    int amountOfValidatedPhotogrammetry = 0;
    int amountOfCheckedPhotogrammetryImages = 0;
};

Data generateRandomInspectionSummary();

#endif // DATA_H
