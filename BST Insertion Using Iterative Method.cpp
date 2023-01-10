include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *right;
		node *left;
		node *insert(node *root,int data);
		void *inorder(node *root);
};
void* node::inorder(node *root)
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
		node *cur=root;
		node *parent=cur;
		while(cur!=NULL)
		{
			parent = cur;
			if(cur->data<data)
			{
				cur=cur->right;
			}
			else
			{
				cur=cur->left;	
			}
		}
		if (parent->data <data)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
		return root;
	}
}
int main()
{
	node n;
	node *root=NULL;	
	root = n.insert(root,10);
	root = n.insert(root,20);
	root = n.insert(root,30);
	root = n.insert(root,40);
	root = n.insert(root,50);
	n.inorder(root);
}
