#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

struct Node {
    int cover,len;
};

struct SegTree{
    vector<Node> st; vector<int> ys; int n;

    SegTree(int m, vector<int>& _ys){
        st.assign(4*m,{0,0}); 
        ys=_ys; n=m-1;
    }

    void upd(int p,int l, int r,int ql, int qr,int v){
        if(qr <= l || r <= ql) return;

        if(ql <= l && r <= qr) st[p].cover+=v;
        else{
            int m=(l+r)/2; 
            upd(2*p,l,m,ql,qr,v);
            upd(2*p+1,m,r,ql,qr,v);
        }

        if(st[p].cover>0) st[p].len=ys[r]-ys[l];
        else st[p].len=(l+1==r?0:st[2*p].len+st[2*p+1].len);
    }

    int get(){
        return st[1].len;
    }
};

struct Event{
    int x,y1,y2,t; 
    
    bool operator<(const Event&o)const{
        return x<o.x;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line; getline(cin, line);

    vector<array<int,4>> rects;
    int x0 , y0, x1, y1; char c;
    stringstream ss(line);

    while(ss >> c){
        if(isdigit(c)){ ss.putback(c); ss >> x0 >> c >> y0 >> c >> x1 >> c >> y1;
            rects.push_back({x0, y0, x1, y1});
        }
    }

    vector<Event> ev; vector<int> ys;
    for(auto &r: rects){
        ev.push_back({r[0],r[1],r[3],1});
        ev.push_back({r[2],r[1],r[3],-1});
        ys.push_back(r[1]); ys.push_back(r[3]);
    }

    sort(all(ev)); sort(all(ys));
    ys.erase(unique(all(ys)),ys.end());
    SegTree st(ys.size(),ys);

    int ans=0, prev = ev[0].x;
    for(auto&e:ev){
        ans += (e.x-prev) * st.get();
        int y1 = lower_bound(all(ys), e.y1) - ys.begin();
        int y2 = lower_bound(all(ys), e.y2) - ys.begin();
        st.upd(1,0, st.n, y1, y2, e.t);
        prev = e.x;
    }

    cout << ans;
}
