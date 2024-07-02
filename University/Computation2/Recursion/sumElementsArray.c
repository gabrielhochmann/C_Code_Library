/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Recursive sum of elements in a array;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that sums elements in an array recursively.
 ========================================================================================
 */

#include <stdio.h>

void getArray(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int sumArray(int v[], int n)
{
    if (n <= 0)
    {
        return 0;
    };

    return v[n-1] + sumArray(v, n-1);
}

int main()
{
    int v[100], n;
    printf("Input the Array size (MAX 100)\n");
    scanf("%d", &n);

    getArray(v, n);

    printf("Sum of the array is: %d\n", sumArray(v, n));

    return 0;
}