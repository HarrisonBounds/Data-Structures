#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> array);
void quickSort(vector<int> array, int, int);
int split(vector<int> array, int, int);
void countingSort(vector<int> array);

int main()
{
	int val;
	vector<int> array;
	int low = 0;
	int high = array.size();

	fstream myFile;
	myFile.open("CSCI2320_final_project_dataset.txt");
	//myFile.open("TestSort.txt");

	if (!myFile) //Check to see if the file opened
	{
		cout << "ERROR, your file did not open" << endl;

	}

	else
	{
		cout << "File is open" << endl << endl;
		int i = 0;
		while (!myFile.eof()) //Will go until it is the end of the text file
		{
			myFile >> val;
			array.resize(i + 1);
			array[i] = val;
			i++;
		}
	}

		//Insertion Sort 
		auto start = high_resolution_clock::now(); // Start before calling the function 
		insertionSort(array);
		auto end = high_resolution_clock::now(); //Start after the function call
		auto duration = duration_cast<microseconds>(end - start); //Take the difference of the start and end times

		cout << "The Insertion sort took " << duration.count() << "microseconds, or " << duration.count() / 1000000 << "seconds" << "\n\n";

		//Quick Sort
		start = high_resolution_clock::now(); 
		quickSort(array, low, high);
		end = high_resolution_clock::now(); 
		duration = duration_cast<microseconds>(end - start); 

		cout << "The Quick sort took " << duration.count() << "microseconds, or " << duration.count() / 1000000 << "seconds" << "\n\n";

		
		//Counting Sort
		start = high_resolution_clock::now(); 
		countingSort(array);
		end = high_resolution_clock::now(); 
		duration = duration_cast<microseconds>(end - start); 

		cout << "The Counting sort took " << duration.count() << "microseconds, or " << duration.count() / 1000000 << "seconds" << "\n\n";
		
		
	}


void insertionSort(vector<int> array)
{
	
	for (int p = 1; p < array.size(); p++)
	{
		int tmp = array[p];
		int j;

		for (j = p; j > 0 && tmp < array[j - 1]; j--)
		{
			array[j] = array[j - 1];
		}

		array[j] = tmp;
	}


}

void quickSort(vector<int> array, int low, int high)
{
	if (low < high)
	{
		int pi = split(array, low, high); //pi is the index at the split

		quickSort(array, low, pi - 1); //To the left of the split
		quickSort(array, pi + 1, high); //To the right of the split
	}
}

int split(vector<int> array, int low, int high)
{
	int pivot = array[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (array[j] < pivot)
		{
			i++; 
			swap(array[i], array[j]);
		}
	}

	swap(array[i + 1.0], array[high]); 
	return (i + 1);
}


void countingSort(vector<int> array)
{
	int max = 0;
	int index = 0;

	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	vector<int> temp_array(max + 1);

	for (int i = 0; i < array.size(); i++)
	{
		index = array[i];
		temp_array[index] += 1;
	}

}
