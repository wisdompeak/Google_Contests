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

bool OK(int R, int C, vector<string>&grid, vector<vector<int>>&visited, int K)
{
    vector<int>s(4, INT_MIN/2);
        
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
        {
            if (grid[i][j]=='1')
                continue;
            if (visited[i][j]<=K)
                continue;
            s[0] = max(s[0],i+j);
            s[1] = max(s[1],i-j);
            s[2] = max(s[2],-i+j);
            s[3] = max(s[3],-i-j);
        }
    
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
        {
            if (grid[i][j]=='1')
                continue;
            int d = INT_MIN/2;
            d = max(d, s[0]-(i+j));
            d = max(d, s[1]-(i-j));
            d = max(d, s[2]-(-i+j));
            d = max(d, s[3]-(-i-j));
            if (d<=K) return true;
        }
    return false;
}


long solver(int R, int C, vector<string>&grid)
{
    auto visited = vector<vector<int>>(R,vector<int>(C,-1));
    queue<pair<int,int>>q;
    auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
    
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
        {
            if (grid[i][j]=='1')
            {
                visited[i][j] = 0;
                q.push({i,j});
            }
        }
    if (q.size()==R*C) return 0;
    
    int step = 0;
    while (q.size()!=0)
    {
        int len = q.size();
        step++;
        while (len--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=R||j<0||j>=C) continue;
                if (visited[i][j]!=-1) continue;
                visited[i][j] = step;
                q.push({i,j});
            }
        }
    }
    
    int left = 0;
    int right = R+C;
    while (left<right)
    {
        int K = left+(right-left)/2;
        if (OK(R,C,grid,visited,K))
            right = K;
        else
            left = K+1;
    }
    
    return left;
}


int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    vector<long>results;

    for (int t=1; t<=T; t++)
    {
        int R,C;
        cin>>R;
        cin>>C;
        vector<string>grid;
        for (int i=0;i<R; i++)
        {
            string s;
            cin>>s;
            grid.push_back(s);
        }
        results.push_back(solver(R,C,grid));
    }

    for (int t=1; t<=T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cout<<results[t-1]<<endl;
    }
}
