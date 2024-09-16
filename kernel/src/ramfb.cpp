#include "ramfb.hpp"
#include "qemujunk.h"
#include <stdatomic.h>

extern fb_info fb;



void ramfb::setup_fb(){
    extern uint64_t stack_top;
    uint64_t heap_start = (uint64_t)&stack_top;
    uint32_t fb_width = WIDTH;
    uint32_t fb_height = HEIGHT;
    uint32_t fb_bpp = 4;
    uint32_t fb_stride = fb_bpp * fb_width;
    


    fb = {
        .fb_addr = heap_start,
        .fb_width = fb_width,
        .fb_height = fb_height,
        .fb_bpp = fb_bpp,

        .fb_stride = fb_stride,
        .fb_size = fb_stride * fb_height,
    };

}

void ramfb::ramfb_setup(uart* uart, HAL* hal, fb_info* fb){
    uint32_t select = qemu_cfg_find_file();

    if(select == 0){
        uart->print("Failed Getting QEMU CFG File");
        hal->halt_system();
        
    }
    struct QemuRAMFBCfg cfg = {
        .addr   = bswap64(fb->fb_addr),
        .fourcc = bswap32(DRM_FORMAT_XRGB8888),
        .flags  = bswap32(0),
        .width  = bswap32(fb->fb_width),
        .height = bswap32(fb->fb_height),
        .stride = bswap32(fb->fb_stride),
    };
    qemu_cfg_write_entry(&cfg, select, sizeof(cfg));
    uart->print("RamFB Setup Successful");

}


void ramfb::memcpy_(void *dest, void *src, uint64_t n){
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
  
    for (int i=0; i<n; i++)
        cdest[i] = csrc[i];
}

void ramfb::write_pixel(fb_info *fb, uint16_t x, uint16_t y, uint8_t pixel[3]) {
    uintptr_t offset = (y * fb->fb_stride) + (x * fb->fb_bpp);

    void* target_address = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(fb->fb_addr) + offset);

    memcpy_(target_address, pixel, 3);

}

void ramfb::draw_rect(int x, int y, int height, int width, uint8_t color[3]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            write_pixel(&fb, x + j, y + i, color);
        }
    }
}

void ramfb::clear_background(uint8_t color[3]){
    draw_rect(5, 5, fb.fb_height, fb.fb_width, color);
}

void ramfb::RGB(uint8_t* color, uint8_t r, uint8_t g, uint8_t b){
    color[0] = b;
    color[1] = g;
    color[2] = r;
}