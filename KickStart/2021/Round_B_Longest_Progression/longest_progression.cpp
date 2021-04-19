#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include<cstdlib>
#include<cstdio>

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solver()
{
    int N;
    cin>>N;
    vector<ll>A(N);
    for (int i=0; i<N; i++)
        cin>>A[i];
    
    vector<ll>countLeft(N);  
    countLeft[0] = 1, countLeft[1] = 2;
    for (int i=2; i<N; i++)
    {        
        if (A[i]-A[i-1]!=A[i-1]-A[i-2])
            countLeft[i] = 2;
        else
            countLeft[i] = countLeft[i-1]+1;
    }
            
    vector<ll>countRight(N);    
    countRight[N-1] = 1, countRight[N-2] = 2;
    for (int i=N-3; i>=0; i--)
    {
        if (A[i+1]-A[i]!=A[i+2]-A[i+1])
            countRight[i] = 2;
        else
            countRight[i] = countRight[i+1]+1;
    }
            
    ll ret = 0;    
    for (int i=0; i<N; i++)
    {
        if (i-1>=0)
            ret = max(ret, countLeft[i-1]+1);
        if (i+1<N)
            ret = max(ret, countRight[i+1]+1);
        
        if (i-2>=0 && i+1<N  && A[i+1]-A[i-1] == 2*(A[i-1]-A[i-2]))
            ret = max(ret, countLeft[i-1]+2);
        
        if (i-1>=0 && i+2<N && A[i+1]-A[i-1] == 2*(A[i+2]-A[i+1]))
            ret = max(ret, countRight[i+1]+2);
        
        if (i-2>=0 && i+2<N && A[i-1]-A[i-2] == A[i+2]-A[i+1] && A[i+1]-A[i-1] == 2*(A[i-1]-A[i-2]))
            ret = max(ret, countLeft[i-1]+1+countRight[i+1]);        
    }
    
    return ret;    
}


int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    vector<ll>rets;

    for (int t=1; t<=T; t++)
    {
        rets.push_back(solver());
    }
    
    for (int t=1; t<=T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cout<<rets[t-1]<<endl;
    }
}
