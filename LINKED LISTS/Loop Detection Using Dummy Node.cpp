#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node(int x)
		{
			data=x;
			next=NULL;
		}
};
bool detectloop(node *head)
{
	node *cur=head;
	node *dummy =new node(1);
	while(cur!=NULL)
	{
		if(cur->next==dummy)
			return true;
		else
		{
			node *temp=cur->next;
			cur->next=dummy;
			cur=temp;
		}
	}
	return false;
}
int main()
{
	node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
//	head->next->next->next->next=head->next;
//	head->next=head;

	if(detectloop(head))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;	
//	cout<<head->next->next->next->next->data;
//	cout<<head->next->next->next;	
	
}
