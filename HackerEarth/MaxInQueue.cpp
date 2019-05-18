#include <bits/stdc++.h>
using namespace std;

void max_heapify(long int A[], long int i, long int n)
{
    long int left = 2*i;
    long int right = 2*i + 1;
    long int largest = 0;
    if(left<=n && A[left] > A[i]) largest = left;
    else largest = i;
    if(right<=n && A[right] > A[largest]) largest = right;
    if(largest != i)
    {
        swap(A[i], A[largest]);
        max_heapify(A, largest, n);
    }
}

void build_maxheap(long int A[], long int n)
{
    for(long int i=n/2; i>=1; i--)
    {
        max_heapify(A, i, n);
    }
}

void increase_value(long int A[], long int i, long int val)
{
    A[i] = val;
    while(i>1 && A[i/2]<A[i])
    {
        swap(A[i/2], A[i]);
        i = i/2;
    }
}

void insert_value(long int A[], long int val)
{
    long int length = sizeof(A)/sizeof(A[0])+1;
    A[length] = -1;
    increase_value(A, length, val);
}

int max(long int A[])
{
    return A[1];
}

int main()
{
    long int n, q, i,j, type, value;
    cin>>n;
    long int *Arr = new long int[100001];
    
    for(i=1; i<n+1; i++)
    {
        cin>>Arr[i];
    }
    build_maxheap(Arr, n);
    cin>>q;
    
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>value;
            insert_value(Arr, value);
        }
        else
        {
            cout<<max(Arr)<<endl;
        }
    }
    
    return 0;
}
