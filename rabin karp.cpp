#include<bits/stdc++.h>
using namespace std;

bool  fun(string original,string pat){
    int hash = 0;
    map<char,int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    mp['d'] = 4;
    mp['e'] = 5;
    mp['f'] = 6;
    mp['g'] = 7;
    mp['h'] = 8;
    mp['i'] = 9;
    for (auto it:pat){
        hash += mp[it];
    }
    int n = original.size();
    int i=0;
    int j=0;
    int score = 0;
    while (j<n)
    {
        score += mp[original[j]];
        if(j-i+1 == pat.size()){
            if(score == hash){
                    string dumm = original.substr(i,pat.size());
                    if(dumm == pat){
                        return true;
                    }
            }
            score -= mp[original[i]];
            i++;
        }
        j++;
    }
return false;
}




int main(){
    string original = "GEEKS FOR GEEKS";
    string pat = "GEEKS";
    if(fun(original,pat)){
        cout<<"pattern is present\n";
    }
    else{
        cout<<"The pattern is not present\n";
    }

    return 0;
}