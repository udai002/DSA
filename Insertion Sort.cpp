#include<iostream>
using namespace std;
int main()
{
	int a[7]={3,2,16,1,20,4,10};
	for(int j=1;j<7;j++)
	{
		int i;
		int key=a[j];
		for(i=j;i>0 && key<a[i-1];i--)
		{
			a[i]=a[i-1];
		}
		a[i]=key;
	}
	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<" ";
	}
}
