#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <locale.h>
#include <wincon.h>

BOOL Asc2Un(LPCTSTR, LPCTSTR, BOOL);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Образец буфера содержит "ненависти" в UTF-8
    unsigned char buffer[15] = { 0x41,0x42,0x43 };
    // utf8 - указатель на вашу строку UTF-8
    char* utf8 = (char*)buffer;
    // конвертируем многобайтовый UTF-8 в широкую строку UTF-16
    int length = MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)utf8, -1, NULL, 0);
   
    
    if (length > 0)
    {
        wchar_t* wide = new wchar_t[length];
        MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)utf8, -1, wide, length);

    // конвертируем его в ANSI, используем setlocale () языка
        size_t convertedChars = 0;
        char* ansi = new char[length];
        wcstombs_s(&convertedChars, ansi, length, wide, _TRUNCATE);
    }

}