#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()


int b[1005],s[1005];
int main(){
        int n,m;cin>>n>>m;
        for(int i=0;i<n;i++) cin>>b[i];
        
        for(int i=0;i<m;i++) cin>>s[i];
        
        sort(b,b+n);
        sort(s,s+m);

        int i=0,j=0,ans=0;
        while(i<n&&j<m){
                if(b[i]==s[j]||b[i]+1==s[j]){
                        ans++;i++;j++;
                }else if(b[i]<s[j]){
                        i++;
                }else if(b[i]>s[j]){
                        j++;
                }
             //  cout<<ans<<" : "<<i<<' '<<j<<endl;
        }
        cout<<ans;
}/*
5 5 
5
6 
6 
3 
7
5 
6 
7 
8 
8
*/
