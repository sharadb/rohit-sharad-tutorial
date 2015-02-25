#include <cstdlib>
#include <iostream>
using namespace std;



void find_min_diff(int * array)
{
	// This function will find the two numbers for which the difference is minimum
	// input is Sorted array
	int num1 = array[0], num2 = array[1] ; 
  int diff = num2 - num1 ;
  for ( int i = 2; i < 5; i++ )
  {
  	if ( ( array [i] - array[i-1] ) >= diff )
  		continue;
  	else 
  	{
  			diff = array [i] - array[i-1];
  			num1 = array[i - 1];
  			num2 = array[i];
  	}  	 	
  }
  cout << num1 << endl;
  cout << num2 << endl;
}



void quicksort(int * array, int start, int end)
{
	if( start >= end )
		return;
	int pivot = array[start];
 	int i = start, j = end;
  while(i < j)
  {
	 	while ( array[i] <= pivot && i < end )
	 		i++ ;
	 	while ( array[j] >= pivot && j > start )
	 		j-- ;
	 	if( i < j)
	 	{
	 		int temp = array[i];
	 		array[i] = array[j];
	 		array[j] = temp;
	 	}
	 else
	 {
	 	int temp = array[j];
	 	array[j] = pivot;
	  array[start] = temp;
	 }
	}
 quicksort(array, start, j - 1);
 quicksort(array, j + 1 , end);
}
int main()
{
  int array[5] = {1, 1, 10, -11, 13} ;
  quicksort ( array, 0, 4 );
  find_min_diff( array );
  return 0;
}