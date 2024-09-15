#include "uart.hpp"
#include "hal.hpp"
#include "ramfb.hpp"


fb_info fb;



extern "C" void kmain(){
    
    uart urt;
    HAL hal;
    ramfb ram;
    ram.setup_fb();
    ram.ramfb_setup(&urt, &hal, &fb);
    uint8_t pixel[3] = {255, 25, 255}; 
    ram.draw_rect(4,10, 90, 90, pixel);
    hal.halt_system();
}