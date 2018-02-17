#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

const int N = 10000;

void CreateProc( int count) {
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcInfo;
	TCHAR CommandLine[] = "Lr1SPO 0";//TEXT((const char[9])str);
	CommandLine[7] += count;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));

		if (!CreateProcess(NULL, // �� ������������ ��� ������ 
			CommandLine,          // ��������� ������
			NULL,                 // ���������� �������� �� �����������. 
			NULL,                 // ���������� ������ �� �����������. 
			FALSE,                // ��������� ���������� ������������
			0,                    // ��� ������ �������� ��������
			NULL,                 // ���� ���������� ��������� ������������� ��������
			NULL,                 // ������������ ������� ������� ������������� ��������
			&StartupInfo,         // ��������� �� ���������  STARTUPINFO.
			&ProcInfo)           // ��������� �� ��������� ���������� � ��������.
			)
			cout << "error" << endl;
		else cout << "vse OK"<<endl;
		for (int i = 0; i < 10; i++)
			cout << "proc : " << _getpid() << endl;
		WaitForSingleObject(ProcInfo.hProcess, INFINITE);
}

void StartProc(int count) {
	count--;
	CreateProc(count);
}

int main(int argc, char** argv) {
	int count;
	if (argc != 1) {
		count = atoi(argv[1]);		
	}
	else {
		cin >> count;
	}
	if (count > 10) {
		cout << "Oh Oh, goodby ;)" << endl;
		return 0;
	}
	if (count > 0)
		StartProc(count);

	return 0;
}