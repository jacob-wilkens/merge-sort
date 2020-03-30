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

void merging(int* ar, int left, int right, int mid){
    int temp[(right - left) + 1];//temp array
    int tempIndex = 0; //temp index
    int leftIndex = left;//left index
    int rightIndex = mid + 1;//right index

    while(leftIndex <= mid && rightIndex <= right){//loop that finds lowest numbers in left and right based on indexes and adds to temp
        
        if(ar[leftIndex] < ar[rightIndex]){//compares left to right
            temp[tempIndex] = ar[leftIndex];
            tempIndex++, leftIndex++;
        } else {//adds right because left wasnt added
            temp[tempIndex] = ar[rightIndex];
            tempIndex++, rightIndex++;
        }
    }

    while (leftIndex <= mid){//wherever left ended, this resumes and adds to temp for left
        temp[tempIndex] = ar[leftIndex];
        tempIndex++, leftIndex++;
        }
 
    while(rightIndex <= right){//wherever right ended, this resumes and adds to temp for right
        temp[tempIndex] = ar[rightIndex];
        tempIndex++, rightIndex++;
    }

    tempIndex = 0; //resets temp index for adding at start of temp
    cout << "left is " << left << " right is " << right << "\n";

	for (int i = left; i <= right; i++){//adds temp back to ar
        ar[i] = temp[tempIndex];
        tempIndex++;
    }


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
        merging(ar, begin1, end2, end1);


  
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