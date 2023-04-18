
#ifndef INSPECTIONSESSIONMANAGER_H
#define INSPECTIONSESSIONMANAGER_H

#include "Data.h"
#include "customization.h"
#include "jsondata.h"
#include "softwareconfig.h"

class InspectionSessionManager
{
public:
    InspectionSessionManager();
    static bool fillPreviousInspectionSummary(JSONData &prevInspectionData,
                                              Data &prevInspectionSummary,
                                              SoftwareConfig &sc,
                                              Customization *customization);
};

#endif // INSPECTIONSESSIONMANAGER_H
