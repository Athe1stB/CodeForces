    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        ll t = 1;
        cin>>t;
     
        while (t--)
        {
            ll n,m,d;
            cin>>n>>m>>d;
            vector<string > vec(n);
            for(ll i=0;i<n;i++)
            {
                cin>>vec[i];
            }
            vector<vector<long long>>gridl(n,vector<long long>(m,0));
            vector<vector<long long>>gridr(n,vector<long long>(m,0));
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    if(vec[i][j]=='*')
                    {
                        if(i!=0&&j!=0)
                        {
                            gridl[i][j]=1+gridl[i-1][j-1];
                        }
                        else{
                            gridl[i][j]=1;
                        }
                        if(i!=0&&j!=m-1)
                        {
                            gridr[i][j]=1+gridr[i-1][j+1];
                        }
                        else{
                            gridr[i][j]=1;
                        }
                    }
                    else{
                        gridl[i][j]=0;
                        gridr[i][j]=0;
                    }
                }
            }
             vector<vector<long long>>grid(n, vector<long long>(m,0));
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    if(vec[i][j]=='*')
                    {
                        grid[i][j]=min(gridl[i][j],gridr[i][j]);
                    }
                }
            }
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    if(grid[i][j]<=d)
                    {
                        grid[i][j]=0;
                    }
                }
            }
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    ll temp=grid[i][j];
                    for(ll k=0;k<temp;k++)
                    {
                        grid[i-k][j+k]=1;
                        grid[i-k][j-k]=1;
                    }
                }
            }
            ll can=1;
            for(ll i=0;i<n;i++)
            {
                
                for(ll j=0;j<m;j++)
                {
                    if((grid[i][j]==1&&vec[i][j]=='*')||(grid[i][j]==0&&vec[i][j]=='.'))
                    {
                        ;
                    }
                    else{
                        can=0;
                    }
                }
            }
            if(can)
            {
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
            
        }
        return 0;
    }
