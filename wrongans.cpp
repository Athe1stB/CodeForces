#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll long long
#define lld long double
#define ull unsigned long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(ll i=a;i<n;i+=x)
#define forD(i,a,n,x) for(ll i=n-1;i>=a;i-=x)
#define ranit(it,n) for(auto &it:n)
#define pb push_back
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define mod 1000000007
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vll , greater<ll>>
#define inf LLONG_MAX-1
#define init(a,x) memset(a,x,sizeof(a))
#define fastio() ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL)
#define nline "\n"

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef Athe1stB
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll tno = 1;
// const ll x[4] = {0, 1, 0, -1};
// const ll y[4] = {-1, 0, 1, 0};
// const ll x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
// const ll y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void solve()
{
    cerr<<"\nCase #"<<tno<<":"<<"\n";

    ll n,k;
    cin>>n>>k;

    vll v(n);
    ranit(it,v)cin>>it;

    vector<pll> range(n/2);
    map<ll,ll> mp;

    forA(i,0,n/2,1)
    {
        range[i].F = min(v[i],v[n-1-i])+1;
        range[i].S = max(v[i],v[n-1-i])+k;
        mp[(v[i]+v[n-1-i])]++;
    }

    ll l=0, r=k+k+k;

    ranit(it,range)
        l = max(l,it.F),
        r = min(r,it.S);

    ll ans = n/2;

    ranit(it,mp)
    {
        if(it.F>=l && it.F<=r)
        {
            ll tempans = (n/2)-it.S;
            debug(tempans);
            ans = min(ans,tempans);
        }
    }

    cout<<ans<<nline;

    cerr<<"\n";
}

int main()
{
    fastio();
    auto start1 = high_resolution_clock::now();
    ll t=1;
    cin>>t;
    while(t--)
        solve(),tno++;
    auto stop1 = high_resolution_clock::now();
    duration<double, milli> ms = stop1-start1;
        
    #ifdef Athe1stB
        cerr<<"Finished in "<< ms.count()<< " ms\n";
    #endif
        
    return 0;
}
