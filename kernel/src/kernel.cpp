#include "drivers/UART/uart.hpp"
#include "drivers/ramfb/ramfb.hpp"
#include "text.hpp"
#include "kterminal/terminal.hpp"
#include "malloc/kmalloc.hpp"
#include "kernel.hpp"
#include "kstdlib.hpp"
fb_info fb;
text text;
ramfb ram;


void kernel::kernel_suicide(char* error){
    uint8_t white[3] = {255, 255, 255};
    uint8_t purple[3] = {255, 0, 255};   
    ram.clear_background(purple);
    text.draw_text(700, 600, ":(", 10, white);
    text.draw_text(10, 10, "NorthernStarOS has ran into an issue and has been shutdown to prevent damage", 1, white);
    text.draw_text(10, 20, "please contact zvqle with this error code", 1, white);
    text.draw_text(10, 60, error, 1, white);
    halt_system();
}

extern "C" void kmain(){
    
    uart urt;
    urt.print("\n------------------------\nNorthernStarOS SHELL BUILD INDEV\n------------------------\n");
    urt.print("Press 'Shift + P' to enter (working on getting enter to work)\n\n");

    HAL hal;
    terminal term;
    
    ram.setup_fb();
    ram.ramfb_setup(&urt, &hal, &fb);

    memalloc mem;
    kstdlib stdlib;
    uint8_t color[3];
    ram.RGB(color, 0, 255, 255);
    text.draw_text(0, 0, stdlib.os_version(), 1, color);
    mem.heap_init();

    term.print("hi!");
    
    urt.print("\n\n");

    while(1){
        char* idk = urt.gets(512);
        term.print(idk);
        mem.free(idk);
    }
    

    hal.halt_system();
}   