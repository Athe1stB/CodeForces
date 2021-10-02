#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>g[n+1],indeg(n+1,0),outdeg(n+1,0),rg[n+1];
        for(ll i=1;i<=n;i++)
        {
            ll k;
            cin>>k;
            for(ll j=1;j<=k;j++)
            {
                ll x;
                cin>>x;
                indeg[x]++;
                outdeg[i]++;
                g[i].push_back(x);
                rg[x].push_back(i);
            }
        }
        ll cnt=0;
        queue<ll>q;
        for(ll i=1;i<=n;i++)
        {
            if(!indeg[i])
            {
                cnt++;
                q.push(i);
            }
        }
        while(q.size())
        {
            ll v=q.front();
            q.pop();
            for(auto u:g[v])
            {
                indeg[u]--;
                if(!indeg[u])
                {
                    cnt++;
                    q.push(u);
                }
            }
        }
        if(cnt!=n) cout<< -1 <<endl;
        else
        {
            ll ans=0;
            set<ll>st;
            for(ll i=1;i<=n;i++)
            {
                if(!outdeg[i])st.insert(i);
            }
            while(st.size())
            {
                ans++;
                int prev=0;
                while(1)
                {
                    auto it=st.upper_bound(prev);
                    if(it!=st.end())
                    {
                        prev=*it;
                        st.erase(prev);
                        for(auto u:rg[prev])
                        {
                            outdeg[u]--;
                            if(!outdeg[u])st.insert(u);
                        }
                    }
                    else
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}