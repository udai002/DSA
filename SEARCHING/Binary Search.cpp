#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,5,7,9,10,12,13,14,15,16,19,20,21,22,23,42,45,47,49,50,51,52};
	int num=17;
	int length=sizeof(a)/sizeof(a[0]);
	int n=length;
	int flag=0;
	int start=0;
	int end=n-1;
	while(n>0)
	{
		n=n/2;
		int middle=(start+end)/2;
		if(a[middle]==num)
		{
			cout<<"Element found at "<<middle+1 <<" pos"<<endl;
			flag=1;
			break;
		}
		else if(num>a[middle])
			start=middle+1;
		else
			end=middle-1;
	}
	if(flag==0)
	{
		cout<<"Element didnt found";
	}
}
