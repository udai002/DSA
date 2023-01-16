#include<iostream>
using namespace std;
int main()
{
	int a[]={1,5,10,14,16,18,30,35,40,45};
	int b[] = {2,3,6,11,15,17,20,22,45,67,78,98,100,111};
	int alen=sizeof(a)/sizeof(a[0]);
	int blen=sizeof(b)/sizeof(b[0]);
	int i=0;
	int j=0;
	int k=0;
	int c[alen+blen];
	while(i<alen && j<blen)
	{
		if(a[i]>b[j])
		{
			c[k]=b[j];
			j++;
		}
		else{
			c[k]=a[i];
			i++;
		}
		k++;
	}
	if(i==alen)
	{
		while(j<blen)
		{
			c[k]=b[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<alen)
		{
			c[k]=a[i];
			i++;
			k++;
		}
	}
	for(i=0;i<(alen+blen);i++)
	{
		cout<<c[i]<<" ";
	}	
}
