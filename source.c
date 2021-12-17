#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <math.h>
// ������� �������
void clrscr() {
	system("@cls||clear");
}
// ���������� ��������
void bubbleSort(char* arr, int count)
{
	int i = 0, j = 0;
	int tmp = 0;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void qSort(char* arr, int first, int last)
{
	int i = first;
	int j = last;
	int x = arr[(first + last) / 2];
	int tmp = 0;
	while (i <= j)
	{
		while (arr[i] < x)
			i++;
		while (arr[j] > x)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (first < j)
		qSort(arr, first, j);
	if (last > i)
		qSort(arr, i, last);
}
void inSort(char* arr, int count)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < count; i++)
	{
		for (j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}
	}
}
// ���������� ������� ������� �� �����
int scancount(char* name)
{
	int count = 0;
	FILE* file = fopen(name, "r");
	if (file == NULL) {
		printf("������ ��� �������� �����\n");
		exit;
	}
	else
	{
		while (!feof(file))
		{
			if (fgetc(file) == '\n')
				count++;
		}
	}
	fclose(file);
	return count;
}
// ������ �������
void PrintArray(char* arr, int count)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("array[%d]=%d\n", i, arr[i]);
	}
}
// ���������� ����
int resultnorm1(char* arr, int count) 
{
	int i = 0;
	int result = 0;
	for (i = 0; i < count; i++)
	{
		result = result + abs(arr[i]);
	}
	return(result);
}
double resultnorm2(char* arr, int count)
{
	int i = 0;
	int sum = 0;
	double result = 0;
	for (i = 0; i < count; i++)
	{
		sum = sum + (abs(arr[i])* abs(arr[i]));
	}
	result = sqrt(sum);
	return(result);
}
double resultnormG(char* arr, int count, double p)
{
	int i;
	int sum = 0;
	double result = 0;
	for (i = 0; i < count; i++)
	{
		sum = sum + pow(abs(arr[i]), p);
		
	}
	result = pow(sum, pow(p, -1));
	return(result);
}
int infinitynorma(char* arr, int count)
{
	int i = 0;
	int max = -9999;
	for (i = 0; i < count; i++)
	{
		if (abs(arr[i]) > max)
			max = abs(arr[i]);
	}
	return(max);
}
void normirovka(char* arr, int count) 
{
	int i = 0;
	int sum = 0;
	double sqrtb = 0;
	for (i = 0; i < count; i++)
	{
		sum = sum + (abs(arr[i]) * abs(arr[i]));
		sqrtb = sqrt(sum);
		printf("���������� �������: \n\n");
		for (i = 0; i < count; i++)
		{
			printf("%d / %g --> %g\n", arr[i], sqrtb, arr[i] * 1.0 / sqrtb);
		}
		printf("\n\n\n");
	}
}

int main()
{
	int flag, sortflag, count, i = 0;
	char* name[300] = { 0 };
	double startTime, endTime, p, norm2, normG = 0;
	int norm1, normI = 0;
	setlocale(LC_ALL, "Rus");
	printf("������� ���� � ���������� ����� � ��������:\n");
	scanf("%s", &name);
	count = scancount(name);
	char* array = (char*)malloc(count * sizeof(char));
	char* array2 = (char*)malloc(count * sizeof(char));
	if (count == 0 || count == 1) {
		printf("��� ������ ����������� ���� ������\n");
		return 0;
	}
	FILE* file = fopen(name, "r");
	if (file == NULL) {
		printf("������ ��� �������� �����\n");
		exit;
	}
	else
	{
		for (i = 0; i < count; i++)
		{
			fscanf(file, "%d\n", &array[i]);
		}
	}
	clrscr();
	printf("������ ������\n");
	memcpy(array2, array, sizeof(char) * count);
	do {
		printf("1. ������\n2. ����������\n3. �����\n4. ���������� ���� ������� (�������)\n5. ����������\n6. �����\n�����:");
		do {
			scanf("%d", &flag);
			if (flag < 1 || flag > 6)
				printf("\n������� ������ �����, ������� �����.\n");
		} while (flag < 1 || flag > 6);
		switch (flag) {
		case(1):
			clrscr();
			printf("������ �� %d �����\n", count);
			PrintArray(array, count);
			break;
		case(2):
			clrscr();
			printf("�������� ������ ����������:\n1. �����������\n2. ���������\n3. �������\n4. ����� � ����\n");
			do
			{
				scanf("%d", &sortflag);
				if (sortflag < 1 || sortflag > 4)
					printf("\n������ �������� �����. ������� �����:\n");
			} while (sortflag < 1 || sortflag > 4);
			switch (sortflag) {
			case(1):
				clrscr();
				printf("���������� � �������� ����������...");
				startTime = clock();
				bubbleSort(array, count);
				endTime = clock();
				printf("����� ����������: %lf\n", (endTime - startTime) / 1000);
				printf("���������� ���������\n\n");
				break;
			case(2):
				clrscr();
				printf("���������� � �������� ����������...\n");
				startTime = clock();
				inSort(array, count);
				endTime = clock();
				printf_s("����� ���������� %lf\n", (endTime - startTime) / 1000);
				printf_s("���������� ���������\n\n");
				break;
			case(3):
				clrscr();
				printf("���������� � �������� ����������...");
				startTime = clock();
				qSort(array, 0, count - 1);
				endTime = clock();
				printf_s("����� ���������� %lf\n", (endTime - startTime) / 1000);
				printf_s("C��������� ���������\n\n");
				break;
			case(4):
				clrscr();
				break;
			}
			break;

		case(3):
			clrscr();
			memcpy(array, array2, sizeof(char) * count);
			printf_s("���������� ��������\n\n");
			break;
		case(4):
			clrscr();
			printf("����������...\n");
			norm1 = resultnorm1(array, count);
			printf("������ ����� �������: %d\n", norm1);
			norm2 = resultnorm2(array, count);
			printf("������ ����� �������: %lf\n", norm2);
			printf("������� ������� p ��� ����������� �����:\n");
			scanf("%lf", &p);
			normG = resultnormG(array, count, p);
			printf("���������� ����� �������: %lf\n", normG);
			normI = infinitynorma(array, count);
			printf("����������� �����: %d\n\n", normI);
			break;
		case(5):
			normirovka(array, count);
			break;
		case(6):
			printf_s("\n����� �� ���������...\n");
			return 0;
			break;
		}
	} while (flag == 1 || flag == 2 || flag == 3 || flag == 4 || flag == 5 || flag == 6);
	fclose(file);
	free(array);
	free(array2);
}
