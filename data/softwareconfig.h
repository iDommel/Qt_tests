
#ifndef SOFTWARECONFIG_H
#define SOFTWARECONFIG_H

#include <string>

class SoftwareConfig
{
public:
    SoftwareConfig();
    /// aircraft logo file name
    std::string companyLogoFileName;

    /// (false) desactivate or (true) activate the utilization of imperial units
    bool useImperialSystem;

    /// (false) disable or (true) enable using CUDA
    bool useCuda;

    /// (false) disable or (true) enable the possibility to use admin mode
    bool useableModeAdmin;

    /// (false) disable or (true) enable the possibility to use marking mode
    bool useableModeMarking = false;

    /// (false) disable or (true) enable the possibility to use paint mode
    bool useableModePaint = false;

    /// (false) disable or (true) enable the possibility to use defect mode
    bool useableModeDefect = false;

    /// (false) disable or (true) enable the possibility to use photogrammetry
    /// mode
    bool useableModePhotogrammetry = false;

    /// (false) disable or (true) enable the possibility to use lightning mode
    bool useableModeLightning = false;

    /// (false) disable or (true) enable the possibility to use dent mode
    bool useableModeDent = false;

    /// Seeking for local sessions in this directory
    std::string localSessionsDir;

    /// default value to use for blue gain if color balance estimation is
    /// disabled
    float defaultBGain;

    /// default value to use for red gain if color balance estimation is
    /// disabled
    float defaultRGain;

    /// Directory where pdf are saved and can be accessed by users : mainly used
    /// for AFI Release otherwise leave it blank
    std::string inspectionPdfsDir;
};

#endif // SOFTWARECONFIG_H
