#include<iostream>
#include<list>
using namespace std;
class Hash
{
	public:
		int bucket;
		list<int> * table;
		Hash(int b)
		{
			bucket = b;
			table = new list<int>[b];
		}
		void insert(int key);
		bool search(int key);
		void remove(int key);
};
void Hash:: insert(int key)
{
	int i=key%bucket;
	table[i].push_back(key);
}
bool Hash::search(int key)
{
	int i = key%bucket;
	for (auto x: table[i])
	{
		if(x == key)
			return true;
	}
	return false;
}
void Hash::remove(int key)
{
	int i = key%bucket;
	table[i].remove(key);
}
int main()
{
	Hash n(7);
	n.insert(10);
	n.insert(20);
	cout<<n.search(30)<<endl;
	n.insert(30);
	cout<<n.search(30)<<endl;
	n.remove(30);
	cout<<n.search(30)<<endl;
	n.insert(30);
}
