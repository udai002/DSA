#include<iostream>
using namespace std;
class node
{
	public:
		node *next;
		int data;
		node *delete_at_pos(node *head,int pos);
		node *insert(node *head,int data);
		void *display(node *head);
};


node *node::delete_at_pos(node *head,int pos)
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
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
				return head;
			}	
		}
		node *add=cur->next;
		cur->next=cur->next->next;
		delete(add);	
	}
	return head;
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

int main()
{
	node n;
	node *head=NULL;
	head=n.insert(head,100);
	head=n.insert(head,200);
	head=n.insert(head,300);
	head=n.insert(head,400);
	head=n.insert(head,500);
	head=n.insert(head,600);
	n.display(head);
	head=n.delete_at_pos(head,8);
	n.display(head);
}
