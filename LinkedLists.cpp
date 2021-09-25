#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};
class SinglyLinkedList
{
public:
	Node* start;
	Node* last;
	int length;
	Node* loc;
	Node* ploc;
	SinglyLinkedList()
	{
		start = NULL;
		last = NULL;
		length = 0;
		loc = NULL;
		ploc = NULL;
	}
	bool isempty()
	{
		return start == NULL;
	}
	void printlist()
	{
		if (!isempty())
		{
			Node* temp = start;
			while (temp != NULL)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}
	void Search(int value)
	{
		loc = start;
		ploc = NULL;
		//if (isempty())
	//	{
			//cout << "list is empty" << endl;
		//	return;
		//}
		while (loc != NULL && loc->data < value)
		{
			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL && loc->data != value)
		{
			loc = NULL;
		}
	}
	void Insertatfront(int value)
	{
		Node* newnode = new Node();
		newnode->data = value;
		if (isempty())
		{
			start = newnode;
			last = newnode;
		}
		else
		{
			newnode->next = start;
			start = newnode;
		}
		length++;
	}
	/*void Insertatend(int value)
	{
		Node* newnode = new Node();
		newnode->data = value;
		if (!isempty())
		{
		    last->next=newnode;
			last = newnode;
		}
		else
		{
			start = newnode;
			last = newnode;
		}
		length++;
	}*/
	void Insertsorted(Node* n)
	{
		Search(n->data);
		if (loc == NULL)
		{
			if (ploc == NULL)
			{
				Insertatfront(n->data);
			}
			else
			{
				Node* newnode = new Node();
				newnode->data = n->data;
				newnode->next = ploc->next;
				ploc->next = newnode;
				if (ploc == last)
				{
					last = newnode;

				}
				length++;
			}
		}
		else
		{
			cout << "Duplication not allowed" << endl;
		}
	}
	void Deletebyvalue(Node* n)
	{
		if (!isempty())
		{
			Search(n->data);
			if (loc != NULL)
			{
				if (start == last)
				{
					start = NULL;
					last = NULL;

				}
				else if(ploc==NULL)
				{
					Node* temp;
					temp = start->next;
					delete start;
					start = temp;
				}
				else if (loc->next = NULL)
				{
					delete last;
					last = ploc;
					ploc->next = NULL;
				}
				else {
					ploc->next = loc->next;
					delete loc;
				}
			}
			else
			{
				cout << "Value not found" << endl;
			}
		}
		else
		{
			cout << "List is empty" << endl;
		}
		

	}
	void Destroylist()
	{
		Node* temp;
		while (start != NULL)
		{
			temp = start;
			start = start->next;
			delete temp;
		}
		last = NULL;
	}
};
int main()
{
	SinglyLinkedList s;
	int option;
	int data1;
	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert()" << endl;
		cout << "2. Delete()" << endl;
		cout << "3. Print()" << endl;
		cout << "4. Clear Screen" << endl;
		cout << "0 exit" << endl;

		cin >> option;
		Node* n1 = new Node();
		//Node n1;

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Enter value you want to insert" << endl;
			cin >> data1;
			n1->data = data1;
			s.Insertsorted(n1);
			//cout<<n1.key<<" = "<<n1.data<<endl;
			break;

		case 2:
			cout << "Enter Value you want to delete" << endl;
			cin >> data1;
			n1->data = data1;
			s.Deletebyvalue(n1);
			break;
		case 3:
			s.printlist();

			break;
		case 4:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}


