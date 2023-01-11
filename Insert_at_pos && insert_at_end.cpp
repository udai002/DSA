#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node *insert_at_pos(node *head,int data,int pos);
		node *insert(node *head,int data);
		void *display(node *head);
};
void *node::display(node *head)
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node *cur=head;
		while(cur!=NULL)
		{
			cout<<cur->data<<" ";
			cur=cur->next;
		}
		cout<<endl;
	}
}

node *node::insert(node *head,int data)
{
	node *temp=new node;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		return temp;
	}
	node *cur=head;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=temp;
	return head;	
}











node* node::insert_at_pos(node *head,int data,int pos)
{
	node *temp=new node;
	temp->data=data;
	if(pos==1)
	{
		temp->next=head;
		return temp;
	}
	node *cur=head;
	for(int i=2;i<=pos-1;i++)
	{
		if(cur!=NULL)
		{
			cur=cur->next;
		}
		else
		{
			cout<<"Short List"<<endl;
		}
	}
	temp->next=cur->next;
	cur->next=temp;
	return head;
}
int main()
{
	node n;
	node *head=NULL;
	head=n.insert(head,10);
	head=n.insert(head,20);
	head=n.insert(head,30);
	head=n.insert(head,40);
	head=n.insert(head,50);
	head=n.insert(head,60);
	n.display(head);
	head=n.insert_at_pos(head,1000,9);
	n.display(head);
}
