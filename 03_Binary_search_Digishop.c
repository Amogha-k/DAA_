#include <stdio.h>
#include <time.h>
#include <conio.h>
#include<stdlib.h>

int main()
{
    int i, n,  key, bottom, top, mid;
    int j, temp;
    double clk;
    clock_t start_time, end_time;

    printf("Enter number of products ");
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100+1;
        printf("The product id are :\t %d\n", a[i]);
    }
    // sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    // printing sorted id of array
    printf("sorted product id is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nEnter the product id to be searched: ");
    scanf("%d", &key);

    // searching
    start_time = clock();
    bottom = 1;
    top = n;
    do
    {
        mid = (bottom + top) / 2;
        if (key < a[mid])
        {
            top = mid - 1;
        }
        else if (key > a[mid])
        {
            bottom = mid + 1;
        }

    } while (key != a[mid] && bottom <= top);

    if ((key == a[mid]) && bottom <= top)

    {
        printf("product found \n");
        printf(" product %d found in positon %d \n", key, mid + 1);
    }
    else
    {
        printf("search failed %d not found \n",key);
    }
    end_time=clock();
    
    clk=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("%f\n",clk);
}