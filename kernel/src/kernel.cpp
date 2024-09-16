#include "uart.hpp"
#include "hal.hpp"
#include "ramfb.hpp"
#include "text.hpp"
#include "cmdline.hpp"
#include "kmalloc.hpp"


fb_info fb;



extern "C" void kmain(){
    
    uart urt;
    urt.print("\n------------------------\nzivOS SHELL BUILD INDEV\n------------------------\n");
    urt.print("Press 'Shift + P' to enter (working on getting enter to work)\n\n");

    HAL hal;
    ramfb ram;
    cmdline cmdline;
    text text;
    ram.setup_fb();
    ram.ramfb_setup(&urt, &hal, &fb);

    memalloc mem;
    uint8_t color[3];
    ram.RGB(color, 0, 255, 255);
    text.draw_text(0, 0, "zivOS Build INDEV", 1, color);
    mem.heap_init();

    cmdline.print("hi!");
    
    urt.print("\n\n");

    while(1){
        char* idk = urt.gets(512);
        cmdline.print(idk);
        mem.free(idk);
    }
    

    hal.halt_system();
}   