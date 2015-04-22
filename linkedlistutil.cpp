#include <iostream>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;



typedef struct node
{
	int data;
	struct node * next;
	node(int x) {
		data = x;
		next = NULL;
	}
} node;

node* isJoinedhelper( node* head1, node* head2 )
  {
    node * temp = head1;
    int count1=0,count2=0;
    while(temp != NULL && temp -> next != NULL)
    {
      count1++;
      temp = temp->next;
    }
    node* tail1 = temp;
    temp = head2;
    while( temp !=NULL && temp -> next != NULL )
    {
      count2++;
      temp = temp -> next;
    }
    node* tail2 = temp;
    if ( tail1 != tail2 )
    { 
        cout << "Not Merging" ;
        return (tail1 -> next);
    }
    else
    {
       if ( count1 < count2 )
       {
           for ( int i = 0; i < (count2-count1) ; i++)
               head2 = head2 -> next;
       }
      if ( count1 > count2 )
      {
           for ( int i = 0; i < (count1-count2) ; i++)
               head1 = head1 -> next;
      }
      while( head1 -> next != head2 -> next)
        {
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
      return head1 -> next;
    }
}

bool isJoined(node* head1,node*head2)
  {
    if ( head1 == NULL || head2 == NULL )
      return false;
    node* mergepoint = isJoinedhelper(head1,head2);
    if ( mergepoint == NULL)
      return false;
    else
      cout << "Lists Merge At: " << mergepoint -> data << endl;
      return true;
}

node * tail(node *head) {

	node* temp = head;
	while ( temp != NULL && temp -> next != NULL )
		temp = temp -> next;
	return temp;
}

bool isJoined(node * head1, node * head2) {

	// returns if the lls finally join at some point
	if ( head1 == NULL || head2 == NULL)
		return false;
	while ( head1 -> next != NULL )
		head1 = head1 -> next;
	while ( head2 -> next != NULL)
		head2 = head2 -> next;
	return (head1 == head2);
}

node* getNewNode(int val)
{	// return new node(val);
	node * temp= (node*) calloc(sizeof(node),1);
	temp -> data = val;
	temp ->next = NULL;
	return temp;
}


node* append(node* head,int data)
{
	node * temp = head;
	if ( temp == NULL)
	{
		temp = getNewNode(data);
		return temp;
	}
	while ( temp -> next != NULL )
				temp =  temp -> next;
	temp -> next = getNewNode(data);
	return head;
}

node *alternate(node *head) {
	// returns a newLinkedList with every alternate element (from the orginal)
	int i = 1 ;
	node *newhead = NULL;
	if ( head == NULL )
		return head;
	while ( head -> next != NULL)
	{
		if( (i%2) == 1)
			newhead = append(newhead,head -> data);
		i++;
		head = head -> next;
	}
	return newhead;
}

node *modifyToAlternate(node *head) {
	// just modify the original ll to have every alternate elements
}


void traverse(node* head)
{
	while( head != NULL)
		{
			cout << head -> data << " ";
			head = head -> next;
		}
	cout << endl;
	return;
}

int main()
{
	node *head = NULL;
	head = append(head,3);
	head = append(head,4);
	head= append(head,5);
	head = append(head,6);
	
	head = append(head,4);
	head= append(head,5);
	head = append(head,6);
	
	head = append(head,4);
	head= append(head,5);
	head = append(head,6);
	traverse(head);
	node* newll = alternate(head);
	traverse(newll);
	return 0;
}



