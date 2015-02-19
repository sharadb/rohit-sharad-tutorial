//abcd
#define maxsize 20
#define k 9
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void canBuyOrNot(int* coinBag)
{
	int i=0,j=0;
	int flag =0;
	int c1=0,c2=0;
	for(i=0;i<maxsize;i++)
    	{
    	   int compliment=k-coinBag[i];
    	   for(j=i+1;j<maxsize;j++)
    	   {
    	   if(coinBag[j]==compliment)
    	   {   
    		   flag=1;
    		   c1=compliment;
    		   break;
    	   }
       	   }
       	   if(flag==1)
       	   	break;
    	}
	if (flag==1)
	{
		c2=k-c1;
		printf("\nCan Buy Ring \nCoins to be used\t");
		printf("%d \t %d\n",c2,c1);
		
	}
	else
	printf("\nCannot Buy Ring\n");
}

int main()
{
	int *coinBag;
	int i=0;
	srand(time(NULL));
	for(i=0;i<maxsize;i++)
	//	scanf("%d",&coinBag[i]);   //populating the coinBag taking input from user
		coinBag[i]= pow(-1,(rand() % 2)) * (rand() % 15);//populating coinBag with positive and negetive numbers randomly
	for(i=0;i<maxsize;i++)
		printf("%d\t", coinBag[i]); //displaying coinBag
     	canBuyOrNot(coinBag);    
	return 0;
}

