#include <cstdlib>
#include <iostream>

using namespace std;

void quicksort(int * array, int start, int end){
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
  int array[5] = {1, 5, 10, -11, 13} ;
  quicksort ( array, 0, 4 );
  for ( int i = 0; i < 5 ; i++ )
  	cout << array[i] << endl ;
  return 0;
}