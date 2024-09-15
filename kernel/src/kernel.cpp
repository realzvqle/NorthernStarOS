#include "uart.hpp"
#include "hal.hpp"
#include "ramfb.hpp"
#include "text.hpp"

fb_info fb;



extern "C" void kmain(){
    
    uart urt;
    HAL hal;
    ramfb ram;
    text text;
    ram.setup_fb();
    ram.ramfb_setup(&urt, &hal, &fb);

    uint8_t white[3] = {255, 255, 255}; 
    ram.clear_background(white);
    uint8_t black[3] = {0, 0, 0}; 
    text.draw_text(10, 10, "Hello World!", 1, black);
    hal.halt_system();
}