#include "hal.hpp"












void HAL::halt_system(){
    for(;;){
        __asm__ ("wfi");
    }
}
