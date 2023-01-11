#include<iostream>
using namespace std;
class node
{
	public:
	node *prev;
	node *next;
	int data;
	node *insert(node *head,int data);
	void *display(node *head);
};
void *node::display(node *head)
{
	if(head==NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		node *cur=head;
		cout<<cur->data<<" ";
		cur=cur->next;
		while(cur!=head)
		{
			cout<<cur->data<<" ";
			cur=cur->next;
		}
	}
}
node *end=NULL;
node* node::insert(node *head,int data)
{
	node *temp=new node;
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		return temp;
	}
	node *cur=head;
	while(cur->next!=NULL && cur->next!=head)
	{
		cur=cur->next;
	}
	cur->next=temp;
	temp->next=head;
	head->prev=temp;
	end=temp;
	return head;
}
int main()
{
	node *head=NULL;
	node n;
	head=n.insert(head,12);
	head=n.insert(head,13);
	head=n.insert(head,14);
	head=n.insert(head,15);
	head=n.insert(head,17);
	head=n.insert(head,18);
	n.display(head);
	cout<<"Node "<<end->data<<endl;
}







//#include<iostream>
//using namespace std;
//struct Node
//{
//	int data;
//	Node *next;
//	Node *prev;
//	Node(int x)
//	{
//		data = x;
//		next=NULL;
//		prev=NULL;
//	}
//};
//void print(Node *head)
//{
//	 
//	 if(head==NULL)
//	 {
//	 	cout<<"EMPTY";
//	 }
//	 cout<<head->data<<" ";
//	for(Node *curr=head->next;curr!=head;curr=curr->next)
//	{
//
//		cout<<curr->data<<" ";
//	}
//}
//Node *insert(Node *head,int x)
//{
//	Node *temp = new Node(x);
//	if(head==NULL)
//	{
//		return temp;
//	}
//	else
//	{
//		Node *curr = head;
//		while(curr->next!=head && curr->next!=NULL)
//		{
//			curr=curr->next;
//		}
//		curr->next=temp;
//		temp->prev=curr;
//		temp->next=head;
//		head->prev=temp;
//		return head;
//	}	
//}
//int main()
//{
//	Node *head = NULL;
//	head = insert(head,100);
//	head = insert(head,200);
//	head = insert(head,300);
//	head = insert(head,400);
//	print(head);
//}
