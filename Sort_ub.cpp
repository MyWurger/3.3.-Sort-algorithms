#include "Sort_ub.h"    // ���������� ������������ ���� � ����������� ���������� ���������� �� ��������
#include <iostream>     // ����������� ������ �����/������
// � ����� ���������� Quick_sort ��� ������������ ����� ��-�� ������� ��������. ����������� ��� ������
#pragma comment(linker, "/STACK:2666777216")

/***************************************************/
/*             ���������� �������                  */
/***************************************************/

// ���������� ������� �� ��������:
/*-----------------------------------------------------------*/
/* ��������� ���������� �� ��������           */
/*--------------------------------------------*/
void Shaker_sort_ub(int* pznachenue        // ��������� �� ������ ������� ������������� �������-�������
	              , int begin              // ������ ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	              , int end                // ����� ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	              , int number)            // ����� ������������� �������-�������  
{
	int i;                                 // ��� ������� �� ���� ��������� �������
	int Temp;                              // ��� �������������� ���������� �������� ������
	// ���� ������ �� <����������>
	while (begin <= end)
	{
		// �������� �� ����������������� ����� �� ����� � ������.
		for (i = end; i > begin; i--)
		{
			if (pznachenue[i] > pznachenue[i - 1]) // ���� ������� ������ �����������
			{
				// ���������� ��� �� ������� �����������
				Temp = pznachenue[i - 1];          // ��������� ���������� � ������������� ����������
				pznachenue[i - 1] = pznachenue[i]; // �������� �� ��� ����� ������� �������
				pznachenue[i] = Temp;              // �� ����� ��������: �������� ��������-������������
			}// if (pznachenue[i] > pznachenue[i - 1])
		}// for i
		begin = begin + 1;                   // ����� ��������� ������� ������� ����� �� ��� ����� --> ��������� ��������������� ��������. �������� ������

		// �������� �� ����������������� ����� �� ������ � �����
		for (i = begin; i < end; i++)
		{
			if (pznachenue[i] < pznachenue[i + 1])  // ���� ������� ������ ����������
			{
				// ���������� ��� �� ������� ����������
				Temp = pznachenue[i + 1];           // ��������� ��������� � ������������� ����������
				pznachenue[i + 1] = pznachenue[i];  // �������� �� ��� ����� ������� �������
				pznachenue[i] = Temp;               // �� ����� ��������; �������� ��������-������������
			}// if (pznachenue[i] < pznachenue[i + 1])
		}// for i
		end = end - 1;                     // ����� ������� ������� ������� ����� �� ��� ����� --> ��������� ��������������� �
	}// while (begin <= end)
	return;                               // ���������� ��������� �������� � caller           
}// Shaker_sort_ub()


/*-----------------------------------------------------------*/
/* ���������� �������  �� ��������            */
/*--------------------------------------------*/
void Selection_sort_ub(int* pznachenue     // ��������� �� ������ ������� ������������� �������-�������
	                 , int begin           // ������ ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	                 , int end             // ����� ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	                 , int number)         // ����� ������������� �������-�������  
{
	int Max;                                 // ������������ �������
	int jMax;                                // ������ ������������� ��������
	int iSort;                               // ������� ��������������� �������
	int i, j;                                // ��������
	int Temp;                                // ��� ������

	for (iSort = 0; iSort < number - 1; iSort++)   // ���� �� ����� �� �����
	{
		// ������ ������� �� ��������������� ��������� ������������. � �ר��� �������� ������ �� ������ ������� � �������
		Max = *(pznachenue + iSort);               // ��������
		jMax = iSort;                              // ��� ������

		// ���� ������������ ������� � ���������� ����� �������
		for (j = iSort + 1; j < number; j++)
		{
			if (*(pznachenue + j) > Max)           // ��������� �������� �� ������������
			{
				// ���������� ������������ ������� � ��� �����
				Max = *(pznachenue + j);
				jMax = j;
			}// if (*(pznachenue + j) > Max) 
		}// for j

		// ����� �������� � ��������������� ����� �������
		// ������ ��� �� ����� ������� � ��������������� ����� �������
		// ������ �������� �������
		Temp = *(pznachenue + iSort);
		*(pznachenue + iSort) = *(pznachenue + jMax);
		*(pznachenue + jMax) = Temp;
	}// for iSort
	return;                                        // ������� ��������� ��������
}// Selection_sort_ub()


/*-----------------------------------------------------------*/
/* ���������� ��������� �� ��������            */
/*---------------------------------------------*/
void Insertion_sort_ub(int* pznachenue     // ��������� �� ������ ������� ������������� �������-�������
	                 , int begin           // ��������� �� ������ ������� ������������� �������-�������
	                 , int end             // ����� ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	                 , int number)         // ����� ������������� �������-�������                 
{
	int i;                                 // ��� ������� � �����
	int key;                               // ��� �������� ������������� ��������
	int j;                                 // ��� ������� � �����
	// ��� � ������ �� �����
	for (i = 1; i < number; i++)
	{
		key = pznachenue[i];               // ���������� �������, ������� ����� ����������
		j = i - 1;                         // �������� � ��� ������, ������� ��������� �� ������������� ��������
		// ��� �� ���� ����� � ����� � ������ - ���������� �������� � ������������ � �� ���������� � �����
		// ���� � ����� �� ����� ��������, ������� ���
		while (j >= 0 && pznachenue[j] < key)
		{
			// �������� �������� �� ��� ���, ���� ��������� �� ����� ������ �����
			// ������ �� ����� ���������� ��������(��� ����� ����� - �� ����� �������) �������, ������� �����
			pznachenue[j + 1] = pznachenue[j];
			j = j - 1;                     // ���������� �� �����, ����������� �� �����
		}// while (j >= 0 && pznachenue[j] < key)
		pznachenue[j + 1] = key;           // ������ �� ����� ����� ����������� ������� - ����
	}// for i
	return;                                // ������� ��������� �������� � caller
}// Insertion_sort_ub()


/*-----------------------------------------------------------*/
/* ���������� �������� �� ��������             */
/*---------------------------------------------*/
void Merge_sort_ub(int* pznachenue         // ��������� �� ������ ������� ������������� �������-�������
	             , int begin               // ������ ������������� �������-�������
	             , int end                 // ����� ������������� �������-�������
	             , int number)             // ����� ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
{
	int middle;                            // ������������� ����� �� �������� ������ �����, �������� ������ �� 2 ����������
	// ���� �������� �� ������ �������� � ������ ����������
	// ������� �������
	if (begin >= end)
	{
		return;                            // ��������� �� ��� ����� � caller, ��� � ��������������� ����� 2 �������� �������
	}// if(begin >= end)
	middle = (begin + end) / 2;            // ��������� ������� ������� ��� �������� ����������
	Merge_sort_ub(pznachenue, begin, middle, number);   // ���������� ����� �����
	Merge_sort_ub(pznachenue, middle + 1, end, number); // ���������� ������ �����
	Merge_ub(pznachenue, begin, middle, end);           // ������� ���� ������
}// Merge_sort_ub()


/*----------------------------------------------------------------------------------*/
/* "�������������" - �������� �������� ��� Merge_sort_ub           */
/*-----------------------------------------------------------------*/
void Merge_ub(int* pznachenue              // ��������� �� ������ ������� ������������� �������-�������
	        , int begin                    // ������ ������������� �������-�������
	        , int middle                   // �������� ������������� �������-�������
	        , int end)                     // ����� ������������� �������-�������
{
	// ���������� ���������� � ����� ��������� ����������� � ������� ��������
	int i;                                 // ��� �����
	int j;                                 // ��� �����
	int k;                                 // ��� �����
	int dlB = middle - begin + 1;          // ����� ����� ����� ����������
	int dlC = end - middle;                // ����� ������ ����� ����������
	int* B = NULL;                         // ��������� ��������� �� ������������ ������ ��������� ����� �����. �������������� ���, ����� �� ��� �����
	B = new int[dlB + 1];                  // ������ ������������ ���������, �������� �������� ����� ����� ���������
	int* C = NULL;                         // ��������� ��������� �� ������������ ������ ��������� ������ �����. �������������� ���, ����� �� ��� �����
	C = new int[dlC + 1];                  // ������ ������������ ���������, �������� �������� ������ ����� ���������
	j = 0;                                 // �������� ��������� � ������
	// ��������� ����� �����
	// ��� B �������� j, �.� �� ����������� begin=0
	for (i = begin; i <= middle; i++)
	{
		B[j] = pznachenue[i];              // ������� ����� ����� - ������� ����������� ���������� 
		j++;                               // ������������ �� ����������
	}// for i
	j = 0;                                 // �������� ������� ��� ������ � ����������� C

	// ��������� ������ �����
	// ��� C �������� j, �.�  middle+1!=0
	for (i = middle + 1; i <= end; i++)
	{
		C[j] = pznachenue[i];              // ������� ������ ����� - ������� ����������� ���������� 
		j++;                               // ������������ �� ����������
	}// for i

	B[dlB] = INT_MIN;                      // �� ��������� ����� ������� ������� ������ �������� ������� �������,
	C[dlC] = INT_MIN;                      // ����� �� ��������� ������ �� ������� �������
	i = 0;                                 // ������ ��� �������� � ������ ��������
	j = 0;
	for (k = begin; k <= end; k++)         // ��� �� ����������
	{
		// ����������� �������� ��������� ������ � ����� �����
		if (B[i] >= C[j])                  // ���� ������� ������ ����� ������ ��� ����� �������� ����� ����� 
		{
			pznachenue[k] = B[i];          // �������� ������� �� ����� ����� �� ������� ����� ����������
			i = i + 1;                     // ������� � ���������� �������� ����� �����
			// ���� ����� INT_MIN, �� ����� ����� ������� �� ������������
		}
		else                               // ���� ������� ����� ����� ������ �������� ������ �����             
		{
			pznachenue[k] = C[j];          // �������� ������� �� ������ ����� �� ������� ����� ����������
			j = j + 1;                     // ������� � ���������� �������� ������ �����
			// ���� ����� INT_MIN, �� ������ ����� ������� �� ������������
		}// if (B[i] >= C[j])
	}// for k
	delete[]B;                             // ���������� ���������� - ���������� ��
	delete[]C;
	return;                                // ������� ��������� �������� � caller
}// Merge_ub()


/*-----------------------------------------------------------*/
/*   ������� ���������� �� ��������            */
/*---------------------------------------------*/
void Quick_sort_ub(int* pznachenue         // ��������� �� ������ ������� ������������� �������-�������
	             , int begin               // ������ ������������� �������-�������
	             , int end                 // ����� ������������� �������-�������
	             , int number)             // ����� ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� ������� 
{
	int middle;                            // ��� �������� ������������
	// ���� �������� �� ������ �������� � ������ ����������
	// ������� �������
	if (begin >= end)
	{
		return;                            // ��������� �� ��� ����� � caller, ��� � ��������������� ����� 2 �������� �������
	}
	// ������������ �������� �� ���
	middle = Partition_ub(pznachenue, begin, end);
	// �������� � �����������, ���������� ��������, ������� ������� �����
	Quick_sort_ub(pznachenue, begin, middle - 1, number);
	// �������� � �����������, ���������� ��������, ������� ������� �����
	Quick_sort_ub(pznachenue, middle + 1, end, number);
}// Quick_sort_ub()


/*----------------------------------------------------------------------------*/
/*   ���������� � ������������ ��� Quick_sort_ub          */
/*--------------------------------------------------------*/
int Partition_ub(int* pznachenue           // ��������� �� ������ ������� ������������� �������-�������
	           , int begin                 // ������ ������������� �������-�������
	           , int end)                  // ����� ������������� �������-�������
{
	// ��������, ������� ����� �����, ����� ���������� ������ �� index
	// ��������, ������� ����� �����, ����� ���������� ����� �� index
	// ������ �������� ����� ���� � ����� �����������
	int index = begin;
	int i;                                 // ��� ������
	int Temp;                              // ��� ������
	// ��� � ������ ���������� � ������ ���������� � ��� �����
	for (i = begin; i < end; i++)
	{
		// ���� ����� �������, ������� ��� ������ �������� (������� ������)
		if (pznachenue[i] >= pznachenue[end])
		{
			// ��������� ������� ����� ������� ������
			Temp = pznachenue[i];
			pznachenue[i] = pznachenue[index];
			pznachenue[index] = Temp;
			index = index + 1;              // index �������������
		}// if (pznachenue[i] >= pznachenue[end])
	}// for i
	// �������� ������� ������� � index ��������
	Temp = pznachenue[end];
	pznachenue[end] = pznachenue[index];
	pznachenue[index] = Temp;
	return(index);                          // ������� ������ �������� �������� � caller
}//Partition_ub()


/*-----------------------------------------------------------*/
/*   ���������� ����� �� ��������              */
/*---------------------------------------------*/
void Shell_sort_ub(int* pznachenue         // ��������� �� ������ ������� ������������� �������-�������
	             , int begin               // ������ ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	             , int end                 // ����� ������������� �������-������� (�� ����� ����������). ����������, ����� ��� ������� ���� � ����� �������
	             , int number)             // ����� ������������� �������-�������
{
	int i;                                 // ��� �����
	int j;                                 // ��� �����
	int Temp;                              // ��� ������
	int d;                                 // ������ ���������
	d = number / 2;                        // ���������� ������ ����� ���������� ����� ������ - �������� �������
	// ������������� ������ ��� �������� ����� ������������� ����������, ���� �� ����� �� ������������ ������� ���� � ������
	while (d > 0)
	{
		for (i = 0; i < number - d; i++)   // ��� �� ���������� ���
		{
			j = i;                         // ���� �������� � ����� ��������������� �����
			// ����� ���� � ����������� i �� ������ ����, ���������� �� ������� ���������� ���������
			while (j >= 0)
			{
				if (pznachenue[j] < pznachenue[j + d])  // ������������� ������� � ��������� � ����������
				{
					// ���� ������� �������, ������ ���������� �� ����� ��������
					// ������ �������
					Temp = pznachenue[j];
					pznachenue[j] = pznachenue[j + d];
					pznachenue[j + d] = Temp;
				}// if (pznachenue[j] < pznachenue[j + d])
				j--; // �������� � �����������, ���� � ����� �����
			}// while j
		}// for i
		d = d / 2;   // ��������� ��������
	}// while d                                       
	return;          // ������� ��������� �������� � caller
}// Shell_sort_ub()