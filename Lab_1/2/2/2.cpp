#include <fcntl.h>  
#include <io.h>  
#include <iostream>
#include <tchar.h>

int main()
{

    _setmode(_fileno(stdout), _O_U16TEXT);


    const wchar_t* text = L"Hello, World!";

    std::wcout << text << L'\n';

    return 0;
}