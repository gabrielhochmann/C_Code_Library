/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Array Reversal;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that reverts arrays (MAX 100 Elements).
 ========================================================================================
 */

#include <stdio.h>

void getarray(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int revertArray(int v[], int start, int end)
{

    if (start >= end)
    {
        return 0;
    };

    int temp = v[end];

    v[end] = v[start];
    v[start] = temp;

    return revertArray(v, start + 1, end - 1);
}

void showInfo(int v[], int n)
{
    int start = 0, end = n - 1;
    revertArray(v, start, end);

    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
}

int main()
{
    int v[100], n;

    printf("Input the array size (MAX 100):\n");
    scanf("%d", &n);

    printf("Input the array elements:\n");
    getarray(v, n);

    showInfo(v, n);

    return 0;
}