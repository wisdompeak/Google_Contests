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
typedef long long ll;

ll M = 1e9;

string solve(int X, int Y)
{
    // cout<<X<<" "<<Y<<endl;
    
    if (X==0 && Y==0)
        return "";
    
    if (X==0 && Y==1) return "N";
    if (X==0 && Y==-1) return "S";
    if (X==1 && Y==0) return "E";
    if (X==-1 && Y==0) return "W";
    
    if (abs(X)%2==0 && abs(Y)%2==0 || abs(X)%2==1 && abs(Y)%2==1)
        return "IMPOSSIBLE";
    
    string a;
    if (abs(X)%2==1)
    {
        a = solve((X-1)/2, Y/2);
        if (a!="IMPOSSIBLE") return "E"+a;
        
        a = solve((X+1)/2, Y/2);
        if (a!="IMPOSSIBLE") return "W"+a;
    }
    else
    {   
        a = solve(X/2, (Y-1)/2);
        if (a!="IMPOSSIBLE") return "N"+a;
        
        a = solve(X/2, (Y+1)/2);
        if (a!="IMPOSSIBLE") return "S"+a;     
    }
    
    return "IMPOSSIBLE";
}


int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    vector<string>results;

    for (int t=1; t<=T; t++)
    {
        int X, Y;
        cin>>X>>Y;
        results.push_back(solve(X,Y));
    }

    for (int t=1; t<=T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cout<<results[t-1]<<endl;
    }

   //cout<<"All Done"<<endl;

}
