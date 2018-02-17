#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

const int N = 10000;

void CreateProc( char* argv) {
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcInfo;
	TCHAR CommandLine[] = TEXT("0");
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));

		if (!CreateProcess("Lr1SPO", // Не используется имя модуля 
			CommandLine,          // Командная строка
			NULL,                 // Дескриптор процесса не наследуется. 
			NULL,                 // Дескриптор потока не наследуется. 
			FALSE,                // Установка описателей наследования
			0,                    // Нет флагов создания процесса
			NULL,                 // Блок переменных окружения родительского процесса
			NULL,                 // Использовать текущий каталог родительского процесса
			&StartupInfo,         // Указатель на структуру  STARTUPINFO.
			&ProcInfo)           // Указатель на структуру информации о процессе.
			)
			cout << "error" << endl;
		else cout << "vse OK";
		WaitForSingleObject(ProcInfo.hProcess, INFINITE);
}

void StartProc(int count) {
	count--;
	char* argv;
	argv = itoa(count, argv, 10);
	CreateProc(argv);
}

int main(int argc, char** argv) {
	int count;
	if (argc != 1) {
		count = atoi(argv[1]);		
	}
	else {
		cin >> count;
	}
	if (count > 0)
		StartProc(count);
	else
		for (int i = 0; i < 10; i++)
			cout << "proc : " << _getpid() << endl;
	return 0;
}