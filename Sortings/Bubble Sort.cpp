//Bubble Sort

#include<iostream>
using namespace std;
int main()
{
	int a[7]={3,10,16,7,20,4,1};
	for (int j=0;j<7-1;j++)
	{
		for(int i=0;i<7-1-j;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<" ";
	}
}

