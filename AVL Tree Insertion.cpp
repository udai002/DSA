#include<iostream>
using namespace std;
class node
{
	public:
		node *left,*right;
		int data;
		node(int x)
		{
			data=x;
			right=NULL;
			left=NULL;
		}
		node *insert(node *head,int data);
		void *inorder(node *head);
		node *leftrotate(node *root);
		node *rightrotate(node *root);
		int getbf(node *root);
};
node* node::leftrotate(node *y)
{
	node *x=y->right;
	node *t2=x->left;
	
	x->left=y;
	y->right=t2;
	return x;
}
node *node::rightrotate(node *y)
{
	node *x=y->left;
	node *t2=x->right;
	
	x->right=y;
	y->left=t2;
	return x;	
}
int node::getbf(node *root)
{
	if(root==NULL)
		return 0;
	int ldepth=getbf(root->left);
	int rdepth=getbf(root->right);
	if(ldepth>rdepth)
		return ldepth+1;
	else
		return rdepth+1;
}
node* node::insert(node *root,int data)
{
	node *temp=new node(data);
	if(root==NULL)
		return temp;
	if(root->data<data)
		root->right=insert(root->right,data);
	else		
		root->left=insert(root->left,data);


	int balance=getbf(root->left) - getbf(root->right);
	
	if(balance > 1&& (root->left->data)>data)
	{
		return rightrotate(root);
	} 
	if(balance > 1&&(root->left->data)<data)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	if(balance < -1 && (root->right->data)>data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);	
	}
	if(balance < -1 && (root->right->data)<data)
	{
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
	node n(0);
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
	root=n.insert(root,16);
	root=n.insert(root,20);
	n.inorder(root);
	cout<<endl;
	cout<<n.getbf(root->right)<<endl;
}
//14 17 11 7 53 4 13 12 8 60 19 16 20
