#include <iostream>
#include <Windows.h>
bool flowerbed = false; // ��������� ������
int n = 20; // ���-�� ������
int flowers[20]; // ������ ������, � ������� ��������������� ����� ��������� ������� � �������� ����������

void checkFlowerbedState() {
    bool all_flowers_watered = false;
    while (true) // ������ ����, � ������� ����� ������������� ��������� ������. ����� � ���� ����� ����� �������� ��������� ����� ������. 
    {
        for (int i = 1; i <= n; i++)
        {
            if (flowers[i] == 1) {
                all_flowers_watered = true;
            }
            else {
                all_flowers_watered = false;
                break; // ���� ���� ���� ������ �� �����, ������ ������ �� ������.
            }
        }

        if (all_flowers_watered) {
            printf("Flowerbed was watered\n");
            break;
        }
    }
}


void firstGardenerWork() {
    for (int i = 1; i <= n; i++)
    {
        if (flowers[i] == 0) // ��������� ����� �� ���-�� ������ �� �����
        {
            flowers[i] = 1; // ���� �� �����, �� ��������
            printf("The flower %d was watered by the first gardener\n", i);
        }
    }
}

void secondGardenerWork()
{
    for (int i = 1; i <= n; i++)
    {
        if (flowers[i] == 0) // ��������� ����� �� ���-�� ������ �� �����
        {
            flowers[i] = 1; // ���� �� �����, �� ��������
            printf("The flower %d was watered by the second gardener\n", i);
        }
    }
}

int main()
{
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)firstGardenerWork, NULL, NULL, NULL);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)secondGardenerWork, NULL, NULL, NULL);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)checkFlowerbedState, NULL, NULL, NULL);
    getchar();
}



/*#include <windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI WorkerThread(LPVOID param) {
    while (true) {
        Beep(440, 500);
        Beep(440, 500);
        Beep(440, 500);
        Beep(349, 350);
        Beep(523, 150);
        Beep(440, 500);
        Beep(349, 350);
        Beep(523, 150);
        Beep(440, 1000);
        Beep(659, 500);
        Beep(659, 500);
        Beep(659, 500);
    }
}
int main() {
	setlocale(0, "");
	HANDLE hThread;
	DWORD ThreadID;
	DWORD Num = 2;
	hThread = CreateThread(
		NULL,
		0,
		WorkerThread,
		(void*)&Num,
		0,
		&ThreadID);

	if (hThread == NULL) {
		cerr << "������" << GetLastError() << endl;
		system("pause");
		return -1;
	}

	int n;

	while (true) {
		cout << "1)�������������\n2)�����������\n0)��������� ���������" << endl;
		cin >> n;
		if (n == 1) { 
			SuspendThread(hThread); 
			system("cls"); 
		}
		if (n == 2) { 
			ResumeThread(hThread); 
			system("cls"); 
		}
		if (n == 0) {
			break;
		}
	}
	return 0;
}*/