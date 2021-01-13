//Name-Alok Bhatt
//Roll No.-2014548

#include <iostream>
#define N 9
using namespace std;

// Sodoku Grid
int grid[N][N];


// Function to check whether num is present in the col or not
bool isInCol(int col, int num){ 
   for (int i = 0; i < N; i++)
      if (grid[i][col] == num)
         return true;
   return false;
}


// Function to check whether num is present in the row or not
bool isInRow(int row, int num){ 
   for (int i = 0; i < N; i++)
      if (grid[row][i] == num)
         return true;
   return false;
}

// Function to check whether num is present in the 3x3 box or not
bool isInBox(int startRow, int startCol, int num){
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (grid[i + startRow][j + startCol] == num)
            return true;
   return false;
}

// Function to print Sodoku Box
void printGrid(){ 
   for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
         if(j == 3 || j == 6)
            cout << " | ";
         cout << grid[i][j] <<" ";
      }
      if(i == 2 || i == 5){
         cout << endl;
         for(int k = 0; k < N; k++)
            cout << "---";
      }
      cout << endl;
   }
}


// Function to find empty locations and fill them
bool findEmpty(int &row, int &col){ 
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) 
            return true;
   return false;
}

// Fuction to find valid number for the place
bool isValid(int row, int col, int num){
   return !isInRow(row, num) && !isInCol(col, num) && !isInBox(row - row%3, col - col%3, num);
}



bool solve(){
   int row, col;
   if (!findEmpty(row, col))
      return true; 
   for (int num = 1; num <= 9; num++){ 
      if (isValid(row, col, num)){ 
         //check validation, if yes, put the number in the grid
         grid[row][col] = num;
         //recursively go for other places in the grid
         if (solve()) 
            return true;
         grid[row][col] = 0;
         //Place 0 when valid number is not found
      }
   }
   return false;
}

int main(){
    cout << "\n\t *** Sodoku Solver ***";
    cout << "\n\nEnter the sodoku problem Row-wise: \nEnter 0 for blank positions";
    cout << "\n\n-----------------------------\n\n";
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    
    cout << "\n\n---- ** Answer ** ----\n\n";
    if (solve() == true)
      printGrid();
    else
      cout << "No Solution";

    return 0;
}
