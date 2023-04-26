#include "Data.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <stdexcept>
#include <string>

InspectionType generateRandomInspectionType()
{
    srand(time(nullptr));                            // seed rand() with current time
    return static_cast<InspectionType>(rand() % 11); // generate random integer between 0 and 10, and cast it
                                                     // to InspectionType
}

QString getInspectionName(InspectionType type)
{
    switch(type)
    {
        case InspectionType::PaintInspection:
            return "Paint Inspection";
        case InspectionType::MarkingInspection:
            return "Marking Inspection";
        case InspectionType::DefectInspection:
            return "Defect Inspection";
        case InspectionType::LightningInspection:
            return "Lightning Inspection";
        case InspectionType::DentInspection:
            return "Dent Inspection";
        case InspectionType::PhotogrammetryInspection:
            return "Photogrammetry Inspection";
        case InspectionType::OtherInspection:
            return "Other Inspection";
        default:
            return "Invalid Inspection Type"; // return an error message if the
                                              // type is invalid
    }
}

InspectionData generateRandomInspectionData()
{
    InspectionData data;
    std::srand(std::time(nullptr)); // Seed the random number generator

    // Generate random values for the inspection data
    data.inspectionDone = std::rand() % 2 == 0;                                        // Random bool value
    data.inspectionProgression = static_cast<float>(std::rand()) / RAND_MAX;           // Random float value between 0 and 1
    data.inspectionDate = QDateTime::currentDateTime().addDays(std::rand() % 30 - 15); // Random date within 30 days from now
    data.analyzedObjects = std::rand() % 101;                                          // Random int value between 0 and 100
    data.validatedObject = std::rand() % 101;                                          // Random int value between 0 and 100

    return data;
}

Data generateRandomNewData()
{
    Data data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);
    for(auto &inspection : data.inspectionData)
    {
        inspection.analyzedObjects = static_cast<int>(dist(gen) * 100);
        inspection.inspectionDate = QDateTime::currentDateTime().addDays(std::rand() % 30 - 15);
        inspection.inspectionDone = std::rand() % 2 == 0;
        inspection.inspectionProgression = static_cast<float>(dist(gen));
        inspection.validatedObject = static_cast<int>(dist(gen) * 100);

        // InspectionData{std::rand() % 2 == 0, static_cast<float>(dist(gen)), QDateTime::currentDateTime().addDays(std::rand() % 30 - 15),
        //                             static_cast<int>(dist(gen) * 10), static_cast<int>(dist(gen) * 10)};
    }
    return data;
}

InspectionData Data::getInspectionData(const InspectionType &type) const
{
    if(!inspectionData.contains(type)) { throw std::invalid_argument("Invalid inspection type"); }
    return inspectionData[type];
}
