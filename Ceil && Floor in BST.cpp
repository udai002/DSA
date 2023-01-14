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
		node *floor(node *root,int key);
		node *ceil(node *root,int key);
};
node* node::ceil(node *root,int key)
{
	node *num=NULL;
	node *cur=root;
	while(cur!=NULL)
	{
		if(cur->data==key)
			return cur;
		if(cur->data>key) {
			num=cur;
			cur=cur->left;
		} else {
			cur=cur->right;
		}
	}
	return num;
}

node* node::floor(node *root,int key)
{
	node *num=NULL;
	node *cur=root;
	while(cur!=NULL) {
		if(cur->data==key)
			return cur;
		if(cur->data<key) {
			num=cur;
			cur=cur->right;
		} else{
			cur=cur->left;
		}		
	}
	return num;
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
	root = n.insert(root,14);
	root = n.insert(root,11);
	root = n.insert(root,53);
	root = n.insert(root,7);
	root = n.insert(root,13);
	root = n.insert(root,17);
	root = n.insert(root,60);
	root = n.insert(root,4);
	root = n.insert(root,8);
	root = n.insert(root,12);
	root = n.insert(root,16);
	root = n.insert(root,19);
	n.inorder(root);
	node *add=n.floor(root,16);
	cout<<"\nAddress"<<add->data<<endl;
	cout<<n.ceil(root,11)->data<<endl;
}

