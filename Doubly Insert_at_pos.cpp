#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *prev;
		node *next;
		node *insert(node *head,int data);
		void *display(node *head);
		node *insert_at_pos(node *head,int data,int pos);
};
node *end;
node *node::insert_at_pos(node *head,int data,int pos)
{
	node *temp=new node;
	end=temp;
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
	if(pos==1)
	{
		temp->next=head;
		head->prev=temp;
		return temp;
	}
	else
	{
		node *cur=head;
		for(int i=2;i<=pos-1;i++)
		{
			if(cur->next!=NULL)
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
		temp->prev=cur;
		return head;	
	}
}
node* node::insert(node *head,int data)
{
	node *temp=new node;
	end=temp;
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
	if(head==NULL)
	{
		return temp;
	}
	else
	{
		node *cur=head;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=temp;
		temp->prev=cur;
		return head;
	}
}
void *node::display(node *head)
{
	if(head==NULL)
	{
		cout<<"List is Empty"<<endl;
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
	node *head=NULL;
	node n;
	head=n.insert(head,12);
	head=n.insert(head,13);
	head=n.insert(head,14);
	head=n.insert(head,15);
	n.display(head);
	head=n.insert_at_pos(head,100,5);
	n.display(head);
}
