#include<iostream>
using namespace std;
int main()
{
	int a[]={7, 6, 10, 5, 9, 2, 1, 15, 7 };
	int lb=0;
	int ub=8;
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	int j=1;
	while(start<end)
	{
		while(pivot>=a[start])
		{
			start++;
		}
		while(pivot<a[end])
		{
			end--;
		}
		if(start<end)
		{
			int temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}	
//		cout<<"Start "<<start<<" End "<<end<<endl;
	}
	int temp=a[end];
	a[end]=pivot;
	a[0]=temp;
	for(int i=0;i<9;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"Start "<<start<<" End "<<end<<endl;
}
