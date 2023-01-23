#include<iostream>
#include<list>
using namespace std;
class Hash
{
	public:
		int data;
		list<int>  *table;
		int bucket;
		Hash(int capacity)
		{
			bucket = capacity;
			table = new list<int>[capacity];
		}
		void insert(int key);
		void remove(int key);
		bool search(int key);
};
void Hash::insert(int key)
{
	int index = key%bucket;
	table[index].push_back(key);

}
void Hash::remove(int key)
{
	int index = key%bucket;
	table[index].remove(key);
}
bool Hash::search(int key)
{
	int index = key%bucket;
	for(auto i:table[index])
	{
		if (i==key)
			return true;
	}
	return false;
}
int main()
{
	Hash n(10);
	n.insert(10);
	n.insert(20);
	cout<<n.search(100)<<endl;
	n.insert(100);
	cout<<n.search(100)<<endl;
	n.remove(100);
	cout<<n.search(100)<<endl;
	cout<<n.search(10)<<endl;
}
