#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
string convert(int number)
{
    std::stringstream ss;
    ss << number;
    std::string str = ss.str();
    const char* char_type = str.c_str();
    return char_type;
}
string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    string output="";
    if (n==1) return output;
    sort(arr,arr+n);
    int min=arr[1]-arr[0];
    for(int i=1;i<n-1;i++)
    {
        if (arr[i+1]-arr[i]<min)
        {
            min=arr[i+1]-arr[i];
        }
    }
    for (int i=0;i<n;i++)
    {
        if (arr[i+1]-arr[i]==min)
        {
            if (output!="")
            {
                output=output+", ";
            }
            string s1=convert(arr[i]);
            string s2=convert(arr[i+1]);
            output=output+'('+s1+", "+s2+")";
        }
    }
    return output;
}
int main()
{
int arr[] = {10, -1, -150, 200};
cout << minDiffPairs(arr, 4);
}
