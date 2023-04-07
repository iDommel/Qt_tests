
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

    // Informations regarding corrosion inspection
    bool corrosionInspectionDone = false;
    float corrosionInspectionProgression = 0.0;
    QDateTime corrosionInspectionDate;
    int amountOfAnalyzedCorrosion = 0;
    int amountOfValidatedCorrosion = 0;
    int amountOfCheckedCorrosionImages = 0;

    // Informations regarding noise inspection
    bool noiseInspectionDone = false;
    float noiseInspectionProgression = 0.0;
    QDateTime noiseInspectionDate;
    int amountOfAnalyzedNoise = 0;
    int amountOfValidatedNoise = 0;
    int amountOfCheckedNoiseImages = 0;

    // Informations regarding oil inspection
    bool oilInspectionDone = false;
    float oilInspectionProgression = 0.0;
    QDateTime oilInspectionDate;
    int amountOfAnalyzedOil = 0;
    int amountOfValidatedOil = 0;
    int amountOfCheckedOilImages = 0;

    // Informations regarding cleanliness inspection
    bool cleanlinessInspectionDone = false;
    float cleanlinessInspectionProgression = 0.0;
    QDateTime cleanlinessInspectionDate;
    int amountOfAnalyzedCleanliness = 0;
    int amountOfValidatedCleanliness = 0;
    int amountOfCheckedCleanlinessImages = 0;
};

Data generateRandomInspectionSummary();
QString getInspectionName(InspectionType type);
InspectionType generateRandomInspectionType();

#endif // DATA_H
