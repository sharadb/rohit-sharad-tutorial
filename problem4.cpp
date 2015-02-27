#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int find_largest_vehicle( vector<int> width, int i, int j )
{
	int min = width.at(i) ;
	for( int p = (i + 1) ; p <= j ; p++)
			if( width[p] < min )
				min = width[p] ;
	return min;
}

int main()
{
	int size, numberOfTestCases;
	int result;
  vector<int> width ;
  cin >> size ;
  cin >> numberOfTestCases ;

  for ( int i = 0; i < size ; i++ )
  	{
  		int temp;
  		cin >> temp ;
  		width.push_back( temp );
  	}

	for ( int i = 0; i < numberOfTestCases ; i++ )
 	 	{
 	 		int x, y ;
 	 		cin >> x;
 	 		cin >> y;
 	 		result = find_largest_vehicle( width, x, y );
 	 		cout << result << endl;
  	}
  	
	return 0;
}