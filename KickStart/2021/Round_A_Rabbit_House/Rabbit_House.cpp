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

int A[1000][1000];
int B[1000][1000];

ll solver()
{
    int r, c;
    cin>>r>>c;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
        {
            cin>>A[i][j];
            B[i][j] = A[i][j];
        }
            
    
    ll sum = 0;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
        {
            if (i==0 && j==0)
                continue;
            else if (i==0)
            {
                if (A[i][j] < A[i][j-1])
                    A[i][j] += A[i][j-1]-1-A[i][j];
            }
            else if (j==0)
            {
                if (A[i][j] < A[i-1][j])
                    A[i][j] += A[i-1][j]-1-A[i][j];
                    
            }
            else
            {
                int t = max(A[i-1][j], A[i][j-1]);
                if (A[i][j] < t)
                    A[i][j] += t-1-A[i][j];
            }                
        }

    for (int i=r-1; i>=0; i--)
        for (int j=c-1; j>=0; j--)
        {
            if (i==r-1 && j==c-1)
                continue;
            else if (i==r-1)
            {
                if (A[i][j] < A[i][j+1])
                    A[i][j] += A[i][j+1]-1-A[i][j];
            }
            else if (j==c-1)
            {
                if (A[i][j] < A[i+1][j])
                    A[i][j] += A[i+1][j]-1-A[i][j];
                    
            }
            else
            {
                int t = max(A[i+1][j], A[i][j+1]);
                if (A[i][j] < t)
                    A[i][j] += t-1-A[i][j];
            }                
        }
    
    for (int i=r-1; i>=0; i--)
        for (int j=c-1; j>=0; j--)
            sum += A[i][j] - B[i][j];
    
    return sum;
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
