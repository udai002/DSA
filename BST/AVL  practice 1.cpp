#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node *right;
		node *insert(node *root,int data);
		void *inorder(node *root);
		node *rightrotate(node *root);
		node *leftrotate(node *root);
		int getbf(node *root);
};
node* node::leftrotate(node *x)
{
	node *r=x->right;
	node *t=r->left;
	r->left=x;
	x->right=t;
	return r;
}
node *node::rightrotate(node *x)
{
	node *r=x->left;
	node *t=r->right;
	r->right=x;
	x->left=t;
	return r;
}
int node::getbf(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ldepth=getbf(root->left);
	int rdepth=getbf(root->right);
	if(ldepth>rdepth)
		return ldepth+1;
	else
		return rdepth+1;
}
node* node::insert(node *root,int data)
{
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		return temp;
	}
	if(root->data<data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
		
	int balance=getbf(root->left)-getbf(root->right);
	if(balance >1 && (root->left->data>data))
	{
		return rightrotate(root);
	}
	if(balance>1 && (root->left->data<data))
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	if(balance <-1 && (root->right->data) < data)
	{
		return leftrotate(root);
	}
	if(balance <-1 && (root->right->data)>data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
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
int main()
{
	node n;
	node *root=NULL;
	root=n.insert(root,14);
	root=n.insert(root,17);
	root=n.insert(root,11);
	root=n.insert(root,7);
	root=n.insert(root,53);
	root=n.insert(root,4);
	root=n.insert(root,13);
	root=n.insert(root,12);
	root=n.insert(root,8);
	root=n.insert(root,60);
	root=n.insert(root,19);
	root=n.insert(root,60);
	root=n.insert(root,20);
	n.inorder(root);
}
