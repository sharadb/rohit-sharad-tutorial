#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<int> find_min_diff (vector<int> vec , int size)
{
	// This function will find the two numbers for which the difference is minimum
	// input is Sorted array
  int diff =  vec[1] -  vec[0] ;
  vector<int> new_vec;
  new_vec.push_back( vec[0] );
  new_vec.push_back( vec[1] );
  for ( int i = 2; i < size; i++ )
  {
  	if ( ( vec[i] - vec[i-1] ) > diff )
  		continue;
  	else if( ( vec[i] - vec[i-1] ) < diff )
  	{
  			diff = vec[i] - vec[i-1];
  			new_vec.clear();
  			new_vec.push_back( vec[i - 1] );
  			new_vec.push_back( vec[i] );
  	}  	 	
  	else
  	{
  		new_vec.push_back( vec[i - 1] );
  		new_vec.push_back( vec[i] );
  	}
  }
  return new_vec;
}
void quicksort(vector<int> &vec, int start, int end)
{
	if( start >= end )
		return;
	int pivot = vec[start];
 	int i = start, j = end;
  while(i < j)
  {
	 	while ( vec[i] <= pivot && i < end )
	 		i++ ;
	 	while ( vec[j] >= pivot && j > start )
	 		j-- ;
	 	if( i < j)
	 	{
	 		int temp = vec[i];
	 		vec[i] = vec[j];
	 		vec[j] = temp;
	 	}
	 else
	 {
	 	int temp = vec[j];
	 	vec[j] = pivot;
	  vec[start] = temp;
	 }
	}
 quicksort( vec, start, j - 1);
 quicksort( vec, j + 1 , end);
}
int main()
{
  int size = 7;
  int initVector[] = {113, 213, 10, 11, 13, 5, 6};
  vector<int> vec(initVector,initVector + size);
  quicksort ( vec, 0, 6 );
  //for ( int i = 0; i < size; i++ )
    //cout << vec[i] << endl ;
  vector<int> result = find_min_diff( vec, size);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << endl ;
  return 0;
}