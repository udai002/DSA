#include<iostream>
#include<list>
using namespace std;
class Hash
{
	public:
	    int *table;
		int cap;
		int size;
		Hash(int c)
		{
			cap= c;
			table = new int[cap];
			for(int i=0;i<c;i++)
				table[i] = -1;
		}
		bool search(int key);
		bool insert(int key);
		bool remove(int key);
		void display();
};
bool Hash::insert(int key)
{
	if(size==cap) {
		cout<<"List is Full"<<endl;
		return false;
	}
	int i = key%cap;
	while((table[i]!=-1) && (table[i]!=-2) && (table[i]!=key))
	{
		i = (i+1)%cap;
	} 
	if (table[i]==key) {
		cout<<"Key is already Present"<<endl;
		return false;
	}
	else {
		cout<<"Else"<<endl;
		table[i]=key;
		size++;
		return true;
	}
}
void Hash::display()
{
    cout<<"Display"<<endl;
    for(int i=0;i<cap;i++)
    {
        cout<<table[i]<<" ";
    }
}

bool Hash::search(int key)
{
    int i = key%cap;
    while(table[i]!= -1 && table[i]!=key )
    {
        i=(i+1)%cap;
    }
    if(table[i] == key)
        return true;
    else
        return false;
}
bool Hash::remove(int key)
{
    int i = key%cap;
    while(table[i] != -1)
    {
        if(table[i]==key)
        {
            table[i]=-2;
            size--;
            return true;
        }
        i=(i+1)%cap;
        if(i==key%cap)
            return false;
    }
    return false;
}
int main()
{
	Hash n(7);
	cout<<n.insert(49)<<endl;
	cout<<n.insert(63)<<endl;
    n.display();
	cout<<n.insert(56)<<endl;
	n.display();
	cout<<n.insert(52)<<endl;
	n.display();	
	cout<<n.remove(52)<<endl;
	n.display();
	cout<<n.insert(52)<<endl;
	n.display();
  	cout<<n.insert(54)<<endl;
	cout<<n.insert(48)<<endl;
	cout<<n.insert(52)<<endl;
	n.display();
}
