#include<iostream>
using namespace std;

const int CAPACITY = 1023; // An array initialzied for the worst case scenario

class BST
{
private:
	int BST_array[CAPACITY];
	int index;
	int root;
	int max;
	int min;

public:
	BST()
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			BST_array[i] = -1;
		}
		index = 1;
		root = 0;
		int max = 0;
		int min = 0;
	}

	void search(int x)
	{
		index = 1; //Resets the index to start with the root value

		cout << "Target = " << x << endl;

		while (BST_array[index] != x)
		{
			if (BST_array[index] != -1)
			{
				cout << BST_array[index] << "--->";
			}
			index++;

			if (index == CAPACITY)
			{
				cout << "Target is not in the tree!: "; //Displays error message and breaks the loop if the target is not found
				break;
			}
		}

		cout << x << endl << endl; //Displays the target after looping through the tree

		
	}

	int findMax()
	{
		index = 1; //Resets index to look through tree
		max = root; // Starts the max value at the root

		while (BST_array[index] != -1)
		{
			if (BST_array[index] > max)
			{
				max = BST_array[index];
			}

			index = (index * 2) + 1;
		}
		

		cout << "MAX = " << max << endl << endl;

		return max;
	}

	int findMin()
	{
		index = 1; //Resets index to look through tree
		min = root; // Starts the minimum value at the root

		while (BST_array[index] != -1)
		{
			if (BST_array[index] < min)
			{
				min = BST_array[index];
			}
			index = index * 2;
		}

		cout << "MIN = " << min << endl << endl;

		return min;
	}

	void insert(int x)
	{
		index = 1; // Resets index to 1
		if (root == 0) //Initializing the root to the first index
		{
			root = x;
			BST_array[index] = root;
		}

		else
		{
			while (BST_array[index] != -1) //Cycling through the tree to place the value
			{
				if (x < BST_array[index])
				{
					index = index * 2;
				}

				else
				{
					index = (index * 2) + 1;
				}
			}
		}

		if (BST_array[index] == -1) //Placing the value x inside the right location of the tree
		{
			BST_array[index] = x;
		}
	}

	void remove(int x)
	{
		cout << "REMOVING: " << x << endl << endl;
		//CASE 1
		index = 1;

		while (BST_array[index] != x) //Finding the target to delete
		{
			index++;
		}

		if (BST_array[index * 2] == -1 && BST_array[(index * 2) + 1] == -1) //Checking if the value is a leaf
		{
			BST_array[index] = -1;
		}

		//CASE 2
		else if (BST_array[index * 2] != -1 && BST_array[(index * 2) + 1] == -1) //Checking if right child is null
		{
			while (BST_array[index] > BST_array[index / 2] ) // Comparing the child array to the parent incase the child needs to replace it
			{
				BST_array[index] = BST_array[(index * 2) + 1];      //Setting the value of the targets right child to its position
			}
		}

		else if (BST_array[index * 2] == -1 && BST_array[(index * 2) + 1] != -1) //Same thing but for left child
		{
			while (BST_array[index] > BST_array[index / 2])
			{
				BST_array[index] = BST_array[index * 2];
			}
		}

		//CASE 3
		else
		{
			BST_array[index] = BST_array[(index * 2) + 1];       //Setting the rirght child to the element that needs to be deleted
		}
		


	}

	void Print_BST()
	{
		index = 1; // Reset index to root
		cout << "Index          Value" << endl;
		cout << "-----          -----" << endl;

		
		for (int i = 1; i < CAPACITY; i++)
		{
			if (BST_array[index] > 0)
			{
				cout << index << "               " << BST_array[index] << endl << endl;
			}
			index++;
		}
	}

};

int main()
{
	BST g;

	g.insert(5);
	g.insert(8);
	g.insert(3);
	g.insert(1);
	g.insert(4);
	g.insert(9);
	g.insert(18);
	g.insert(20);
	g.insert(19);
	g.insert(2);

	g.Print_BST();

	g.findMax();
	g.findMin();

	g.search(3);
	g.search(18);
	g.search(19);

	g.remove(19);
	g.Print_BST();
	g.remove(2);
	g.Print_BST();
	g.remove(8);
	g.Print_BST();
	g.remove(3);
	g.Print_BST();
	g.remove(5);
	g.Print_BST();
}
