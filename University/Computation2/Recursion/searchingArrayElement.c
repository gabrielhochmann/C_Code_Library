/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Searching for an array element recursively;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that searches for an element in an array recursively.
 ========================================================================================
 */

#include <stdio.h>

void getArray(int v[], int n)
{
    printf("Input %d Elements\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int searchArray(int v[], int n, int x)
{
    if (n <= 0)
    {
        return -1;
    };

    if (v[n - 1] == x)
    {
        return n - 1;
    }

    return searchArray(v, n - 1, x);
}

int main()
{
    int v[100], n, x;

    printf("Input the Array size (MAX 100)\n");
    scanf("%d", &n);
    getArray(v, n);

    printf("Input a number to find him on the array\n");
    scanf("%d", &x);

    printf("The %d is on v[%d] position.\n", x, searchArray(v, n, x));

    return 0;
}