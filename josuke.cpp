#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(string s,char &d,int &z)
{
    int n=s.length();
    for(int i=0;i<n;i++)
        if(s[i]==d)
        {
            int x=(s[i]-'0'+1)*pow(10,n-1-i);
            string w=s.substr(i);
            int y=stoi(w),l=x-y;
            z+=l;
            return l+func(to_string(z),d,z);
        }
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        string s=to_string(n);
        char c=d+'0';
        // reverse(s.begin(),s.end());
        cout<<func(s,c,n)<<endl;
    }
}
