#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include<vector>
using namespace std;

map<int, std::string> keyNames = {
    {VK_BACK, "Backspace"},
    {VK_TAB, "Tab"},
    {VK_CLEAR, "Clear"},
    {VK_RETURN, "Enter"},
    {VK_SHIFT, "Shift"},
    {VK_CONTROL, "Ctrl"},
    {VK_MENU, "Alt"},
    {VK_PAUSE, "Pause"},
    {VK_CAPITAL, "Caps Lock"},
    {VK_ESCAPE, "Esc"},
    {VK_SPACE, "Space"},
    {VK_PRIOR, "Page Up"},
    {VK_NEXT, "Page Down"},
    {VK_END, "End"},
    {VK_HOME, "Home"},
    {VK_LEFT, "Left Arrow"},
    {VK_UP, "Up Arrow"},
    {VK_RIGHT, "Right Arrow"},
    {VK_DOWN, "Down Arrow"},
    {VK_SELECT, "Select"},
    {VK_PRINT, "Print"},
    {VK_EXECUTE, "Execute"},
    {VK_SNAPSHOT, "Print Screen"},
    {VK_INSERT, "Insert"},
    {VK_DELETE, "Delete"},
    {VK_HELP, "Help"},
    {VK_LWIN, "Left Windows Key"},
    {VK_RWIN, "Right Windows Key"},
    {VK_APPS, "Applications Key"},
    {VK_SLEEP, "Sleep"},
    {VK_NUMPAD0, "Numpad 0"},
    {VK_NUMPAD1, "Numpad 1"},
    {VK_NUMPAD2, "Numpad 2"},
    {VK_NUMPAD3, "Numpad 3"},
    {VK_NUMPAD4, "Numpad 4"},
    {VK_NUMPAD5, "Numpad 5"},
    {VK_NUMPAD6, "Numpad 6"},
    {VK_NUMPAD7, "Numpad 7"},
    {VK_NUMPAD8, "Numpad 8"},
    {VK_NUMPAD9, "Numpad 9"},
    {VK_MULTIPLY, "Numpad Multiply"},
    {VK_ADD, "Numpad Add"},
    {VK_SEPARATOR, "Numpad Separator"},
    {VK_SUBTRACT, "Numpad Subtract"},
    {VK_DECIMAL, "Numpad Decimal"},
    {VK_DIVIDE, "Numpad Divide"},
    {VK_F1, "F1"},
    {VK_F2, "F2"},
    {VK_F3, "F3"},
    {VK_F4, "F4"},
    {VK_F5, "F5"},
    {VK_F6, "F6"},
    {VK_F7, "F7"},
    {VK_F8, "F8"},
    {VK_F9, "F9"},
    {VK_F10, "F10"},
    {VK_F11, "F11"},
    {VK_F12, "F12"},
    {0x41, "A"},
    {0x42, "B"},
    {0x43, "C"},
    {0x44, "D"},
    {0x45, "E"},
    {0x46, "F"},
    {0x47, "G"},
    {0x48, "H"},
    {0x49, "I"},
    {0x4A, "J"},
    {0x4B, "K"},
    {0x4C, "L"},
    {0x4D, "M"},
    {0x4E, "N"},
    {0x4F, "O"},
    {0x50, "P"},
    {0x51, "Q"},
    {0x52, "R"},
    {0x53, "S"},
    {0x54, "T"},
    {0x55, "U"},
    {0x56, "V"},
    {0x57, "W"},
    {0x58, "X"},
    {0x59, "Y"},
    {0x5A, "Z"},
};


int main() {
    const int keyCount = 256;
    vector<bool> keyPressed(keyCount, false);

    while (true) {
        for (int i = 0; i < keyCount; ++i) {
            if (GetAsyncKeyState(i) & 0x8000) {
                if (!keyPressed[i]) {
                    system("cls"); // Clear console before printing
                    if (keyNames.find(i) != keyNames.end()) {
                        std::cout << "Key " << keyNames[i] << " pressed" << std::endl;
                    } else {
                        std::cout << "Key " << i << " pressed" << std::endl;
                    }
                    keyPressed[i] = true;
                }
            } else {
                keyPressed[i] = false;
            }
        }
    }
    return 0;
}
