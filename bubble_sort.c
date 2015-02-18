#define maxsize 5
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void buble_sort(int* coinBag,int size)
{
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size-i;j++)
		{
			if(coinBag[j]>coinBag[j+1])
			{
				int temp=coinBag[j];
				coinBag[j]=coinBag[j+1];
				coinBag[j+1]=temp;
			}
		}
}
/*void insertion_sort(int* coinBag,int size)
{
	int i,j;
	int *coinBag2;
	for(i=0;i<size;i++)
	{
       

	}
}*/
int main()
{
	int *coinBag;
	int i=0;
	srand(time(NULL));
	for(i=0;i<maxsize;i++)
		coinBag[i]= pow(1,(rand() % 2)) * (rand() % 9);//populating coinBag with positive and negetive numbers randomly
	for(i=0;i<maxsize;i++)
		printf("%d\t", coinBag[i]); //displaying coinBag
        printf("\n");
    buble_sort(coinBag,maxsize);
    for(i=0;i<maxsize;i++)
		printf("%d\t", coinBag[i]); //displaying coinBag
        printf("\n");
    return 0;
}
