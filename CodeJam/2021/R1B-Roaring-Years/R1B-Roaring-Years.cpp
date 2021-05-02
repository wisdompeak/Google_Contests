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

string pick(string origin, string cur, string cand, int n)
{
    if (cur=="") return cand;
    if (cand.size() == origin.size() && cand <= origin) return cur;
    
    if (cand.size() == cur.size())
    {
        if (cand >= cur)
            return cur;
        else
            return cand;
    }
    else if (cand.size() > cur.size())
        return cur;
    else
        return cand;
}

bool SmallerOrEqual(string& s, string& t)
{
    if (s.size()>t.size()) return false;
    else if (s.size()<t.size()) return true;
    else return s<=t;
}

string create(ll base, int times)
{
    string s = to_string(base);
    for (int i=1; i<times; i++)
    {
        base++;
        s+=to_string(base);
    }
    return s;
}

string solver()
{
    string Y;
    cin>>Y;
    
    string ret = "";
    int n = Y.size();   
    
    if (n==1) return "12";    
    
    for (int times = 2; times <= n+1; times++)
    {
        ll low = 1, high = pow(10, (n-1)/times+1) - 1;
                
        while (low < high)
        {            
            
            ll mid = low+(high-low)/2;
                  
            ll base = mid;
            string s = create(base, times);            
            
            if (SmallerOrEqual(s, Y))
                low = mid+1;
            else
                high = mid;          
        }
        
        string s = create(low, times);
        if (!SmallerOrEqual(s, Y))
        {
            ret = pick(Y, ret, s, n);
        }
            
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    vector<string>rets;

    for (int t=1; t<=T; t++)
    {
        rets.push_back(solver());
    }
    
    for (int t=1; t<=T; t++)
    {
        cout<<"Case #"<<t<<": "<<rets[t-1]<<endl;        
    }
}
