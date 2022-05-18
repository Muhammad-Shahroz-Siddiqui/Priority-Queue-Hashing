#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
struct List
{
	template <typename F>
	struct node
	{
	public:
		F Data;
		node* next;
		node(T _data, node* _next = nullptr)
		{
			Data = _data;
			next = _next;
		}
	};
public:
	node<T> * head;
	node<T> * tail;
	List()
	{
		head = tail = nullptr;
	}
	List(const List& L)
	{
		node<T>* temp = L.head;
		while (temp != nullptr)
		{
			insertAtEnd(temp->Data);
			temp = temp->next;
		}
	}
	const List* operator = (const List& L)
	{
		node<T>* temp = L.head;
		while (temp != nullptr)
		{
			insertAtEnd(temp->Data);
			temp = temp->next;
		}
		return this;
	}
	void insertAtStart(T const element)
	{
		node<T>* newEle = new node<T>(element, nullptr);
		if (head == nullptr)
		{
			head = tail = newEle;
		}
		else
		{
			node<T>* temp = head;
			head = newEle;
			newEle->next = temp;
		}
	}
	void insertAtEnd(T const element)
	{
		node<T>* newEle = new node<T>(element, nullptr);
		if (tail == nullptr)
		{
			head = tail = newEle;
		}
		else
		{
			node<T>* temp = tail;
			tail = newEle;
			temp->next = newEle;
		}
	}
	void print()
	{
		if (head != nullptr)
		{
			cout << "List:\n";
			node<T>* curptr = head;
			while(curptr != nullptr)
			{
				cout << curptr->Data << endl;
				curptr = curptr->next;
			}
			cout << endl;
		}
	}

	bool search(T const& element) const
	{
		if (head != nullptr)
		{
			node<T>* curptr = head;
			while(curptr != nullptr)
			{
				if (element == curptr->Data)
				{
					return true;
				}
				curptr = curptr->next;
			}
		}
		return false;
	}

	bool isEmpty() const
	{
		if (head == nullptr) { return true; } else { return false; }
	}

	bool insertBefore(T const v1, T const v2)
	{
		if (head != nullptr)
		{
			node<T>* preptr = nullptr;
			node<T>* curptr = head;
			while(curptr != nullptr)
			{
				if (v2 == curptr->Data)
				{
					node<T>* newEle = new node<T>(v1, curptr);
					if (preptr != nullptr)
					{
						preptr->next = newEle;
					}
					else
					{
						head = newEle;
					}
					return true;
				}
				preptr = curptr;
				curptr = curptr->next;
			}
		}
		return false;
	}

	void deleteAll(T const value)
	{
		if (head != nullptr)
		{
			node<T>* preptr = nullptr;
			node<T>* curptr = head;
			node<T>* nextptr = head->next;
			while(curptr != nullptr)
			{
				if (value == curptr->Data)
				{
					if (preptr == nullptr)
					{
						curptr = nextptr;
						nextptr = nextptr->next;
						DeleteAtStart();
					}
					else
					{
						preptr->next = nextptr;
						delete curptr;
						curptr = nextptr;
						if (nextptr != nullptr)
						{
							nextptr = nextptr->next;
						}
					}
				}
				else
				{
					preptr = curptr;
					curptr = curptr->next;
					if (nextptr != nullptr)
					{
						nextptr = nextptr->next;
					}
				}
			}
		}
	}

	void DeleteAtStart()
	{
		if (head != nullptr)
		{
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void MergeSort(const List& L)
	{
		if (L.head != nullptr)
		{
			node<T>* preptr = nullptr;
			node<T>* arr1ptr = head;
			node<T>* arr2ptr = L.head;
			bool exitL = false;
			while (arr2ptr != nullptr)
			{
				if (arr1ptr != nullptr)
				{
					if (arr1ptr->Data > arr2ptr->Data)
					{
						if (arr1ptr == head)
						{
							insertAtStart(arr2ptr->Data);
							arr1ptr = head;
							arr2ptr = arr2ptr->next;
							preptr = arr1ptr;
						}
						else
						{
							node<T>* newEle = new node<T>(arr2ptr->Data, arr1ptr);
							preptr->next = newEle;
							preptr = preptr->next;
							arr2ptr = arr2ptr->next;
						}
					}
					else
					{
						preptr = arr1ptr;
						arr1ptr = arr1ptr->next;
					}
				}
				else
				{
					insertAtEnd(arr2ptr->Data);
					arr2ptr = arr2ptr->next;
				}
			}
		}
	}

	~List()
	{
		if (head != nullptr)
		{
			while (head != nullptr)
			{
				DeleteAtStart();
			}
		}
	}
};

template<typename k,typename i,typename o>
struct Node
{
	k priority;
	i user_id;
	o op_type; //0 for Read and 1 for Write
	public:
		Node()
		{
		}
		
		Node(k ky,i d,o type)
		{
			priority = ky;
			user_id = d;
			op_type = type;
		}
};


template<typename k,typename i,typename o>
struct MaxHeap
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
				if(min.priority > r[x].priority)
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
			if(l < totalitems && r[l].priority > r[large].priority)
			{
				large = l;
			}
			if(rig < totalitems && r[rig].priority > r[large].priority)
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
			if(min.priority > ky)
			{
				min = u;
			}
			int f = totalitems - 1;
			while(f > 0 && r[f].priority > r[f/2].priority)
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
				if(x == 0)
				{
					cout<<"Access Given"<<endl;
				}
				else if(x == 1)
				{
					cout<<"In Waiting"<<endl;
				}
				cout<<"User ID : "<<r[x].user_id<<" Priority : "<<r[x].priority<<" Access Type : ";
				if(r[x].op_type == 0)
				{
					cout<<"Read"<<endl;
				}
				else if(r[x].op_type == 1)
				{
					cout<<"Write"<<endl;
				}
			}
		}
};


template<typename k,typename p ,typename i,typename o>
struct Hashitem
{
	k file_id;
	MaxHeap<p,i,o> *waiting;
	MaxHeap<p,i,o> *active;
};


template<typename k,typename p,typename i,typename o>
struct Hashtable
{
	List<Hashitem<k,p,i,o>> *arr;
	public:
		Hashtable()
		{
			arr = new List<Hashitem<k,p,i,o>>[9];
		}
		
		int cal_hash(k f_id)
		{
			if((f_id >= 5000 && f_id <=5999) || (f_id >= 50000 && f_id <= 59999))
			{
				return 0;
			}
			if((f_id >= 6000 && f_id <= 6999) || (f_id >= 60000 && f_id <= 69999))
			{
				return 1;
			}
			if((f_id >= 7000 && f_id <= 7999) || (f_id >= 70000 && f_id <= 79999))
			{
				return 2;
			}
			if((f_id >= 8000 && f_id <= 8999) || (f_id >= 80000 && f_id <= 89999))
			{
				return 3;
			}
			if((f_id >= 9000 && f_id <= 9999) || (f_id >= 90000 && f_id <= 99999))
			{
				return 4;
			}
			if(f_id >= 10000 && f_id <= 19999)
			{
				return 5;
			}
			if(f_id >= 20000 && f_id <= 29999)
			{
				return 6;
			}
			if(f_id >= 30000 && f_id <= 39999)
			{
				return 7;
			}
			if(f_id >= 40000 && f_id <= 49999)
			{
				return 8;
			}	
		}
		
		void i_file(k f_id)
		{
			Hashitem<k,p,i,o> f1;
			f1.file_id = f_id;
			int index = cal_hash(f_id);
			arr[index].insertAtEnd(f1);
		}
		
		
		void req_access( k f_id, p p_id, i u_id , o op_type)
		{
			
		}
};





main()
{
	Hashtable<int,int,int,bool> p1;
	p1.i_file(6500);
	p1.arr[0].;
//	Hashitem<int,int,int,bool> a;
//	a.file_id = 7001;
//	a.users.Insert(2,6000,0);
//	a.users.Insert(3,2500,1);
//	
//	
//	
//
//	Hashitem<int,int,int,bool> a2;
//	a.file_id = 8002;
//	a.users.Insert(2,6000,0);
//	a.users.Insert(3,2500,1);
//
//
//
//
//	Hashitem<int,int,int,bool> a3;
//	a.file_id = 5603;
//	a.users.Insert(2,6000,0);
//	a.users.Insert(3,2500,1);
//
//
//
//	Hashitem<int,int,int,bool> a4;
//	a.file_id = 5034;
//	a.users.Insert(2,6000,0);
//	a.users.Insert(3,2500,1);
//
//
//
//
//	Hashitem<int,int,int,bool> a5;
//	a.file_id = 5012;
//	a.users.Insert(2,6000,0);
//	a.users.Insert(3,2500,1);
//
//
//
//
//
//	Hashtable<int,int,int,bool> p1(a);
//	
//	cout<<p1.h_arr[0].file_id<<endl;
//	p1.h_arr[1].users.print();
}
