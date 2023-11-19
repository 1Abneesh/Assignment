#include<bits/stdc++.h>
using namespace std;

struct Item{
    public:
    int w;
    int v;
};

bool compare(Item a,Item b){
    double r1 =(double) a.v/a.w;
    double r2 = (double) b.v/b.w;
    return r1>r2;
}

void  knapsack(vector<Item> a,int weight){
    sort(a.begin(),a.end(),compare);

    int profit = 0;
    for(auto it: a){
        if(it.w<=weight){
            profit += it.v;
            weight -= it.w;
        }
        else{
            profit += (it.v/it.w)*weight;
            weight = 0;
            break;
        }
    }
    cout<<"maximum profit is : - " << profit;

}

int main(){
    vector<Item> a = {
        {20, 100},
        {10, 60},
        {30, 120},
        {15, 50},
        {25, 80}
    };
    knapsack(a,50);

    return 0;
}