#include<iostream>
using namespace std;



class node
{
public:
	int data;
	node* next;
};

class PointerList
{
public:
	PointerList()
	{
		top = NULL;
	}

	bool empty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

	void insert(int element, int value)
	{
		node* newptr = new node;
		newptr->data = element;

		if (top == NULL)			//insert the very first element
			if (value == 0)
			{
				newptr->next = NULL;
				top = newptr;
			}
			else
				cout << "Location Error!!";
		else
			if (value == 0)		//insert on the first position when some elements existed
			{
				newptr->next = top;
				top = newptr;
			}
			else				//most cases belongs to this situation (as showed in the class slide)
			{
				node* preptr;
				preptr = top;

				while (preptr->data != value)
				{
					preptr = preptr->next;
					if (!preptr)
					{
						if (value != top->data)
						{
							cout << "ERROR, value given does not exist in the list" << endl;
						}
						break;
					}
					
				}

				if (preptr)
				{
					newptr->next = preptr->next;
					preptr->next = newptr;
				}
			}
	}

	void remove(int value)
	{
		if (value == 0)			//delete the first element
		{
			node* ptr = top;
			top = ptr->next;
			delete(ptr);
		}
		else
		{
			node* preptr;
			preptr = top;

			while (preptr->data != value)
			{
				preptr = preptr->next;

				if (!preptr)
				{
					if (value != top->data)
					{
						cout << "ERROR, value given does not exist in the list" << endl;
					}
					break;
				}
			}


			if (preptr)
			{
				node* ptr = preptr->next;
				preptr->next = ptr->next;
				delete(ptr);
			}
		}
	}


	void print()
	{
		node* temp;
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << endl;
	}

private:
	node* top;

};


int main() {
	PointerList* sl = new PointerList();

	sl->insert(10, 0);   //current linked list: 10 (default status, when empty)   
	sl->insert(20, 10);	//current linked list: 10->20
	sl->insert(30, 20);	//current linked list: 10->20->30
	sl->insert(40, 20);	//current linked list: 10->20->40->30
	sl->insert(50, 30);	//current linked list: 10->20->40->30->50
	sl->print();
	sl->insert(60, 50);	//current linked list: 10->20->40->30->50->60
	sl->insert(70, 5);	//error, no 5 existed in the linked list
	sl->print();
	sl->remove(30); 	//current linked list: 10->20->40->30->60
	sl->print();
	sl->remove(10);	//current linked list: 10->40->30->60
	sl->print();
	sl->remove(50);	//error, no 50 existed in the linked list
	sl->print();

	return 0;
}





