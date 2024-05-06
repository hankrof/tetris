#ifndef __VIEW_IO_H__
#define __VIEW_IO_H__
namespace tetris
{
    enum KeyCode
    {
        TKeyNone,
        TKeyLeft,
        TKeyRight,
        TKeySpace,
        TKeyUp,
        TKeyDown
    };

    void openKeyDevice();
    void closeKeyDevice();
    KeyCode readKey();
}
#endif
