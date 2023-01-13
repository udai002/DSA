//#include <bits/stdc++.h> 
//using namespace std; 
//
//struct Node{
//    int data;
//    Node* next;
//    Node(int x){
//        data=x;
//        next=NULL;
//    }
//};
//int main() 
//{ 
//	Node *head=new Node(10);
//	Node *temp1=new Node(20);
//	Node *temp2=new Node(30);
//	head->next=temp1;
//	temp1->next=temp2;
//	cout<<head->data<<"-->"<<temp1->data<<"-->"<<temp2->data;
//	return 0;
//} 





#include<iostream>
using namespace std;
int main()
{
	string pass="loki";
	int count=0;
	string text;
	while(count<3)
	{	
		cout<<"Enter for the "<<count+1<<"time"<<endl;
		cin>>text;
		if(text==pass)
		{
			cout<<"Yes";
			break;
		}
		else
		{
			count++;
		}	
	}
	if(count>=3)
	{
		cout<<"No";
	}
}
