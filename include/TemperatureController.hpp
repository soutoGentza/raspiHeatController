#include <string>

class CTempController{

    const std::string CORE_TEMP_FILE = "/sys/class/thermal/thermal_zone0/temp";

public:
    CTempController();

    float getCurrentCoreTemp() const;

private:

};