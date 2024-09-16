
#include "cmdline.hpp"




extern fb_info fb;
static ramfb ram;
static text text;




void cmdline::print(char* status) {
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



// static inline char* array_adder(size_t size) {
//     char* array = kmalloc(size);
//     // if (!array) {
//     //     return NULL;  
//     // }

//     for (int jj = 0; jj < size - 1; jj++) {
//         array[jj] = '\0';  
//     }
//     static char former_char;

//     int index = 0;
//     while (index < (size - 1)) { 

//         char character = read_key();
//         // if(character == former_char){
//         //     continue;
//         // }
//         if(character == NULL){

//             continue;
//         }
//         if (character == '\n') {
//             array[index] = '\0';  
//             break;
//         }
//         array[index] = character; 
//         char temp[2];
//         temp[0] = character;
//         temp[1] = '\0';  
//         index++;
//         kputs(1 + j, 20 * i, temp, 1, 0x000000);
//         j += 10;
//         former_char = character;
        
//     }

//     if (index == (size - 1)) {
//         array[size - 1] = '\0';  
//     }

//     return array;
// }


// char* shell_get(size_t size) {
//     static bool init = false;
//     if(!init){
//         krect(0, 40, fb.fb_height - 40, fb.fb_width, 0xffffff);
//         init = true;
//     }               
//     if ((10 + j) >= fb.fb_width) {
//         i++;
//         j = 0;
//     }
//     kputs(1 + j, 20 * i, ">   ", 1, 0x000000);
//     j += 10;
//     //j += 5;
//     //i++;
//     char* result = array_adder(size);
//     // for(int i = 0; i < size; i++){
//     //     shell_print("ARRAY");
//     //     shell_print(&result[i]);
//     // }
//     //kputs(90, 10, result, 2, 0x9905C2);
    
//     //j = 0;
//     i++;
//     if ((20 * i) >= fb.fb_height) {
//         krect(0, 40, fb.fb_height - 40, fb.fb_width, 0xffffff);
//         i = 3;
//     } 
//     shell_print("");
//     return result;
// }



