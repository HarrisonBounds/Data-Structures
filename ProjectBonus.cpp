#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 26;
const int COLS = 2;

class StackArray
{
private:
	int array[ROWS][COLS];
	int index_array[ROWS];
	int front_end;
	int back;
	int index;
	int counter;
	int front_count;

public:

	StackArray()
	{
		array[ROWS - 1][COLS - 1] = { 0 };
		index_array[ROWS - 1] = { 0 }; // This array is to hold the spots already been used by the random index
		front_end = -1;
		back = -1;
		index = 0;
		counter = 0;
		front_count = 0;
	}

	bool empty()
	{
		if (front_end == back)
		{
			return true;
		}
	}

	void enqueue(int element)
	{
		bool available = true;

		do
		{
			available = true; //Resets bool value if there is a duplicate

			index = rand() % 26; //Locating a random index in the array

			index_array[counter] = index;

			for (int i = 0; i < counter + 1 && available == true; i++)
			{
				for (int j = i + 1; j < counter + 1 && available == true; j++)
				{
					if (index_array[i] == index_array[j])
					{
						available = false;
					}
					else
					{
						available = true;
					}
				}
			}
		} while (!available);

		if (counter == 0)
		{
			front_end = index_array[0];
		}

		counter++;

		array[index][0] = element; 

		array[index][1] = back; 

		back = index;


	}

	void dequeue()
	{
		
		counter--;

		for (int i = 0; i < counter; i++) //Shifts all elements in array
		{
			index_array[i] = index_array[i + 1];
		}

		front_end = index_array[front_count];

		array[index_array[0]][1] = -1; //Sets the first "next" value  to null

		

	}

	int front()
	{
		cout << "The front is " << array[front_end][0] << "\n\n\n";
		return front_end;
	}

	void display()
	{


		for (int i = counter - 1; i >= 0; i--) 
		{
			cout << "Index: " << index_array[i] << " ----- Data: " << array[index_array[i]][0]
				<< " ----- Next: " << array[index_array[i]][1] << endl;
		}

		cout << "\n\n\n";
	}




};

int main()
{
	srand(time(0));

	StackArray g;

	g.enqueue(1);
	g.enqueue(2);
	g.enqueue(3);
	g.enqueue(4);
	g.enqueue(5);
	g.enqueue(6);
	g.enqueue(7);
	g.enqueue(8);
	g.enqueue(9);
	g.enqueue(10);
	g.display();

	g.enqueue(20);
	g.display();
	g.enqueue(30);
	g.display();
	g.enqueue(40);
	g.display();

	g.front();
	g.dequeue();
	g.display();

	g.front();
	g.dequeue();
	g.display();

	g.front();
	g.dequeue();
	g.display();





}