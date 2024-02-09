#include <bits/stdc++.h>
using namespace std;

class seg_tree{
   public:
    vector<long long> seg;
    long long n;
    
    seg_tree(long long size){
        n = size;
        seg.resize(4*n+1);
    }
     
    void build(vector<long long> &arr, long long v, long long tl, long long tr){
        if(tl==tr){
            seg[v] = arr[tl];
        }
        else{
            long long tm = (tl+tr)/2;
            build(arr, 2*v+1, tl, tm);
            build(arr, 2*v+2, tm+1, tr);
            seg[v] = seg[2*v+1] + seg[2*v+2];
        }
    } 
    
    long long sum(long long v, long long tl, long long tr, long long l, long long r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }
    long long tm = (tl + tr) / 2;
    return sum(v*2+1, tl, tm, l, min(r, tm))
           + sum(v*2+2, tm+1, tr, max(l, tm+1), r);
    }
    
    void update(long long v, long long tl, long long tr, long long pos, long long new_val) {
    if (tl == tr) {
        seg[v] = new_val;
    } else {
        long long tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, pos, new_val);
        else
            update(v*2+2, tm+1, tr, pos, new_val);
        seg[v] = seg[v*2+1] + seg[v*2+2];
    }
}
     
};


int main()
{
    seg_tree mySegTree(10);
    vector<long long> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    mySegTree.build(arr, 0, 0, arr.size()-1);
    mySegTree.update(0, 0, 9, 5, 69);
    cout<<mySegTree.sum(0, 0, 9, 2, 5);


    return 0;
}