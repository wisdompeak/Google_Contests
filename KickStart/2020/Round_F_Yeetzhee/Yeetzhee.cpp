#include <bits/stdc++.h>

using namespace std;
map<vector<int>,double>Map;
int N,M,K;

double dfs(vector<int>&cur, vector<int>&target)
{
    if(cur==target)
        return 0;
    if (Map.find(cur)!=Map.end())
        return Map[cur];
        
    double other=0;
    int selfTimes=0;
    for (int i=0; i<M; i++)
    {
        if (i<K && cur[i]<target[i])
        {
            int j = i;
            while (j+1<M && cur[j+1]==cur[j])
                j++;
            cur[i]++;
            other += (dfs(cur,target)+1)*(j-i+1)*1.0/M;
            cur[i]--;
            i = j;
        }     
        else
        {
            selfTimes+=1;
        }
    }
    // ret = other + (ret+1)*selfTimes*1.0/M
    double ret = (other + selfTimes * 1.0/M) / (1.0 - selfTimes * 1.0/M);
    Map[cur] = ret;
    // for (auto x:cur) cout<<x<<",";
    // cout<<":"<<selfTimes<<" "<<ret<<endl;
    return ret;
}


int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t)
    {
        cin>>N>>M>>K;
        Map.clear();
        auto A=vector<int>(M);
        auto B=vector<int>(M);
        for(int i=0;i<K;++i){
            cin>>A[i+M-K];
        }
        reverse(A.begin(),A.end());
        double res=dfs(B,A);
        printf("Case #%d: %.7f\n",t,res);
    }
    return 0;
}
