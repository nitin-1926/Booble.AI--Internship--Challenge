#include <iostream> 
#include <vector>
#include <fstream>          //fstream header file for ifstream class 
#include<string>

using namespace std; 

void printPermutations(vector <vector<char>> &inputs){
     
    int n = inputs.size();                          // number of arrays
    
    int flag = 0;                       //to keep track of initial permutation while printing
     
    int* indices = new int[n];                      // to keep track of next element in each of the n arrays
  
     
    for (int i = 0; i < n; i++){            // initialize with first element's index
        indices[i] = 0;
    } 
  
    while (1) { 
  
        if(flag == 0){                                              //check if it's first time printing or not
            for (int i = 0; i < n; i++){
                    cout << inputs[i][indices[i]];                  // print current combination
            }
            flag = 1;
        }
        else{
            cout << ", ";
            for (int i = 0; i < n; i++){
                cout << inputs[i][indices[i]];
            }
        }

         
        int next = n - 1;                                                          // find the rightmost array that has more                                 
        while (next >= 0 &&  (indices[next] + 1 >= inputs[next].size())){             // elements left after the current element
            next--;                                                                // in that array
        }
   
        if (next < 0)                               // no such array is found so no more  combinations left
            return; 
   
        indices[next]++;                                    // if found move to next element in that array
   
        for (int i = next + 1; i < n; i++){         // for all arrays to the right of this array current index again points to first element
            indices[i] = 0; 
        } 
    }
}
int main() 
{ 
	ifstream fin;               // Creation of ifstream class object to read the file

	fin.open("input.csv");      // by default open mode = ios::in mode 
    
    string line;                // variable declared to store each line read
    
    vector <vector<char>> inputs;       //2D vector declared to store the inputs
 	 
	while (fin) {                       // Execute a loop until EOF (End of File)
		 
		getline(fin, line);         // Read a Line from File
        
        int n = line.length();      //Store the length of the line in a variable
        
        if(n==0){                   //Check if the line if empty and the skip a loop for it
            continue;
        }
        
        vector<char> temp;              //Temperory Vector to store each character
        
        for(int k=0;k<n;k++){           //Loop to extract each character. ',' acts as a delimiter and characters stored in vector temp
            if(line[k] == ','){
                continue;
            }
            else{
                temp.push_back(line[k]);
            }
        }
        inputs.push_back(temp);                 //Row is inserted into 2D vector inputs
	}
   
    printPermutations(inputs);              //Function called to calculate and print all possible permutations
    
    cout<<endl;
	 
	fin.close();                        // Close the file

	return 0; 
} 
