//Permutations

#include <bits/stdc++.h> 

using namespace std; 

// function to print combinations that contain one element from each of the given strings 
void printComb(vector<vector<char>> &arr) 
{ 
	// number of arrays 
	int n = arr.size(); 

	
	int* indices = new int[n]; 

	// initialize with first element's index 
	for (int i = 0; i < n; i++) 
		indices[i] = 0; 

	while (1) { 

		 
		for (int i = 0; i < n; i++) 
			cout << arr[i][indices[i]] << " "; 
		cout << endl; 

		
		int next = n - 1; 
		while (next >= 0 && 
			(indices[next] + 1 >= arr[next].size())) 
			next--; 

		
		if (next < 0) 
			return; 

		
		indices[next]++; 

		for (int i = next + 1; i < n; i++) 
			indices[i] = 0; 
	} 
} 
void create() 
{ 
	// file pointer 
	fstream fout; 

	// opens an existing csv file or creates a new file. 
	fout.open("Input_data.csv", ios::out | ios::app); 

    cout<<"Enter the number of strings: \n";
    int n;
    cin>>n;
	cout << "Enter the strings: \n";
	
	// Read the input 
	for (int i = 0; i < n; i++) { 

		string temp;
		cin>>temp; 

		// Insert the data to file 
		for(int i=0;i<temp.size();i++)
		{
			fout<<temp[i]<<",";
		}
		fout<<"\n";
	} 
} 

vector<vector<char>> read_record() 
{ 

	// File pointer 
	fstream fin; 

	// Open an existing file 
	fin.open("Input_data.csv", ios::in); 

	
	vector<char> row; 
	string temp; 
	vector<vector<char>> vect;

	while (fin >> temp) { 

		row.clear(); 

        for(int i=0;i<temp.size();i++)
        {
        	if(temp[i]!=',')
        	{
        		row.push_back(temp[i]);
			}
        	
		}
		
		vect.push_back(row);
	} 

	return vect;	
} 


int main() 
{ 
    //create the csv file containing strings
    create();
    //reading the csv file and returning the vector of vectors
    vector<vector<char>> vect = read_record();
    //printing the permutation
	printComb(vect); 
} 

