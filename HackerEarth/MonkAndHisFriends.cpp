#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test, i, n, m;
    long long int x;
    //vector<long long int> vec;
    unordered_map<long long int, long long int> mp;
    
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            cin>>x;
            mp[x]++;
        }
        for(i=0; i<m; i++)
        {
            cin>>x;
            if(mp.find(x)==mp.end())
            {
                mp[x]++;
                cout<<"NO"<<endl;
            }
            else
            {
                //mp[x]--;
                cout<<"YES"<<endl;
            }
        }
        
        mp.clear();
    }
    
    return 0;
}
