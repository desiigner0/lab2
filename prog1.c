#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
const float RAND_MAX_F = RAND_MAX;
void clrscr() {
    system("@cls||clear");
}
// �������� ���������� �������
void CreateArr(int scan_count, char* array, int max, int min) 
{
    int i = 0;
    char element = 0;
    srand(time(NULL));
    for (i = 0; i < scan_count; i++) 
    {
        element = ((rand() / RAND_MAX_F) * (max-min) + min);
        array[i] = element;
    }
}
// ������ ������� � ����
void write_in_file(int scan_count, char* array, char* name)
{
    int i = 0;
    FILE* file = fopen(name, "w");
    if (file == NULL)
        printf("������ ��� �������� �����\n");
    else
    {
        for (i = 0; i < scan_count; i++)
        {
            fprintf(file, "%d\n", array[i]);
        }
    }
    fclose(file);
}

// ��� �����
void filename(char* name)
{
    while (strlen(name) >= 15) {
        printf("�������� ������� �������");
        scanf("%s", &name);
    }
    strcat(name, ".txt");
}
// ���������� ������� �� �����
void scanarr(int scan_count, char* array) 
{
    int i = 0;
    FILE* file = fopen("arr.txt", "r+");
    if (file == NULL)
        printf("������ ��� �������� �����\n");
    else
    {
        for (i = 0; i < scan_count; i++) 
        {
            fscanf(file, "%d", &array[i]);
        }
    }
}
int scancount()
{
    int count = 0;
    FILE* file = fopen("arr.txt", "r");
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
int main()
{
    setlocale(LC_ALL, "Rus");
    int scan_count = 0, flag = 0, i = 0, min = 0, max = 0;
    char element = 0;
    char* array = 0;
    char* name[16] = { 0 };
    do {
        printf("��� ������ --> (char). �������� ������ ����� �������� ������ (������� �����):\n");
        printf("1. ������ �� ��������� n �����\n");
        printf("2. ������ �� ������� �������� �����\n");
        printf("3. ������ �� �����\n");
        printf("4. �����\n");
        do {
            scanf_s("%d", &flag);
            if (flag < 1 || flag > 4)
                printf("\n������� ������ �����, ������� �����.\n");
        } while (flag < 1 || flag > 4);
        switch (flag) {
        case 1:
            clrscr();
            printf("������� ����� ��������� �������:\n");
            scanf_s("%d", &scan_count);
            array = (char*)malloc(scan_count * sizeof(char));
            printf("����������� �������� (����� ����������� �������� -128):\n");
            scanf("%d", &min);
            printf("������������ �������� (����� ������������ �������� 127):\n");
            scanf("%d", &max);
            if (min > max)
            {
                printf("������� ������� ��������\n");
                printf("����������� �������� (����� ����������� �������� -128):\n");
                scanf("%d", &min);
                printf("������������ �������� (����� ������������ �������� 127):\n");
                scanf("%d", &max);
            }
            CreateArr(scan_count, array, min, max);
            printf("������� ��� �����, � ������� ���������� ������ (�� ����� 15 ��������, ��� ����������):");
            scanf("%s", &name);
            filename(name);
            write_in_file(scan_count, array, name);
            free(array);
            clrscr();
            break;
        case 2:
            clrscr();
            printf("������� ����� ��������� �������:\n");
            scanf_s("%d", &scan_count);
            array = (char*)malloc(scan_count * sizeof(char));
            printf("������� �������� �������:\n");
            for (i = 0; i < scan_count; i++)
            {
                scanf("%d", &element);
                if (element >= -128  && element <= 127)
                {
                    array[i] = element;
                }
                else
                {
                    printf("������� �������� ��������, �������� [0;255]\n");
                    i--;
                }

            }
            printf("������� ��� �����, � ������� ���������� ������ (�� ����� 15 ��������, ��� ����������):\n");
            scanf("%s", &name);
            filename(name);
            write_in_file(scan_count, array, name);
            free(array);
            clrscr();
            break;
        case 3:
            clrscr();
            scan_count = scancount();
            array = (char*)malloc((scan_count + 1) * sizeof(char));
            printf("��������� ������ � ���� � ��������� arr.txt\n");
            scanarr((scan_count+1), array);
            printf("������� ��� �����, � ������� ��������� ������ (�� ����� 15 ��������, ��� ����������):\n");
            scanf("%s", &name);
            filename(name);
            write_in_file((scan_count+1), array, name);
            clrscr();
            break;
        case 4:
            return 0;
        default:
            printf("������� �������� ��������.\n");
            break;
        }
    } while (flag == 1 || flag == 2 || flag == 3 || flag == 4);
    free(array);
}