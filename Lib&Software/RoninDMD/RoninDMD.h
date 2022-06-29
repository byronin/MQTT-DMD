


#ifndef RoninDMD_H
#define RoninDMD_H

#include "Bitmap.h"
#include <SPI.h>

class RoninDMD : public Bitmap
{
public:
    explicit RoninDMD(int widthPanels = 1, int heightPanels = 1);
    ~RoninDMD();

    bool doubleBuffer() const { return _doubleBuffer; }
    void setDoubleBuffer(bool doubleBuffer);
    void swapBuffers();
    void swapBuffersAndCopy();

    void loop();
    void refresh();

    void begin();

    void setBrightness(uint16_t crh);
    static Color fromRGB(uint8_t r, uint8_t g, uint8_t b);

private:
    RoninDMD(const RoninDMD &other) : Bitmap(other) {}
    RoninDMD &operator=(const RoninDMD &) { return *this; }
    
    uint16_t cr;
    bool _doubleBuffer;
    uint8_t phase;
    uint8_t *fb0;
    uint8_t *fb1;
    uint8_t *displayfb;
    unsigned long lastRefresh;
};

#endif
