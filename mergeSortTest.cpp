#include <iostream>
using namespace std;
void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

//which portion of the array am I mergeSorting....
void mergeSort(int* ar, int begin, int end)
{
    cout << "Merge Sorting: ";
    printArray(ar, begin, end);
    //if it is not a 1 list (not trivially sorted)
    if(begin != end)
    {
        //divide in half and call mergeSort on each half
        int begin1 = begin;
        int end1 = (end + begin) / 2;
        int begin2 = end1 + 1;
        int end2 = end;
        cout << "begin 1 is " << begin1 << " end 1 is " << end1 << " begin 2 is "<< begin2 << " end 2 is " << end2 << "\n";
        //call mergesort on the first half
        mergeSort(ar, begin1, end1);
        //call mergesort on the second half
        //this will not fire until the entire 
        //first half is dealt with
        mergeSort(ar, begin2, end2);
        //now perform the merge step
        cout << "Now we have to merge!!!!\n Start to cry Clancy!!!\n";
        int leftSize = (end1 - begin1) + 1;
        int rightSize = (end2 - begin2) + 1;
        int tempAr[leftSize + rightSize];
        int left[leftSize];
        int right[rightSize];

        cout << "left size is " << leftSize << "\n";
        cout << "right size is " << rightSize << "\n";
        cout << "temp size is " << leftSize + rightSize << "\n";

        cout << "begin 1 is " << begin1 << " end 1 is " << end1 << " begin 2 is "<< begin2 << " end 2 is " << end2 << "\n";
        int index = 0;
        
        for(int i = begin1; i <= end1; i++){
            left[index] = ar[i];
            cout << "left is  " << left[index] << "\n";
        }

        index = 0;

        for(int i = begin2; i <= end2; i++){
            right[index] = ar[i];
            cout << "right is  " << right[index] << "\n";
        }

        index = 0;
        
        for(int i = 0; i < leftSize; i++){
            cout << "left number being added is " << left[i] << "\n";
            tempAr[i] = left[i];
            cout << "temp ar index first " << i << " is " << tempAr[i] << "\n";
        }

        for(int i = 0; i < rightSize; i++){
            
            for(int j = 0; j < leftSize; j++){
                
                if(right[i] < tempAr[j]) {
                    int temp = tempAr[j];
                    tempAr[j] = right[i];
                    tempAr[j+1] = temp;
                    break;
                } else {
                    continue;
                }
            }
        }

        for(int i = 0; i < leftSize + rightSize; i++){
            cout << "temp ar index second " << i << " is " << tempAr[i] << "\n";
        }


        cout << "printing array \n";
        printArray(ar, 0,4);
  
    } else
    {
        cout << "One List! Do nothing\n";
    }
    
}
int main()
{
    int ar[5] = {7,2,1,4,3};
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
    return 0;
}