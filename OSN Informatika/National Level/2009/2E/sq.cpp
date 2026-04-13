#include<bits/stdc++.h>
using namespace std;

int main(){ 
    deque<int>d;
    int n; cin >> n;
    
    while(n--){
        string s; int x;
        cin >> s;
        if(s == "push_back"){
            cin >> x;
            d.push_back(x);
        }else if(s == "push_front"){
            cin >> x;
            d.push_front(x);
        }else if(s == "pop_back"){
            d.pop_back();
        }else if(s == "pop_front"){
            d.pop_front();
        }
    }
    
    while(!d.empty()){
        cout << d.front() << endl;
        d.pop_front();
    }
    
   
    
}