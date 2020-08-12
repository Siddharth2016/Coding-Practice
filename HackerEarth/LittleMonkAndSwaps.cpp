#include <bits/stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &vec, int n, int index) 
{
    if(index >= n) return;
    
    inorder(a, vec, n, 2 * index + 1); 
    vec.push_back(a[index]); 
    inorder(a, vec, n, 2 * index + 2); 
} 

int minSwaps(vector<int> &vec) 
{ 
    vector<pair<int,int>> t(vec.size()); 
    int ans = 0; 
    for(int i = 0; i < vec.size(); i++) 
    {
        t[i].first = vec[i];
        t[i].second = i;
    }
    
    sort(t.begin(), t.end()); 
    
    for(int i = 0; i < t.size(); i++) 
    {
        if(i == t[i].second) 
            continue; 
        else
        { 
            swap(t[i].first, t[t[i].second].first); 
            swap(t[i].second, t[t[i].second].second); 
        } 

        if(i != t[i].second) --i;
        ans++; 
    }
    
    return ans; 
} 

int main()
{
    int n, i;
    cin>>n;
    int *A = new int[n];
    vector<int> v;
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    inorder(A, v, n, 0);
    
    cout<<minSwaps(v);
    return 0;
    
}
