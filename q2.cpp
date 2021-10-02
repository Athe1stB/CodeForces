#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int w[n];//array of water
    for(int i=0;i<n;i++)cin>>w[i];
    int x;
    cin>>x;
    vector<vector<int>> q;
    for(int i=0;i<x;i++){
        int m,n,o;
        for(int i=0;i<3;i++){
            cin>>m>>n>>o;
            q.push_back({m,n,o});
        }
    }
    for(int i=1;i<n;i++)w[i]=w[i-1]+w[i];
    for(int i=0;i<q.size();i++){//q.size() size of query
            q[i][0]--;
            q[i][1]--;
            if(q[i][1]+1<n){
                w[q[i][1]+1]+=q[i][2];
                w[q[i][0]]-=q[i][2];
            }
            else w[q[i][0]]-=q[i][2];
    }
    for(int i=1;i<n;i++)w[i]=w[i-1]+w[i];
    for(int i=0;i<n;i++)cout<<w[i]<<" ";
}
