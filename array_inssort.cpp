#include<iostream>
using namespace std;
bool compare(int a,int b)
{
    return a<b;
}
void swap(int arr[],int i , int j)
{
    int a=arr[i];
    arr[i]=arr[j];
    arr[j]=a;
}
void inssort(int arr[], int n,int incr=1)
{
    for (int i=1;i<n;i+=incr)
    {
        for (int j=i;j>=incr && compare(arr[j],arr[j-incr]);j-=incr)
        {
            swap(arr,j,j-incr);
        }
    }
}
void bubsort(int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=n-1;j>i;j--)
        {
            if (compare(arr[j],arr[j-1]))
            {
                swap (arr, j,j-1);
            }
        }
    }
}
void selsort (int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        int low_index=i;
        for (int j=n-1;j>i;j--)
        {
            if (compare(arr[j],arr[low_index]))
            low_index=j;
        }
        swap(arr,i,low_index);
    }
}
void shellsort(int arr[], int n) 
{ // Shellsort
    for (int i=n/2; i>2; i/=2) // For each increment
    {
        for (int j=0; j<i; j++) // Sort each sublist
        {
            inssort(&arr[j], n-j, i);
        }
    }
    inssort(arr,n,1);
}
void mergesort()
{

}
void quicksort(int arr[], int left, int right )
{
    if (right -left <2) return;
    int pivot=(left+right)/2;
    while (left<right)
    {
        while (left<right  && !compare(arr[pivot],arr[left] )) left++;
        while (left<right  && compare(arr[pivot] ,arr[right])) right++;
        if (left < right )
        {
            if(left < right)
            {
                if (pivot==left) pivot=right;
                else if (pivot ==right) pivot =left;
                swap (arr,left,right);
            }
        }
    }
    if (pivot != left)
    {
        swap(arr,left,pivot);
    }
    quicksort(arr,left,pivot-1);
    quicksort(&arr[pivot +1],right -pivot);
}

int main()
{
    int arr[8]={56,1,47,98,30,31,15,60};
    shellsort(arr,8);
    for (int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
}