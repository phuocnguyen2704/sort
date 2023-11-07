#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(),rooms.end());
    sort(people.begin(),people.end());
    int count=0;
    for(int i=0,j=0;i<rooms.size() && j<people.size();)
    {
        if (rooms[i] >= people[j] - k && rooms[i] <= people[j] + k) {
            count++;
            i++;
            j++;
        } else if (rooms[i] < people[j] - k) {
            i++;
        } else {
            j++;
        }
    }
}
int main()
{

}