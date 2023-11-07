#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
    T* temp = new T[right - left + 1];
    T* i = left;T* j = middle + 1; int k = 0;
    while (i <= middle && j <= right) {
        if (*i <= *j) {
            temp[k] = *i;
            i++;    
        } else {
            temp[k] = *j;
            j++;
        }
        k++;
    }
    while (i <= middle) {
        temp[k] = *i;
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = *j;
        j++;
        k++;
    }
    for (int i=0;i<k;i++)
    {
        left[i]=temp[i];
    }
    right =left+k-1;
    Sorting::printArray(left, right);
    delete[] temp;
    }
    static void mergeSort(T* start, T* end) {
       /*TODO*/
        if (start<end)
        {
            T * middle=start + (end-start)/2;
            mergeSort(start,middle);
            mergeSort(middle+1,end);
            merge(start,middle,end);
        }
    }
};
int main()
{
int arr[] = {0,2,4,3,1,4};
Sorting<int>::mergeSort(&arr[0], &arr[5]);
}