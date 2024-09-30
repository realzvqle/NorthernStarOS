#ifndef RAMFB_HPP_INCLUDED
#define RAMFB_HPP_INCLUDED







#include "hal.hpp"
#include "mmio.hpp"
#include "uart.hpp"
#include <cstdint>



#define WIDTH 1600
#define HEIGHT 900

typedef struct _fb{
    uint64_t fb_addr;
    uint32_t fb_width;
    uint32_t fb_height;
    uint32_t fb_bpp;
    uint32_t fb_stride;
    uint32_t fb_size;
} fb_info;


class ramfb : public mmio {
    private:
        void memcpy_(void *dest, void *src, uint64_t n);
    public:
        void setup_fb();
        void draw_rect(int x, int y, int height, int width, uint8_t color[3]);
        void ramfb_setup(uart* uart, HAL* hal, fb_info* fb);
        void write_pixel(fb_info* fb, uint16_t x, uint16_t y, uint8_t pixel[4]);
        void clear_background(uint8_t color[3]);
        void RGB(uint8_t* color, uint8_t r, uint8_t g, uint8_t b);
};

















#endif