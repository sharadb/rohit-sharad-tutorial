#define maxsize 8

#include <cstdlib>
#include <iostream>

using namespace std;
/*
int canBuy(int *coinBag, int numCoins, int K) {
	int i;
	int max = coinBag[0], min = coinBag[0];
	int *coinBag2;
	for (i = 1; i < numCoins; ++i) {
		if ( max < coinBag[i] ) {
			 max=coinBag[i];
			 continue;
		}
    if ( min > coinBag[i] ) {
    	min=coinBag[i];
    	continue;
    }       
	}
	coinBag2 = (int *) calloc(sizeof(int), (max - min) + 1);
	for (i = 0; i < numCoins; ++i) {
		int compliment = K - coinBag[i] - min;
		if ( compliment >= 0 && coinBag2[compliment] == 1) {
			return 1;
		} else {
			coinBag2[coinBag[i] - min] = 1;
		}
	}
	return 0;
}
*/
int canBuy ( int* Bag1, int* Bag2, int numCoins1, int numCoins2, int k)
{
	int i;
	int max1 = Bag1[0], max2 = Bag2[0];
	int min1 = Bag1[0], min2 = Bag2[0];
	int *BagMap;
	int compliment;

	for (i = 1; i < numCoins1; ++i) {
			if ( max1 < Bag1[i] ) {
				 max1 = Bag1[i];
				 continue;
			}
	    if ( min1 > Bag1[i] ) {
	    	min1 = Bag1[i];
	    	continue;
	    }       
		}
	for (i = 1; i < numCoins2; ++i) {
			if ( max2 < Bag2[i] ) {
				 max2 = Bag2[i];
				 continue;
			}
	    if ( min2 > Bag2[i] ) {
	    	min2 = Bag2[i];
	    	continue;
	    }       
		}
	
	BagMap = (int*) calloc( sizeof(int), (max1 - min1 + 1) );
	
	for ( i = 0 ; i < numCoins1 ; i++ )
	{
		BagMap[Bag1[i] - min1] = 1;
	}

	for ( i = 0; i < numCoins2 ; i++ ) 
	{
		compliment = k - Bag2[i] ;
		if( (compliment - min1 ) > 0 && BagMap[ compliment - min1 ] == 1)
			return 1;
	} 
	return 0;
}

int main()
{
	int coinBag[5]={8,2,3,4,5}, coinBag2[5]={-1,2,3,4,5};
	int i=0;
	int result;
  result=canBuy(coinBag,coinBag2,5,5,13);
     	if(result==1)
     		printf("Can Buy\n");
     	else 
     		printf("Cannot Buy\n");
	return 0;
}
