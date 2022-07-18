#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int ROWS = 26;
const int COLS = 2;

class StackArray
{
private:
	int array[ROWS][COLS];
	int index_array[ROWS];
	int myTop;
	int index;
	int counter;

public:

	StackArray()
	{
		array[ROWS - 1][COLS - 1] = { 0 };
		index_array[ROWS - 1] = { 0 }; // This array is to hold the spots already been used by the random index
		myTop = -1;
		index = 0;
		counter = 0;
	}

	bool empty()
	{
		if (myTop == -1)
		{
			return true;
		}
	}

	void push(int element)
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


		counter++;
		

		array[index][0] = element; // assigning the element to the random index

		array[index][1] = myTop; //Assigning the top vale to the "next" spot in the array

		myTop = index;           //Assigning the index to top


	}

	void pop()
	{
		counter--;
		myTop = index_array[counter - 1];
	}

	int top()
	{
		cout << "The current top is " << array[myTop][0] << "\n\n\n";
		return myTop;
	}

	void display()
	{
		
		for (int i = counter - 1; i >= 0; i--) //FIX  -- REVERSE 
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

	g.push(1);
	g.push(2);
	g.push(3);
	g.push(4);
	g.push(5);
	g.push(6);
	g.push(7);
	g.push(8);
	g.push(9);
	g.push(10);
	g.display();

	g.push(20);
	g.display();
	g.push(30);
	g.display();
	g.push(40);
	g.display();

	g.top();
	g.pop();
	g.display();

	g.top();
	g.pop();
	g.display();

	g.top();
	g.pop();
	g.display();





}