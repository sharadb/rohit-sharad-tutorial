//abcd
#define maxsize 8
#define k 9
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int canBuyOrNot(int * coinBag)
{
	int i=0,j=0;
    int *coinBag2;
    int range=0; 
    int max=coinBag[0],min=coinBag[0];
    for(i=0;i<maxsize;i++)
    {
        if(max<coinBag[i]) { max=coinBag[i]; continue;}
        if(min>coinBag[i]) { min=coinBag[i]; continue;}       
    }
    range=max-min;
    if(min<0)
    {
    	coinBag2=(int*)calloc(sizeof(int),range+1);
     	for(i=0;i<maxsize;i++)
    	 {
            if(coinBag2[k-coinBag[i]-min]==1)
            		return 1;
            else 
            	coinBag2[coinBag[i]-min]=1;
		 }
		 return 0;
    } 
}



int main()
{
	int *coinBag;
	int i=0;int result;
	srand(time(NULL));
	for(i=0;i<maxsize;i++)
	//	scanf("%d",&coinBag[i]);   //populating the coinBag taking input from user
		coinBag[i]= pow(-1,(rand() % 2)) * (rand() % 15);//populating coinBag with positive and negetive numbers randomly
	for(i=0;i<maxsize;i++)
		printf("%d\t", coinBag[i]); //displaying coinBag
     	result=canBuyOrNot(coinBag);
     	if(result==1)
     		printf("\nCan Buy\n");
     	else 
     		printf("Cannot Buy\n");
	return 0;
}