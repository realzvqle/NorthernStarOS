#include "hal.hpp"
#include "ramfb.hpp"
#include "text.hpp"
#include <cstdint>








static ramfb rmfb;
static text text;



void HAL::halt_system(){
    for(;;){
        __asm__ ("wfi");
    }
}

void HAL::kernel_suicide(char* error){
    
    uint8_t white[3] = {255, 255, 255};
    uint8_t purple[3] = {255, 0, 255};

    
    rmfb.clear_background(purple);
    text.draw_text(700, 600, ":(", 10, white);
    text.draw_text(10, 10, "Nightpane has ran into an issue and has been shutdown to prevent damage", 1, white);
    text.draw_text(10, 20, "please contact zvqle with this error code", 1, white);
    text.draw_text(10, 60, error, 1, white);


    halt_system();


}
