//#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include<cstdlib>
#include<cstdio>

#include <bits/stdc++.h>

using namespace std;

int solver(vector<int>&Time, vector<int>&Start, vector<int>&Decay)
{
    int n = Time.size();
    vector<vector<int>>p;
    for (int i=0; i<n; i++)
        p.push_back({Decay[i],Start[i],i});
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    
    vector<int>dp(n+1,0);
    int S = Time[0];    
    
    for (int i=0; i<n; i++)
    {
        auto dp_temp = dp;
        for (int j=1; j<=i+1; j++)
        {
            int cand1 = dp_temp[j];
            int idx = p[i][2];
            int cand2 = dp_temp[j-1] + max(Start[idx]-S*(j-1)*Decay[idx],0);
            dp[j] = max(cand1, cand2);
        }                
    }
    
    int ret = 0;
    for (int j=0; j<=n; j++)
        ret = max(ret, dp[j]);
    return ret;
}


int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    vector<int>results;

    for (int t=1; t<=T; t++)
    {
        int N;
        cin>>N;
        vector<int>Time;
        vector<int>Start;
        vector<int>Decay;

        for (int i=0; i<N; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            Time.push_back(a);
            Start.push_back(b);
            Decay.push_back(c);
        }

        results.push_back(solver(Time,Start,Decay));

    }

    for (int t=1; t<=T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cout<<results[t-1]<<endl;
    }

   //cout<<"All Done"<<endl;
}
