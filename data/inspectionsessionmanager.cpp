
#include "inspectionsessionmanager.h"

InspectionSessionManager::InspectionSessionManager() {}

/// @brief This function fills the previous inspection summary with the data
/// from the previous inspection.
/// @param prevInspectionData The json data from the previous inspection.
/// @param prevInspectionSummary the data structure that will be filled with the
/// parsed json data
/// @param sc the software configuration
/// @param customization the customization
/// @return true if the previous inspection summary was filled, false otherwise
bool InspectionSessionManager::fillPreviousInspectionSummary(
    JSONData &prevInspectionData, Data &prevInspectionSummary,
    SoftwareConfig &sc, Customization *customization)
{
    if(prevInspectionData.defectGarbagePayload.size() == 0)
    {
        return false; // aaaa
    }
}
