#include<iostream>
using namespace std;
class node
{
	public:
		node *left;
		node *right;
		int data;
		node *insert(node *root,int data);
		void *inorder(node *root);
		node *del(node *root,int data);
};
node * node::del(node *root,int x)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(root->data<x)
		{
			root->right=del(root->right,x);
		}
		else if(root->data>x)
		{
			root->left=del(root->left,x);
		}
		else
		{
			if (root->left==NULL)
			{
				node *temp=root->right;
				delete root;
				return temp;
			}
			else if(root->right==NULL)
			{
				node *temp=root->left;
				delete root;
				return temp;	
			}
			else
			{
				node *cur=root->right;
				while(cur->left!=NULL)
				{
					cur=cur->left;
				}
				root->data=cur->data;
				root->right=del(root->right,cur->data);
			}
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
node* node::insert(node *root,int data)
{
	node *temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	if(root==NULL)
	{
		return temp;
	}
	else
	{
		if(root->data<data)
		{
			root->right=insert(root->right,data);
		}
		else
		{
			root->left=insert(root->left,data);
		}
	}
}
int main()
{
	node *root=NULL;
	node n;
	root=n.insert(root,19);
	root=n.insert(root,15);
	root=n.insert(root,22);
	root=n.insert(root,11);
	root=n.insert(root,17);
	root=n.insert(root,20);
	root=n.insert(root,25);
	root=n.insert(root,10);
	root=n.insert(root,12);
	root=n.insert(root,16);
	root=n.insert(root,18);
	n.inorder(root);
	cout<<endl;
	root=n.del(root,15);
	n.inorder(root);
}
