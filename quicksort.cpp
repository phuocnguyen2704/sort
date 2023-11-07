#include<iostream>
using namespace std;
template <class T>
class Sorting {
public:
    static T* Partition(T* start, T* end) ;
public:
    static void QuickSort(T* start, T* end) ;
};
template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    if (start ==nullptr || end==nullptr) return nullptr;
    if(start==end) return start;
    T * pivot =start;
    T * left=start+1;
    T * right=end-1;
    do 
    {
        while (*left<*pivot && left<right){left++;}
        while (*right>*pivot && right!=pivot)right--; 
        if (left<right) 
        // swap (left, right ) ;
        {
        T temp=* left;
        * left=* right;
        *right=temp;
        }
    }while (left<right);
    pivot=right;
    // swap (start,right);
    T temp=* start;
    *start=*right;
    *right=temp;
    return pivot;   
}
template <class T>
void Sorting<T>::QuickSort(T *start, T *end)
{
    if (start<end)
    {
        T * pivot=Partition(start,end);
        int index=0;
        for (T * temp=start ;temp<=end;temp++)
        {   
            if (temp==pivot) 
            {
                cout<<index<<" ";
                break;
            }
            index++;
        }
        QuickSort(start,pivot);
        QuickSort(pivot +1,end);
    }   
}

int main()
{
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array) cout << i << " ";
}
