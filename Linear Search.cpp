#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,5,7,9,10,12,13,14,15,16,19,20,21,22,23,42,45,47,49,50,51,52};
	int num=1;
	int length=sizeof(a)/sizeof(a[0]);
	int i;
	for(i=0;i<length;i++)
	{
		if(a[i]==num)
		{
			cout<<"Element found at "<<i+1<<" Pos."<<endl;
			break;
		}
	}
	if(i==length)
		cout<<"Element didnt found"<<endl;
}
