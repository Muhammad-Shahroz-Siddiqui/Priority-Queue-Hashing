#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;


template<typename k,typename i,typename o>
struct Node
{
	k key;
	i id;
	o op_type;
	public:
		Node()
		{
		}
		
		Node(k ky,i d,o type)
		{
			key = ky;
			id = d;
			op_type = type;
		}
};


template<typename k,typename i,typename o>
class MaxHeap
{
	vector<Node<k,i,o>> r;
	Node<k,i,o> min;
	int totalitems;
	
	public:
		MaxHeap()
		{
			totalitems = 0;
		}
		
		
		void builtqueue(Node<k,i,o> temp[],int size)
		{
			for(int u=0;u<size;u++)
			{
				r.push_back(temp[u]);
				totalitems++;
			}
			for(int x = size/2;x>= 0;x--)
			{
				Heapify(x);
			}
			for(int x=0;x<r.size();x++)
			{
				if(min.key > r[x].key)
				{
					min = r[x];
				}
			}
		}
		
		
		void Heapify(int x)
		{
			int l = (2 * x) + 1;
			int rig = (2 * x) + 2;
			int large = x;
			if(l < totalitems && r[l].key > r[large].key)
			{
				large = l;
			}
			if(rig < totalitems && r[rig].key > r[large].key)
			{
				large = rig;
			}
			if(large != x)
			{
				swap(r[x],r[large]);
				Heapify(large);
			}
		}
		
		
		
		Node<k,i,o> extractMax()
		{
			Node<k,i,o> u;
			if(totalitems == 0)
			{
				return u;
			}
			u = r[0];
			--totalitems;
			r[0] = r[totalitems];
			r.pop_back();
			Heapify(0);
			return u;
		}
		
		
		
		Node<k,i,o> findmax()
		{
			if(r.size() != 0)
			{
				return r[0];
			}
		}
		
		
		
		Node<k,i,o> findmin()
		{
			if(r.size() != 0)
			{
				return min;
			}
		}
		
		void Insert(k ky,i d,o type)
		{
			++totalitems;
			Node<k,i,o> u(ky,d,type);
			r.push_back(u);
			if(min.key > ky)
			{
				min = u;
			}
			int f = totalitems - 1;
			while(f > 0 && r[f].key > r[f/2].key)
			{
				swap(r[f],r[f/2]);
				f = f/2;
			}
		}
		
		
		
		int size()
		{
			return r.size();
		}
		
		
		bool empty()
		{
			if(r.size() == 0)
			{
				return true;
			}
			return false;
		}
		
		
		
		
		void print()
		{
			for(int x = 0; x < r.size(); x++)
			{
				cout<<"Key : "<<r[x].key<<" ID : "<<r[x].id<<endl;
			}
		}
};



int main()
{
	//Key and ID as Integer and Bool for Read/Write
//	MaxHeap<int,int,bool> p1;
//	p1.Insert(25,2,0);
//	p1.Insert(1,12,0);
//	p1.Insert(28,5,0);
//	p1.Insert(2,12,0);
//	p1.Insert(38,2,0);
//	p1.Insert(68,2,0);
//	p1.print();
//	
//	Node<int,int,bool> min = p1.findmin();
//	cout<<"\nMin Element Key = "<<min.key<<endl;
//	min = p1.findmax();
//	cout<<"Max Element Key = "<<min.key<<endl;
//	Node<int,int,bool> v1[10];
//	for(int x=0;x<10;x++)
//	{
//		v1[x].key = x+1;
//		v1[x].id = x+2;
//		v1[x].op_type = 0;
//	}
//	
//	p1.builtqueue(v1,10);
//	p1.print();
}







