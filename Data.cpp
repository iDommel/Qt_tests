#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include "data.h"

InspectionType generateRandomInspectionType() {
    srand(time(nullptr)); // seed rand() with current time
    return static_cast<InspectionType>(rand() % 11); // generate random integer between 0 and 10, and cast it to InspectionType
}

QString getInspectionName(InspectionType type) {
    switch(type) {
        case PaintInspection:
            return "Paint Inspection";
        case MarkingInspection:
            return "Marking Inspection";
        case DefectInspection:
            return "Defect Inspection";
        case LightningInspection:
            return "Lightning Inspection";
        case DentInspection:
            return "Dent Inspection";
        case PhotogrammetryInspection:
            return "Photogrammetry Inspection";
        case CorrosionInspection:
            return "Corrosion Inspection";
        case NoiseInspection:
            return "Noise Inspection";
        case CleanlinessInspection:
            return "Cleanliness Inspection";
        case OilInspection:
            return "Oil Inspection";
        case OtherInspection:
            return "Other Inspection";
        default:
            return "Invalid Inspection Type"; // return an error message if the type is invalid
    }
}

Data generateRandomInspectionSummary()
{
    Data data;

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Distribution for boolean values
    std::bernoulli_distribution bool_dist(0.5);

    // Distribution for float values between 0 and 1
    std::uniform_real_distribution<float> float_dist(0.0, 1.0);

    // Distribution for integer values between 0 and 100
    std::uniform_int_distribution<int> int_dist(0, 100);

    // Generate random data for paint inspection
    data.paintInspectionDone = bool_dist(gen);
    data.paintInspectionProgression = float_dist(gen);
    data.paintInspectionDate = QDateTime::currentDateTime().addDays(-int_dist(gen));

    // Generate random data for marking inspection
    data.markingInspectionDone = bool_dist(gen);
    data.markingInspectionProgression = float_dist(gen);
    data.markingInspectionDate = QDateTime::currentDateTime().addDays(-int_dist(gen));
    data.amountOfAnalyzedStickers = int_dist(gen);
    data.amountOfValidatedStickers = int_dist(gen);

    // Generate random data for defect inspection
    data.defectInspectionDone = bool_dist(gen);
    data.defectInspectionProgression = float_dist(gen);
    data.defectInspectionDate = QDateTime::currentDateTime().addDays(-int_dist(gen));
    data.amountOfAnalyzedZois = int_dist(gen);
    data.amountOfValidatedZois = int_dist(gen);
    data.amountOfCheckedImages = int_dist(gen);

    // Generate random data for lightning inspection
    data.lightningInspectionDone = bool_dist(gen);
    data.lightningInspectionProgression = float_dist(gen);
    data.lightningInspectionDate = QDateTime::currentDateTime().addDays(-int_dist(gen));
    data.amountOfAnalyzedLightning = int_dist(gen);
    data.amountOfValidatedLightning = int_dist(gen);
    data.amountOfCheckedLightningImages = int_dist(gen);

    // Generate random data for dent inspection
    data.dentInspectionDone = bool_dist(gen);
    data.dentInspectionProgression = float_dist(gen);
    data.dentInspectionDate = QDateTime::currentDateTime().addDays(-int_dist(gen));
    data.amountOfAnalyzedDent = int_dist(gen);
    data.amountOfValidatedDent = int_dist(gen);
    data.amountOfCheckedDentImages = int_dist(gen);

    // Generate random data for photogrammetry inspection
    data.photogrammetryInspectionDone = bool_dist(gen);
    data.photogrammetryInspectionProgression = float_dist(gen);
    data.photogrammetryInspectionDate = QDateTime::currentDateTime().addDays(-int_dist(gen));
    data.amountOfAnalyzedPhotogrammetry = int_dist(gen);
    data.amountOfValidatedPhotogrammetry = int_dist(gen);
    data.amountOfCheckedPhotogrammetryImages = int_dist(gen);

    return data;
}
