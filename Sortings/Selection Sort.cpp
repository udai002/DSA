#include<iostream>
using namespace std;
int main()
{
	int a[7]={3,10,16,7,20,4,1};
	for(int i=0;i<7-1;i++)
	{
		int max=0;
		for(int j=1;j<7-i;j++)
		{
			if(a[j]>a[max])
			{
				max=j;
			}
		}
		int temp=a[7-1-i];
		a[7-i-1]=a[max];
		a[max]=temp;
	}
	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<" ";
	}
}
