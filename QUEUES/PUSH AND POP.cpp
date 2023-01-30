









#include<iostream>
using namespace std;
class node
{
	public:
		node *left,*right;
		int key,size;
		node * push(node *head,int key);
		node *getlast(node *head);
		node *pop(node *last);
		void display(node *head);
};
void node::display(node *head)
{
	if(head==NULL)
	{
		cout<<"empty";
	}
	else
	{
		node *cur=head;
		while(cur!=NULL)
		{
			cout<<cur->key<<" ";
			cur=cur->right;
		}
	}
	
}
node* node::getlast(node *head)
{
	if(head==NULL)
	{
		return NULL;
	}
	node *cur=head;
	while(cur->right!=NULL)
	{
		cur=cur->right;	
	}
	return cur;
}
node *node::pop(node *last)
{
	if(size>0)
	{
		size--;
		cout<<last->key<<endl;
		node *t=last->left;
		delete last;
		t->right=NULL;
		return t;
	}
	else
	{
		cout<<"underflow"<<endl;
		return last;
	}
}
node* node::push(node *head,int key)
{
	if(head==NULL)
	{
		size++;
		node *temp=new node;
		node *last=temp;
		temp->key=key;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else
	{
		if(size<=10)
		{
			size++;
			node *temp=new node;
			temp->key=key;
			head->left=temp;
			temp->right=head;
			temp->left=NULL;
			return temp;
		}
		else
		{
			cout<<"overflow"<<endl;
			return head;
		}
	}
}
int main()
{
	node n;
	node *head=NULL;
	node *last;
	//n.getlast(head);
	head=n.push(head,10);
	last=n.getlast(head);
	head=n.push(head,20);
	head=n.push(head,30);
	cout<<endl;
	last=n.pop(last);
	n.display(head);
}
