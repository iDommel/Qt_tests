#ifndef JSONDATA_H
#define JSONDATA_H
#include "nlohmann/json.hpp"
#include <QDateTime>

class JSONData
{
public:
    JSONData() = default;

    float totalAmountOfImages;

    // Images offsets
    nlohmann::json imageOffsetsPayload;

    // Defect inspection
    nlohmann::json defectSceneObjectsPayload;
    nlohmann::json defectPayload;
    nlohmann::json defectGarbagePayload = nlohmann::json::array();
    nlohmann::json defectCheckerPayload;
    nlohmann::json defectRefinerThresholds;
    QDateTime defectInspectionDate;

    // Paint inspection
    nlohmann::json paintSceneObjectsPayload;
    nlohmann::json paintPayload;
    //    PaintUserData paintUserData;
    //    std::vector<PaintUserDrawing> paintUserDrawingsByVignette;
    nlohmann::json paintRefinerThresholds;
    QDateTime paintInspectionDate;

    // Marking inspection
    nlohmann::json markingSceneObjectsPayload;
    nlohmann::json markingPayload;
    nlohmann::json markingRefinerThresholds;
    QDateTime markingInspectionDate;

    // Lightning inspection
    nlohmann::json lightningSceneObjectsPayload;
    nlohmann::json lightningPayload;
    nlohmann::json lightningCheckerPayload;
    nlohmann::json lightningRefinerThresholds;
    QDateTime lightningInspectionDate;

    // Dent inspection
    nlohmann::json dentSceneObjectsPayload;
    nlohmann::json dentPayload;
    nlohmann::json dentCheckerPayload;
    nlohmann::json dentRefinerThresholds;
    QDateTime dentInspectionDate;

    // Photogrammetry inspection
    nlohmann::json photogrammetrySceneObjectsPayload;
    nlohmann::json photogrammetryPayload;
    nlohmann::json photogrammetryCheckerPayload;
    nlohmann::json photogrammetryMarkerPayload;
    nlohmann::json photogrammetryRefinerThresholds;
    QDateTime photogrammetryInspectionDate;
};

#endif // JSONDATA_H
