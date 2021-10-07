
#include <fcntl.h>  
#include <io.h>  
#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <locale.h>
#include <wincon.h>

int main()
{

    size_t _tcslen(const TCHAR*);

    const TCHAR* name = _T("Hello, World!");
    std::wcout << name << L'\n';
    // Получить целевой размер кэша, необходимый для конвертации
DWORD dBufSize=WideCharToMultiByte(CP_OEMCP, 0, name, -1, NULL,0,NULL, FALSE);

 // выделяем целевой кеш
char *dBuf = new char[dBufSize];
memset(dBuf, 0, dBufSize);
// Конвертировать
int nRet = WideCharToMultiByte(CP_OEMCP, 0, name, -1, dBuf, dBufSize, NULL, FALSE);



    return 0;
}