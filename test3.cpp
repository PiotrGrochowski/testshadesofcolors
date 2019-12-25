#include <windows.h>
#include <stdint.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD start = {0, 0};
    DWORD b = 0;
    CHAR_INFO screen[2000];
    for (int i=0; i<2000; i+=80){
        for (int k=0; k<16; k++){
            screen[i+k].Char.AsciiChar=32;
        }
        for (int k=16; k<32; k++){
            screen[i+k].Char.AsciiChar=176;
        }
        for (int k=32; k<48; k++){
            screen[i+k].Char.AsciiChar=177;
        }
        for (int k=48; k<64; k++){
            screen[i+k].Char.AsciiChar=178;
        }
        for (int k=64; k<80; k++){
            screen[i+k].Char.AsciiChar=219;
        }
    }
    for (int i=0; i<2000; i++){
        screen[i].Attributes = (uint8_t)((i%16)+((i/80)*16));
    }
    SMALL_RECT testscreenrect;
    testscreenrect.Left = 0;
    testscreenrect.Top = 0;
    testscreenrect.Right = 79;
    testscreenrect.Bottom = 15;
    WriteConsoleOutput(hConsole, screen, {80, 16}, {0, 0}, &testscreenrect);
    SetConsoleCursorPosition(hConsole, {0, 16});
    return 0;
}
