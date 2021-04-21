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

bool isPrime(ll x)
{
    if (x==2) return true;
    if (x%2==0) return false;
    for (int i=3; i<=sqrt(x); i+=2)
        if (x%i==0) return false;
    return true;
}

ll solver()
{
    ll Z;
    cin>>Z;
    
    ll ret = LLONG_MAX;
    ll z1 = 0, z2 = 0;
    for (int z = sqrt(Z); z>=2; z--)
    {
        if (isPrime(z))
        {
            if (z1 ==0)
                z1 = z;
            else
                z2 = z;
        }
        if (z2!=0)
            break;            
    }
    if (z1*z2!=0)
        ret = z1*z2;
    
    ll z3 = sqrt(Z)+1;
    while (!isPrime(z3) && z1*z3 <= Z)        
        z3++;
    
    
    if (z1*z3 <= Z)
    {
        if (ret == LLONG_MAX)
            ret = z1*z3;
        else
            ret = max(ret, z1*z3);
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
