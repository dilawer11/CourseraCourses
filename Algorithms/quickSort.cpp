#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;

void printArray(int * array, int n){
    for(int i = 0; i < n; i++){
        if(array[i] != i + 1){
            cout << "Out Of Place" << endl;
        }
    }
    cout << endl;
}
int selectPivot(int * array, int n){
    return 0;
}
int partition(int * array, int n){
    int pivotIndex = selectPivot(array, n);
    int pivotVal = array[pivotIndex];
    // if(n == 10000){
    //     cout << pivotVal << endl;
    // }
    int ptr = 0;
    for (int i = 0; i < n; i++){
        if(array[i] < pivotVal){
            int temp = array[ptr];
            array[ptr] = array[i];
            array[i] = temp;
            if(ptr == pivotIndex){
                pivotIndex = i;
            }
            ptr++;
        }
    }
    array[pivotIndex] = array[ptr];
    array[ptr] = pivotVal;
    // if(n == 10000){
    //     cout << array[pivotIndex] << endl;
    // }
    return ptr;
}
void quickSort(int * array, int n){
    if(n <= 1){
        return;
    }else{
        int pivotIndex = partition(array, n);
        quickSort(array, pivotIndex);
        quickSort(array + pivotIndex + 1, n - pivotIndex - 1);
        return;
    }
}
int main(){
    cout << "Quick Sort" << endl;
    int arraySize = 10000;
    int * array = new int[arraySize];
    fin.open("QuickSort.txt");

    for(int i = 0; i < arraySize; i++){
        fin >> array[i];
    }
    // printArray(array, 10);
    // cout << array[arraySize - 1] << endl;
    quickSort(array, arraySize);
    printArray(array, 10000);
    return 0;
}