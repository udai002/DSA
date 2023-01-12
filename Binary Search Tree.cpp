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
		bool search(node*root,int data)
		{
			node *cur=root;
			while(cur!=NULL)
			{
				if(cur->data==data)
				{
					return true;
				}
				else if (cur->data<data)
				{
					cur=cur->right;
				}
				else
				{
					cur=cur->left;
				}
			}
			return false;
		}
};
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
void *node::inorder(node* root)
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
	root=n.insert(root,13);
	root=n.insert(root,14);
	root=n.insert(root,11);
	root=n.insert(root,12);
	n.inorder(root);
	if(n.search(root,14))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}
