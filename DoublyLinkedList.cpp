#include<iostream>
using namespace std;
class node
{
	public:
	node* next;
	node* prev;
	int data;
};
class doublyLinkedList
{
	public:
	int length=0;
	node* start;
	node* last;
	node* loc;
	node* ploc;
	
	doublyLinkedList()
	{
		start=NULL;
		last=NULL;
		loc=NULL;
		ploc=NULL;
		length=0;
	}
	bool isempty()
	{
		return start==NULL;
	}
	void print()
	{
		if(!isempty())
		{
				node* temp=start;
				while(temp!=NULL)
				{
					cout<<temp->data<<endl;
					temp=temp->next;
				}
	
		}
		else 
		{
			cout<<"List is empty"<<endl;
		}
	}
	void search(int value)
	{
		if(isempty())
		{
			return;
		}
		loc=start;
		ploc=NULL;
		while(loc!=NULL && loc->data<value )
		{
			ploc=loc;
			loc=loc->next;
		}
		if(loc!=NULL && loc->data!=value)
		{
			loc=NULL;
		}
	}
	void insertatfront(int value)
	{
		node* newnode=new node;
		newnode->data=value;
		if(isempty())
		{
			start=newnode;
			last=newnode;
		}
		else
		{
			newnode->next=start;
			start->prev=newnode;
			start=newnode;
		}
		length++;
		//print();
	}
	void insertatlast(int value)
	{
		node* newnode=new node;
		newnode->data=value;
		if(start==NULL)
		{
			start=newnode;
			last=newnode;
		}
		else{
			last->next=newnode;
			newnode->prev=last;
			last=newnode;
			//newnode->next=NULL;
		}
		length++;
//		print();
	}
	void insertsorted(int value)
	{
		search(value);
		if(loc==NULL)
		{
			if(ploc==NULL)
			{
				insertatfront(value);
			}
			else
			{
				node* newnode=new node;
				newnode->data=value;
				newnode->next=ploc->next;
				newnode->prev=ploc;
				ploc->next->prev=newnode;
				ploc->next=newnode;
				if(ploc==last)
				{
					last=newnode;
				}
				length++;
			}
		}
		else
		{
			cout<<"Duplication not allowed"<<endl;
		}
//		print();
	}
	void deletebyvalue(int value)
	{
		search(value);
		if(loc!=NULL)
		{
			if(ploc==NULL)
			{
				if(loc==last)
				{
					start=NULL;
					last=NULL;
				}
				else
				{
					start=start->next;
					start->prev=NULL;
				}
			}
			else
			{
				if(loc==last)
				{
					last=last->prev;
					last->next=NULL;
				}
				else
				{
					ploc->next=loc->next;
					loc->next->prev=ploc;
				}
			}
			delete loc;
		}
		else
		{
			cout<<"Value not found"<<endl;
		}
	//	print();
	}
	void destroylist()
	{
		if(!isempty())
		{
			node* temp;
			while(start!=NULL)
			{
				temp=start;
				start=start->next;
				delete temp;
			}
			last=NULL;
		}
		else{
			cout<<"List is empty"<<endl;
		}
	}
};
int main()
{//Creating object of list class
	doublyLinkedList s;
	int option;//variable to store integer value
	int data1;
	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert()" << endl;
		cout << "2. Delete()" << endl;
		cout << "3. Print()" << endl;
		cout << "4. DestroyList()" << endl;
		cout << "0 exit" << endl;

		cin >> option;
	
		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Enter value you want to insert" << endl;
			cin >> data1;
			s.insertsorted(data1);
			//cout<<n1.key<<" = "<<n1.data<<endl;
			break;

		case 2:
			cout << "Enter Value you want to delete" << endl;
			cin >> data1;
			s.deletebyvalue(data1);
			break;
		case 3:
			s.print();
			break;
		case 4:
		s.destroylist();
		break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);//if user inputs 0 the program stops

	return 0;
}