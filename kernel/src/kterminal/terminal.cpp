
#include "terminal.hpp"




extern fb_info fb;
extern ramfb ram;
extern text text;




void terminal::print(const char* status) {
    static bool init = false;
    if(!init){
        uint8_t color[3];
        RGB(color, 255, 255, 255);
        draw_rect(0, 40, fb.fb_height - 40, fb.fb_width, color);
        init = true;
    }               
    if ((10 + j) >= fb.fb_width) {
        i++;
        j = 0;
    }
    uint8_t color[3];
    RGB(color, 0, 0, 0);
    draw_text(1 + j, 20 * i, status, 1, color);
    j += 5;
    i++;
    j = 0;
    if ((20 * i) >= fb.fb_height) {
        uint8_t color[3];
        RGB(color, 255, 255, 255);
        draw_rect(0, 40, fb.fb_height - 40, fb.fb_width, color);
        i = 3;
    } 
}






