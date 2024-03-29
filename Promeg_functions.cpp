#include <iostream>           // ����������� ������ �����/������
#include <fstream>            // �������� ������ �����/������
#include <iomanip>            // ���������� � ������������� setw
#include <time.h>             // ���������� � ������������� srand
#include <chrono>             // ����������� ���������� ��� ���������� ������� ������ ���������� 
#include "Promeg_functions.h" // ���������� ������������ ���� � ����������� ��������������� ������� 
#include "Constants.h"        // ���������� ������������ ���� � ����������� �����������
#include "Sort_vozr.h"        // ���������� ������������ ���� � ����������� ���������� ���������� �� �����������
#include "Sort_ub.h"          // ���������� ������������ ���� � ����������� ���������� ���������� �� ��������
#include "Sort_podr.h"        // ���������� ������������ ���� � ����������� ��������� ���������� ���������� �� �����������

using namespace std;    // ���������� ������������ ��� std
/***************************************************/
/*             ���������� �������                  */
/***************************************************/

/*-----------------------------------------------------------*/
/* ������ ������� ��� ������ ������� */
/*-----------------------------------*/
void pechatusloviy()
{
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << "   �������� �������� ����������:       ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  1." << (char)179 << "  Shaker_sort                     ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  2." << (char)179 << "  Selection_sort                  ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  3." << (char)179 << "  Insertion_sort                  ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  4." << (char)179 << "  Merge_sort                      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  5." << (char)179 << "  Quick_sort                      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  6." << (char)179 << "  Shell_sort                      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  7." << (char)179 << "  Repeat with other numbers       ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  8." << (char)179 << "  Exit.                           ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����
	return;                                 // ���������� ��������� ��������
}// pechatusloviy()


/*-----------------------------------------------------------*/
/* ������ ��������������� ������� � ������� */
/*------------------------------------------*/
void pechat_tabl(int* pznachenue  // ��������� �� ������ ������� ������������� �������-������� 
	           , int number)      // ���������� ��������� � �������-�������
{
	int j;                        // ��� ������� �� ��������� �������
	cout << "\t\t\t\t \x1b[33m� � � � � � � � � � � � �   � � � � � �   � � � � � � � �:\x1b[30m \n";
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << (char)218 << (char)196 << (char)196 << setw(30) << setfill(' ') << (char)196 << (char)196 << (char)191;          // ����� ������� ���������� ������
	for (j = 0; j < number; j++)  // ���� �� ���� ��������� �������, ��������� �������� ����������
	{// ������� ������� �������
		cout << "\n" << char(179) << setw(17) << setfill(' ') << *(pznachenue + j) << setw(17) << setfill(' ') << char(179) << setw(6) << setfill(' ') << "n = " << j + 1;
	}// for j
	cout << '\n';
	cout << (char)192 << (char)196 << (char)196 << setw(30) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;  // ����� ������ ���������� ������
	setlocale(LC_ALL, "Rus");     // ���������� ������� ����
}//pechat_tabl()


/*-----------------------------------------------------------*/
/* �������� ������������� �������           */
/*------------------------------------------*/
void sozdanie(int** pznachenue    // ����� ��������� �� ������������ ������-������, ��� ��������� �������� ���������
	        , int** soxranenie    // ����� ��������� �� ������������ ������-������ ���������� ��������� ��������� ����� �����������
	        , int& number)        // ���������� ��������� � �������-������� ��� ���������              
{
	cout << "������� ���������� ��������� �������: ";
	cin >> number;                // ������ �������, �������� �������������
	cout << endl;
	if (!cin.good())              // ���� ���������� ��������� �� �����
	{// ����� �� ������
		cout << "��������� �������� ���������� ��������� �� �������� ����� ������ ��� ��� ���������!!!";
		cout << "\n\t\t\t\t\t� � � � � � � � � �   � � � � � � � � � \n\n";
		system("pause");
		exit(1);                  // ��������� ��������� �� �������
	}
	*pznachenue = new int[number];// ��� ���� ��������� ���������� ������� ������ �� ������ ���������� ���������
	*soxranenie = new int[number];// ������� ������ ��� ������������ �� ������ ���������� ���������
	return;                       // ������� - �����. ������� ��������� �������� � caller
}//sozdanie()


/*-----------------------------------------------------------*/
/*  ���������� ������������ ������� - �������  */
/*---------------------------------------------*/
void zapolnenie(int* pznachenue   // ��������� �� ������ ������� ������������� �������-������� 
	          , int* soxranenie   // ��������� �� ������ ������� ������������� �������-������� ��� �����������
	          , int number)       // ���������� ��������� � �������-�������          
{
	int i;                        // ��� ����� ����������
	char choice;                  // �����, ��� ����� ���������� ����
	cout << "����� ������ �� ������ ����������� ��� �������? �������� �� ������������:\n\n";
	cout << setw(41) << setfill(' ') << "A) ��������� (������ ��� ������������);" << setw(57) << setfill(' ') << "B) ��������� (������ ������������ � �������� �������);" << setw(20) << setfill(' ') << "C) ������������;" << endl << endl;
	cout << "\n\x1b[31m���������:\x1b[30m � ������ ���������� �� �������� A � B �������� �������\n\n";
	cout << "������� A, B, C (��������� ���������� �������): ";
	cin >> choice;                // ������������ ������, ��� ����� ���������� ����
	cout << "�� �����: " << choice << endl << endl;  // ���-������

	srand(time(NULL));            // ������� �������� ���������� ��������������� �����, ����� rand ������� �� ���� � �� �� �������� ��� ������ �������
	if (choice == 'A')            // �������� ������� ���������� � ������� �����������. ������ ������ ��� ���������� �� �����������, ������ - ��� ��������
	{
		pznachenue[0] = rand() % rand_min;                   // ������� ������ ������� ���������
		for (i = 1; i < number; i++)                         // ������������ �� ���� ��� �� ���� ��������� �������
		{
			pznachenue[i] = pznachenue[i - 1] + rand() % step; // ������ ��������� ������ ����������� �������� �� step
		}// for i
		copy(pznachenue, soxranenie, number);                // ����������� ���������� � ������ ��������, �.� ����� ���������� �������� ������ ���������
		return;                                              // ��������� - ��������� � caller
	}// if(choice == 'A')

	else if (choice == 'B')      // �������� ������� ���������� � ������� ��������. ������ ������ ��� ���������� �� ��������, ������ - ��� �����������
	{
		pznachenue[0] = rand() % rand_max;                    // ������� ������ ������� ������� ��������� ������
		for (i = 1; i < number; i++)                          // ������������ �� ���� ��� �� ���� ��������� �������
		{
			pznachenue[i] = pznachenue[i - 1] - rand() % step;  // ������ ��������� ������ ����������� �������� �� step
		}// for i 
		copy(pznachenue, soxranenie, number);                 // ����������� ���������� � ������ ��������, �.� ����� ���������� �������� ������ ���������
		return;                                               // ��������� - ��������� � caller
	}// else if (choice == 'B')

	else if (choice == 'C')      // �������� ������� ���������� � ��������� �������. ������� ������ ��� ���������� �� �������� � ��� �����������
	{
		for (i = 0; i < number; i++)                          // ��� �� ���� ��������� �������
		{
			pznachenue[i] = rand() % rand_max;                // ��������� ��������� ������ �� ���������� �������� ��������� �����
		}// for i 
		copy(pznachenue, soxranenie, number);                 // ����������� ���������� � ������ ��������, �.� ����� ���������� �������� ������ ���������
		return;                                               // ��������� - ��������� � caller
	}// else if (choice == 'C')

	// �� ������ �� �� ���� �� ������� ������ ---> ������ �����
	cout << "\t\t\t\n�� ����� ������ ��� ��������� ������, ����� �������� ������ ������������� �������!!!\n";
	udalenie(pznachenue);        // ������� ����� ��������� ������ 
	udalenie(soxranenie);        // ������� ����� ��������� ������ ���������� 
	cout << "\n\t\t\t\t\t� � � � � � � � � �   � � � � � � � � � \n\n";
	system("pause");
	exit(1);                     // ��������� ��������� �� �������
}// zapolnenie()


/*-----------------------------------------------------------*/
/* �������� ������������� �������           */
/*------------------------------------------*/
void udalenie(int* pznachenue)                     // ��������� �� ������ ������� ������������� �������-�������
{
	delete[] pznachenue;                           // ������� ������������ ������-������
	return;                                        // ���������� ��������� �������� � caller
}// udalenie()


/*--------------------------------------------------------------------------------------*/
/* ����������� ��������� ��������� �������-������� � ������������� */
/*-----------------------------------------------------------------*/
void copy(int* pznachenue        // ��������� �� ������ ������� ������������� �������-������� 
	    , int* soxranenie        // ��������� �� ������ ������� ������������� �������-������� 
	    , int number)            // ���������� ��������� � �������-�������
{ 
	int i;                       // ��� ����� �����������
	// ������� ���������� �����. ��� �� ��������� ������������ �������
	for (i = 0; i < number; i++)
	{
		soxranenie[i] = pznachenue[i];             // ��������� ������� ������� ������� �� ������
	}// for i
	return;                      // ��������� - ��������� � caller
}// copy()


/*--------------------------------------------------------------------------------------*/
/* �������� ����������� �� �������������� ������� � �������� */
/*-----------------------------------------------------------*/
void back_copy(int* pznachenue   // ��������� �� ������ ������� ������������� �������-������� 
	         , int* soxranenie   // ��������� �� ������ ������� ������������� �������-������� 
	         , int number)       // ���������� ��������� � �������-�������
{
	int i;                       // ��� ����� �����������
	// ������� ���������� �����. ��� �� ��������� ������� ����������
	for (i = 0; i < number; i++)
	{
		pznachenue[i] = soxranenie[i];             // ��������� ������� ������� ������� � ������
	}// for i
	return;                      // ��������� - ��������� � caller
}// back_copy()


/*-----------------------------------------------------------*/
/* ����� ������� �� �������                 */
/*------------------------------------------*/
void(*MENU(int& vubor              // �������, ��������� �������������
	, char pechat                  // �����, �������� �� �������� ��������� � ������� ��� ������
	, char V_or_U))                // �����, ����������� �� ����������� ��� �� ��������
	(int*, int, int, int)          // ������������ ���������� �������
{
	// ������ ���������� �� ������ ������� ���������� �� �����������, ��������������� �� ����� � ����� �� ����������
	void (*functions_vozr[])(int*, int, int, int) = { Shaker_sort_vozr, Selection_sort_vozr, Insertion_sort_vozr, Merge_sort_vozr, Quick_sort_vozr, Shell_sort_vozr };
	// ������ ���������� �� ������ ������� ���������� �� ��������, ��������������� �� ����� � ����� �� ����������
	void (*functions_ub[])(int*, int, int, int) = { Shaker_sort_ub, Selection_sort_ub, Insertion_sort_ub, Merge_sort_ub, Quick_sort_ub, Shell_sort_ub };
	// ������ ���������� �� ���������� �������� ������� ���������� �� �����������, ��������������� �� ����� � ����� �� ����������
	void (*functions_podr[])(int*, int, int, int) = { Shaker_sort_podr, Selection_sort_podr, Insertion_sort_podr, Merge_sort_podr, Quick_sort_podr, Shell_sort_podr };
	cout << "\n�������� �������: 1 - 8, ��� 7 - ���������� ��������� � ������� ������� � �������, � 8 - ����� \n";
	cout << "�� �����: ";
	cin >> vubor;                                 // ���� ������ ��������� ������ �������������
	if ((vubor > 0) && (vubor < 7))               // ���� ������ � �������� ������� �� �������
	{
		// ������������ �� ����� �������� �������� ��� ���� ����������
		if (pechat == 'N')
		{
			// ������������ ����� ����������� �� �����������
			if (V_or_U == 'V')
			{
				return (functions_vozr[vubor - 1]); // ������ ��������������� ��������� �� �������, ����������� ��������� �� ������ ������� ���������� ���������� �� �����������
			}// if (V_or_U == 'V')

			// ������������ ����� ����������� �� ��������
			if (V_or_U == 'U')
			{
				return (functions_ub[vubor - 1]);   // ������ ��������������� ��������� �� �������, ����������� ��������� �� ������ ������� ���������� ���������� �� ��������
			}// if (V_or_U == 'U')  
		}// if (pechat == 'N')

		// ���� ������������ ����� ������� ��� ��������� � �������������� ��������
		else if (pechat == 'Y')
		{
			return (functions_podr[vubor - 1]);     // ������ ��������������� ��������� �� �������, ����������� ��������� �� ���������� ������� ����������
		}// else if (pechat == 'Y')
	}
	else // ������������ ��� ����� ��� ��������� ������� �� ������� ��� ��� EXIT ��� Repeat
	{
		return NULL;                                // ������� ��������� - ���� ������, ������� � caller
	}// if((vubor > 0) && (vubor < 7))
}// *MENU()


/*----------------------------------------------------------------------------------*/
/*  ������ ���������� ��������� ���������� �� ����� � � ����*/
/*----------------------------------------------------------*/
void pechat_mass_search(int* pznachenue      // ��������� �� ������ ������� ������������� �������-�������
	                  , int  number)         // ���������� ��������� � �������-�������             
{
	char pechat;                             // ����� ������������: ����� �� �� ������� �������� ��� ���� ����������
	char V_or_U;                             // ����� ������������: ����� �� �� ����������� ������ �� ����������� ��� �� ��������
	int vubor = 0;                           // ����� �������, ��������� �������������              
	int begin = 0;                           // ������ ������������� �������-�������
	int end = 0;                             // ����� ������������� �������-�������
	int i;                                   // ��� ������
	int* soxranenie = NULL;                  // ��������� �� ������ ��� ���������� ��������� ���������
	void(*choi�e)(int*, int, int, int);      // ��������� �� �������, ��������� �������������
	// ������ ���� ���������� ������ ��� ������ � ����, ����� �� ����������
	string name[6] = { "S h a k e r   s o r t", "S e l e c t i o n   s o r t", "I n s e r t i o n   s o r t", "M e r g e   s o r t", "Q u i c k   s o r t", "S h e l l   s o r t" };
	ofstream fout;                           // ���������� ������� ��� ���������� ������ ������ � ����
	fout.open(FNAME, ios::_Nocreate);        // ��������� ������ � ������. ��������� ��� ������

	if (!fout.is_open())                     // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������\n";
		fout.close();                        // ������� ���� ��� ������
		system("pause");
		return;                              // ���������� ��������, ��������������� ���� � caller
	}// if(!fout.is_open())
	cout << "\t\t\t\t\x1b[35m����������� � ����������� ��������� � ������� � � ����� ������\x1b[30m\n\n";
	sozdanie(&pznachenue, &soxranenie, number);    // ������� ������������ ������� � ������������ ������ ���������
	zapolnenie(pznachenue, soxranenie, number);    // ��������� ������������ ������ � ��������� �������� ���������                 
	system("cls");                                 // �������� ����� - ������� � �������� ���������
	while (1)                                      // ����������� ���� ������ �� ������� ���� ������������ �� ������� Exit ��� �� �������.
	{
		end = number - 1;                          // ���������� ����� ������� - ��� ��������� �������
		cout << "\t\t\t\t \x1b[34m� � � � � �   �   � � � � � � � � � � �   � � � � � � � � � �\x1b[30m\n\n";
		cout << "���������� ��������� � ������� : " << number << endl;  // ���-������
		pechatusloviy();                           // ����� ������� ������ �������
		cout << "\n������ �� �� ������� �������� ��� ���� ����������? ��������� ���������� ������ �� �����������! ������� Y ��� N: ";
		cin >> pechat;                             // ����, ����� �� ������������ ������� �������� ��� ���� ����������
		cout << "�� �����: " << pechat << endl;          // ���-������
		if (!((pechat == 'Y') || (pechat == 'N')) != 0)  // ���� �� ��� �� ��� ������
		{
			cout << "�������� Y ��� N. ��������� ���������� �������\n";
			system("pause");
			system("cls");                               // ��� ������ ����� ������� ������ �����
			continue;                                    // ��������� ����� ������
			// ���������� �������� ������� �� �����, �.� ������ ��� �� ������������
		}// if(!((pechat == 'Y') || (pechat == 'N')) != 0)

		cout << "\n� ����� ������� ������ �����������? ������� V(�� �����������) ��� U(�� ��������): ";
		cin >> V_or_U;                                   // ����, ����� �� ������������ ����������� ������ �� ����������� ��� �� ��������
		cout << "�� �����: " << V_or_U << endl;          // ���-������
		if (!((V_or_U == 'V') || (V_or_U == 'U')) != 0)  // ���� �� ��� �� ��� ������
		{
			cout << "�������� V ��� U. ��������� ���������� �������\n";
			system("pause");
			system("cls");                               // ��� ������ ����� ������� ������ �����
			continue;                                    // ��������� ���� ������
			// ���������� �������� ������� �� �����, �.� ������ ��� �� ������������
		}// if(!((pechat == 'Y') || (pechat == 'N')) != 0)

		choi�e = MENU(vubor, pechat, V_or_U);            // ����������� ��������� ������� �� �������, ��������� �������������
		if (choi�e == NULL)                              // ���� ����� �� ����� ��������� ����������� Exit ��� Repeat
		{
			if (vubor == 7)                              // ���� ������������ ������ Repeat
			{
				cout << "\t\t\t\t\t\x1b[31m�������� ���������� ������� � ������� �������!!!\x1b[30m\n\n";
				system("pause");
				system("cls");                           // ������ �����
				udalenie(pznachenue);                    // ������� ����� ��������� �������
				udalenie(soxranenie);
				cout << "\t\t\t\t\x1b[35m����������� � ����������� ��������� � ������� � � ����� ������\x1b[30m\n\n";
				sozdanie(&pznachenue, &soxranenie, number);    // ������� ������������ ������ � ������������ ������ ��������� ������
				zapolnenie(pznachenue, soxranenie, number);     // ��������� ������������ ������ ������ � ��������� ��������
				system("cls");                                  // ������� ����� � �������� ���������
				continue;                                       // ��������� ���� ������  
				// ���������� �������� ������� �� �����, �.� ������ ��� �� ������������
			}//if (vubor == 7)

			cout << "\t\t\t\t\t� � � � � � � � � �   � � � � � � � � � \n\n";
			// ���� ������������ �� Exit ��� ������
			system("pause");
			break;                                               // ��������� ����
		}// if (choi�e == NULL) 
		pechat_tabl(pznachenue, number);                         // ����������� ����������� ������ � �������
		cout << "\t\t\t\t\t\x1b[32m� � � � � � � �   " << name[vubor - 1] << "\x1b[30m" << endl;      // ������� �������� ��������� �� �������
		if (pechat == 'N')                               // ���� ������������ �� ����� �������� �������� ��� ���� ����������
		{
			auto start = chrono::steady_clock::now();    // ������ ����������� ����� ������, �.�. �������� ������
			choi�e(pznachenue, begin, end, number);      // ������� �������, ��������� �� ������� ����� ���������
			auto end = chrono::steady_clock::now();      // ��������� ����������� ����� ������
			cout << "\n\n\t\t\t\t\t\t\x1b[33m� � � � � � � � � � � � � � �\x1b[30m \n\n";
			pechat_tabl(pznachenue, number);             // ����������� ��� � ������� ����� ����������
			fout << "\t\t\t" << name[vubor - 1] << endl; // ������� � ���� ��� ���������� ���������
			cout << "����� ���������� �������, ����������� �������� = " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "  �����������; \n\n";        // ������� �� ����� ����� ������
			fout << "����� ���������� �������, ����������� �������� = " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "  �����������; \n\n";        // ������� � ���� ����� ������
		} // if (pechat == 'N')
		else if (pechat == 'Y')                          // ���� ������������  ����� �������� �������� ��� ���� ����������    
		{
			if (V_or_U == 'U')                           // ���� ������������ ������ � ��������� ���������� ����������� �� ��������
			{
				cout << "������ � ��������� ���������� ������������ ��������!!!!\n";
				system("pause");
				system("cls");
				continue;                                // ��������� ���� ������  
				// ���������� �������� ������� �� �����, �.� ������ ��� �� ������������
			}// if (V_or_U == 'U')
			// ���� � ��������� ���������� ������������ ��������� ������ �� �����������
			choi�e(pznachenue, begin, end, number);      // ������� �������, ��������� �� ������� ����� ���������
			cout << "\n\n\t\t\t\t\t\t\x1b[33m� � � � � � � � � � � � � � �\x1b[30m \n\n";
			pechat_tabl(pznachenue, number);             // ����������� ��� � ������� ����� ����������
		}// else if (pechat == 'Y')
		// ���� �������������� ������
		back_copy(pznachenue, soxranenie, number);       // ������� ������ �������, �.�. �� ��������� ����� ����������
		system("pause");
		system("cls");                                   // ��� ������ ����� ������� ������ �����
	}// while
	udalenie(soxranenie);
	udalenie(pznachenue);                                // ���������� - ������� ��, ��� ����� ������������. ������� ��������� �������
	fout.close();                                        // ������� ���� ��� ������
	return;                                              // ���������� ��������, ��������������� ���� � caller
}// pechat_mass_search()