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

	void insert(int element, int position)
	{
		node* newptr = new node;
		newptr->data = element;

		if (top == NULL)			//insert the very first element
			if (position == 0)
			{
				newptr->next = NULL;
				top = newptr;
			}
			else
				cout << "Location Error!!";
		else
			if (position == 0)		//insert on the first position when some elements existed
			{
				newptr->next = top;
				top = newptr;
			}
			else				//most cases belongs to this situation (as showed in the class slide)
			{
				node* preptr;
				preptr = top;

				for (int i = 0; i < position - 1; i++)
					preptr = preptr->next;

				newptr->next = preptr->next;
				preptr->next = newptr;
			}
	}

	void remove(int position)
	{
		if (position == 0)			//delete the first element
		{
			node* ptr = top;
			top = ptr->next;
			delete(ptr);
		}
		else
		{
			node* preptr;
			preptr = top;
			for (int i = 0; i < position - 1; i++)
				preptr = preptr->next;

			node* ptr = preptr->next;
			preptr->next = ptr->next;
			delete(ptr);
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
	sl->insert(10, 0);
	sl->insert(20, 1);
	sl->insert(30, 2);
	sl->insert(40, 3);
	sl->insert(40, 4);
	sl->print();
	sl->insert(50, 0);
	sl->insert(60, 3);
	sl->insert(70, 5);
	sl->print();
	sl->remove(2);
	sl->print();
	sl->remove(1);
	sl->print();
	sl->remove(3);
	sl->print();
	


	return 0;
}