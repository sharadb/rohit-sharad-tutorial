#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <string>


using namespace std;

bool paranthesis_mat(string str)
{
	stack<char> s;
	int size = str.size();
	for ( int i = 0; i < size; i++)
	{
		if ( str.at(i) == '(' || str.at(i) == '{' || str.at(i) == '[' )
			s.push(str.at(i) );
		else if (str.at(i) == ')')
		{
			 if(s.top() == '(')
			 		{
			 			s.pop();
			 			continue;
			 		}
			 	else
			 		return false;
		}
		else if (str.at(i) == '}')
		{
			if (s.top() == '{')
			 		{
			 			s.pop();
			 			continue;
			 		}
			 	else 
			 		return false;
		}
		else if (str.at(i) == ']')
		{
			if (s.top() == '[')
			 		{
			 			s.pop();
			 			continue;
			 		}
			 else 
			 	return false;
		}
		else 
			continue;
	}


	if (s.empty())
		return true;
	else 
		return false;
}

int main()
{
	string s = "{}[{()}](){]{";
  bool res = paranthesis_mat(s);
  if (res)
  	cout << "TRUE" << endl;
  else 
  	cout << "FALSE" << endl;
	return 0;
}