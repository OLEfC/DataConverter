#include <iostream>
#include <windows.h>
using namespace std;
class Bits_to_Byte
{
public:
	long double z;
	void s(long double a, string ft, string lt) {
		int n = ft.length();
		int c = lt.length();
		if (ft[n - 1] == 'i' && lt[c - 1] == 'b') {
			a = a / 8;
			z = a;

		}
		else if (ft[n - 1] == 'b' && lt[c - 1] == 'i') {
			a = a * 8;
			z = a;

		}
		else if (ft[n - 1] == lt[c - 1]) {
			z = a;
		}
	}
};
class stepin
{
public:
	int start;
	int end;
	long double las;
	void s(string per, string druh, long double chyslo) {
		if (per[0] == 'b')
			start = 0;
		else if (per[0] == 'k')
			start = 1;
		else if (per[0] == 'm')
			start = 2;
		else if (per[0] == 'g')
			start = 3;
		else if (per[0] == 't')
			start = 4;

		if (druh[0] == 'b')
			end = 0;
		else if (druh[0] == 'k')
			end = 1;
		else if (druh[0] == 'm')
			end = 2;
		else if (druh[0] == 'g')
			end = 3;
		else if (druh[0] == 't')
			end = 4;
		int serednye;
		if (start < end) {
			serednye = end - start;
			las = (chyslo / pow(1024, serednye));
		}
		else if (end < start) {
			serednye = start - end;
			las = (chyslo * pow(1024, serednye));
		}
		else {
			las = chyslo;
		}
	}

};

int main()

{
	setlocale(LC_ALL, "Ukrainian");
	string fi, se;
	long double a, b, chyslo;
	Bits_to_Byte convert;
	stepin con;
	string tak;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "����������� ����i�� �����" << endl;
	cout << "b-�����			bi-�i��" << endl;
	cout << "kb-�i�������		kbi-�i���i��" << endl;
	cout << "mb-���������		mbi-�����i��" << endl;
	cout << "gb-�i�������		gbi-�i���i��" << endl;
	cout << "tb-���������		tbi-�����i��" << endl;
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "����i�� �����: ";
		cin >> a;
		cout << "������ ������� ���������� � ��� ������������: ";
		cin >> fi;
		cout << "������ ������� ���������� � ��� ������������: ";
		cin >> se;
		convert.s(a, fi, se);
		chyslo = convert.z;//�����i��� �i� �i���� i ������
		con.s(fi, se, chyslo);
		chyslo = con.las;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << a << fi << " = " << chyslo << se << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "���������� (y/n)" << endl;
		cin >> tak;
	} while (tak == "y");
	return 0;
}
