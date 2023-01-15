#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node *right;
		node *insert(node *head,int data,int start);
		void *display(node *head);
		void *end_traverse(node *end);
};
void *node::end_traverse(node *end)
{
	node *cur=end;
	while(cur!=NULL)
	{
		cout<<cur->data<<" ";
		cur=cur->left;	
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
			cur=cur->right;
		}
		cout<<endl;
	}
}
node *node::insert(node *head,int data,int start)
{
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
	{
		return temp;
	}
	else
	{
		node *cur=head;
		while(cur->right!=NULL)
		{
			cur=cur->right;
		}
		cur->right=temp;
		temp->left=cur;
		if(start==1)
		{
			return head;
		}
		else
		{
			return temp;
		}
	}
}
int main()
{
	node n;
	node* head=NULL;
	head=n.insert(head,10,1);
	head=n.insert(head,20,1);
	head=n.insert(head,30,1);
	head=n.insert(head,40,1);
	head=n.insert(head,50,1);
	node *end=n.insert(head,60,0);
	n.display(head);
	n.end_traverse(end);
}
