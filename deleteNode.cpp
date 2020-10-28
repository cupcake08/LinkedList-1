//problem from coding ninjas platform
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

/***********************************************************************/
/***********************************************************************/
Node* deleteNode(Node *head,int i)
{
  Node *temp=head;
  int count=0;
  if(i==0)
  {
    Node *a=head->next;
    head=a;
    return head;
  }
  while(temp->next!=NULL && count<i-1)
  {
    temp=temp->next;
    count++;
  }
  if(temp->next!=NULL)
  {
    Node *a=temp->next;
    Node *b=a->next;
    temp->next=b;
    delete a;
  }
  return head;
}
/***********************************************************************/
/***********************************************************************/
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}
