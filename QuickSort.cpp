
#include<iostream>
using namespace std;
int partition(int a[],int lb,int ub)
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end)
	{
		if(pivot>=a[start])
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
	}
	int temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
	return end;
}
quicksort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int loc=partition(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);	
	}
}
int main()
{
	int a[]={100,7,5,2,1,7,9,10,1,1,11,6,10,5,9,2,1,15,7};
	int length=sizeof(a)/sizeof(a[0]);
	int lb=0;
	int ub=length-1;
	quicksort(a,lb,ub);
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<"  ";
	}
}
