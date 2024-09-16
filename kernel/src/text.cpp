#include "text.hpp"





void text::draw_char(int x, int y, int size, char c, uint8_t color[3]){
    if (c < 32 || c > 126) {
        return;
    }

    const uint8_t *bitmap = kfont[c - 32]; 

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            if (bitmap[i] & (1 << j)) { 
                draw_rect(x + j * size, y + i * size, size, size, color);
            }
        }
    }
}

void text::draw_text(int x, int y, const char* s, int size, uint8_t color[3]){
    int c;
    int current_x = x; 
    int current_y = y;
    int line_height = size * 10; 

    while ((c = *s++)) { 
        if (c == '\n') {
            current_y += line_height; 
            current_x = x; 
        } else {
            draw_char(current_x, current_y, size, c, color);
            current_x += size * 10; 
        }
    }
}