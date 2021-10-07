#include <fcntl.h>  
#include <io.h>  
#include <iostream>
#include <tchar.h>
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <Windows.h>

using namespace std;

wstring cpy(wstring str1,wstring str2) {
    str2 = str1;
    return str2;
}

int main()
{
    setlocale(LC_ALL, "CP_UTF8");
    wstring str1;
    wcin >> str1;
    wstring str2;                                  
    cpy(str1,str2);

    wcout << str1 << str2 << endl;
    return 0;
}