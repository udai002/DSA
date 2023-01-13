#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node *right;
		node *insert(node *root,int data);
		void *inorder(node *root);
		void *levelorder(node *root);
};
void *node::levelorder(node *root)
{
	if(root==NULL)
		cout<<"Tree is Empty"<<endl;
	else
	{
		queue<node *> q;
		q.push(root);
		while(q.empty()==false)
		{
			node *cur=q.front();
			cout<<cur->data<<" ";
			q.pop();
			if(cur->left!=NULL)
				q.push(cur->left);
			if(cur->left!=NULL)
				q.push(cur->right);
		}	
	}
}

void *node::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

node *node::insert(node *root,int data)
{
	node *temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	if(root==NULL)
		return temp;
	if(root->data<data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
}

int main()
{
	node *root=NULL;
	node n;
	root = n.insert(root,12);
	root = n.insert(root,82);
	root = n.insert(root,2);
	root = n.insert(root,22);
	n.inorder(root);
	cout<<endl;
	n.levelorder(root);
}
