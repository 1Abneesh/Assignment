#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    char id;
    int dead;
    int profit;
};

bool compare(Job a,Job b){
    return a.profit > b.profit;
}

void fun(vector<Job> a){
    sort(a.begin(),a.end(),compare);
    int max_dadline = -1;
    for(auto it:a){
        max_dadline = max(max_dadline,it.dead);
        // cout<<it.id<<"\n";
    }
    // int a[max_dadline];
    int count = 0;
    bool visited[max_dadline+1]={false};
    vector<char> slot(max_dadline+1);
    for(auto it:a){
        for(int i = it.dead;i>=1;i--){
            if(!visited[i]){
                visited[i] = true;
                slot[i] = it.id;
                count += it.profit;
                break;
            }
        }
    }
    cout<<"max profit is :- ";
    cout<<count;
    cout<<"\n";
    for(int i = 1;i<=max_dadline;i++){
        if(visited[i]){
            cout<<slot[i]<<" ";
        }
    }
    cout<<"\n";

}

int main(){
    vector<Job> arr = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 100, 15 } };
    
    // int a[] = {1,2,3,4,5};
    fun(arr);


    return 0;
}