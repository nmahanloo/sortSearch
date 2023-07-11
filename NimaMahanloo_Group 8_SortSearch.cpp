// Nima Mahanloo
// SortBubbleSelectionInsertion
// CISP 430
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
// A module to swap array'S members
void dataSwap(int (&arr)[5][4], int rIndex, int cIndex, int rIndexS, int cIndexS)
{
    int temp;
    temp = arr[rIndex][cIndex];
    arr[rIndex][cIndex] = arr[rIndexS][cIndexS];
    arr[rIndexS][cIndexS] = temp;
}
// A module to display array's members
void displaySorted(int arr[5][4])
{
    cout << endl;
    int row, col;
    for (row = 0; row < 5; row++)
    {
        for (col = 0; col < 4; col++)
            {
                cout << arr[row][col] << " ";
            }
        cout << endl;
    }
}
// Program main class
class sorting
{
    public:
        sorting(int [5][4]);
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void shellSort();
        void binarySearch();
        void resetArray(int [5][4]);
    private:
        int inputArray[5][4];
        int rIndex, cIndex;
};
// Program class construction
sorting::sorting(int inArray[5][4])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            inputArray [i][j] = inArray[i][j];
        }
    }
    rIndex = 0;
    cIndex = 0;
}
// A module to sort array's first column by bubble sort algorithm
void sorting::bubbleSort()
{
    cout << endl << "1.Bubble sort on the 1st column (Asc):" << endl;
    for (rIndex = 0; rIndex < 4; rIndex++)
    {
        for (cIndex = 0; cIndex < 4-rIndex; cIndex++)
        {
            if (inputArray[cIndex][0] > inputArray[cIndex+1][0])
                {
                    dataSwap(inputArray, cIndex, 0, (cIndex+1), 0);
                }
        }
    }
    displaySorted(inputArray);
}
// A module to sort array's second column by selection sort algorithm
void sorting::selectionSort()
{
    cout << endl << "2.Selection sort on the 2nd column (Desc):" << endl;
    int maxValue;
    for (rIndex = 0; rIndex < 5; rIndex++)
    {
        maxValue = rIndex;
        for (cIndex = rIndex+1; cIndex < 5; cIndex++)
        {
            if (inputArray[rIndex][1] < inputArray[cIndex][1])
            {
                maxValue = cIndex;
            }
        }
        if(maxValue != rIndex)
        {
            dataSwap(inputArray, rIndex, 1, maxValue, 1);
        }
    }
    displaySorted(inputArray);
}
// A module to sort array's fifth row by insertion sort algorithm
void sorting::insertionSort()
{
    cout << endl << "3.Insertion sort on the 5th row (Asc):" << endl;
    for (rIndex = 1; rIndex < 4; rIndex++)
    {
        if (inputArray[4][rIndex] < inputArray[4][rIndex-1])
        {
            dataSwap(inputArray, 4, rIndex, 4, rIndex-1);
            for (cIndex = rIndex-1; cIndex > 0; cIndex--)
            {
                if (inputArray[4][cIndex] < inputArray[4][cIndex-1])
                {
                    dataSwap(inputArray, 4, cIndex, 4, cIndex-1);
                }
            }
        }
    }
    displaySorted(inputArray);
}
// A module to sort array's third column by shell sort algorithm
void sorting::shellSort()
{
    cout << endl << "5.Shell sort on the 3rd column (Asc):" << endl;
    int n = 5;
    int gap = 2;
    while (gap > 0)
    {
        for(rIndex = 0; rIndex+gap < n; rIndex++)
        {
            if (inputArray[rIndex][2] > inputArray[rIndex+gap][2])
            {
                dataSwap(inputArray, rIndex, 2, rIndex+gap, 2);
            }
        }
        gap = gap/2;
    }
    displaySorted(inputArray);
}
// A module to search key in fifth row's sorted values by binary search
void sorting::binarySearch()
{
    bool binSearch = true;
    bool found = false;
    bool prev = false, next = false;
    int key, pivot;
    int startZone = 0, endZone = 4;
    cout << endl << "4.Binary Search :" << endl;
    cout << "Please select and enter an item from 5th row in the list > ";
    cin >> key;
    while (binSearch == true)
    {
        pivot = (endZone + startZone) / 2;
        if (key > inputArray[4][pivot])
        {
            if (pivot == endZone)
            {
                binSearch = false;
            }
            else
            {
                startZone = pivot + 1;
            }
        }
        else if ((key < inputArray[4][pivot]) && (pivot >= startZone))
        {
            if (pivot == startZone)
            {
                binSearch = false;
            }
            else
            {
               endZone = pivot - 1;
            }
        }
        else if (key == inputArray[4][pivot])
        {
            found = true;
            binSearch = false;
        }
    }
    if (found == true)
    {
        if (inputArray[4][pivot-1] == key)
        {
            prev = true;
        }
        if (inputArray[4][pivot+1] == key)
        {
            next = true;
        }
        if (prev == true)
        {
            cout << key << " found on the 5th row at position numbers " << pivot << " and " << pivot+1 << endl;
        }
        else if (next == true)
        {
            cout << key << " found on the 5th row at position numbers " << pivot+1 << " and " << pivot+2 << endl;
        }
        else
        {
            cout << key << " found on the 5th row at position no." << pivot+1 << endl;
        }
    }
    else
    {
        cout << key << " is not available at this row" << endl;
    }
}
// A module to reset class array to origin
void sorting::resetArray(int inArray[5][4])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            inputArray [i][j] = inArray[i][j];
        }
    }
}

int main()
{
    srand(time(0));
    int iRow, iCol, temp = -1;
    bool first;
    int toSortArray [5][4];
    cout << "Original Array:" << endl << endl;
    for (iRow = 0; iRow < 5; iRow++)
    {
        first = true;
        for (iCol = 0; iCol < 4; iCol++)
        {
            toSortArray[iRow][iCol] = temp;
            while (toSortArray[iRow][iCol] == temp)
            {
                toSortArray[iRow][iCol] = rand() %10;
            }
            temp = toSortArray[iRow][iCol];
            cout << temp << " ";
        }

        cout << endl;
    }
    sorting sortArray(toSortArray);
    sortArray.bubbleSort();
    sortArray.resetArray(toSortArray);
    sortArray.selectionSort();
    sortArray.resetArray(toSortArray);
    sortArray.insertionSort();
    sortArray.binarySearch();
    sortArray.resetArray(toSortArray);
    sortArray.shellSort();
    return 0;
}
