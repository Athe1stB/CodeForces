#include<bits/stdc++.h>
using namespace std ;
#define lln long long int 
 
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=(s[n-1]-'0');
    for(int i=0;i<n-1;i++){
        if(s[i]!='0'){
        count+=(s[i]-'0')+1;
        }
    }
    cout<<count<<endl;
    return;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
