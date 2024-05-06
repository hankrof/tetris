#ifndef __GETAC_KEY_DEVICE_H__
#define __GETAC_KEY_DEVICE_H__
#include <string>
#include <vector>
namespace getac
{
    struct BusInputDevice
    {
    public:
        static BusInputDevice parse(std::string context);
        std::string getEventName() const;
        std::string bus;
        std::string name;
        std::string phy;
        std::string sysfs;
        std::string uniq;
        std::string handlers;
        std::vector<std::string> bitmap;
    };

    class KeyDeviceFinder
    {
    public:
        static std::vector<BusInputDevice> enumBusInputDevices();
		static int getFd(std::string inputName);
    };
}
#endif

