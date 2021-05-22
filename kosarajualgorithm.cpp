#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define pb push_back
#define test1 cin>>x; while(x--)
#define inputarr cin>>n; int arr[n]; for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define N   1000000
#define read(type) readInt<type>()
#define ps(x,y)         fixed<<setprecision(y)<<x
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define rz resize   
#define sz(a) (int)(a.size())

//  void EulerTotient(int n) {
//     vector<int> phi(n + 1);
//     phi[0] = 0;
//     phi[1] = 1;
//     for (int i = 2; i <= n; i++)
//         phi[i] = i;

//     for (int i = 2; i <= n; i++) {
//         if (phi[i] == i) {
//             for (int j = i; j <= n; j += i)
//                 phi[j] -= phi[j] / i;
//         }
//     }
//     cout<<phi[n]<<endl;
// }

 vector<int>adj[1001];
 vector<int>adjrev[1001];
vector<int>order;
int vis[1001];
int comp[1001];

void dfs(int curr){
  vis[curr]=1;

  for(auto it:adj[curr]){
    if(!vis[it])
    dfs(it);
  }
  order.push_back(curr);
}

void dfsreverse(int curr,int col){
  comp[curr]=col;
  vis[curr]=1;

  for(auto it:adjrev[curr]){
    if(!vis[it])
    dfsreverse(it,col);
  }
  
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adjrev[y].push_back(x);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i])
    dfs(i);
  }

int col=1;
memset(vis,0,sizeof(vis));
  for(int i=n;i>=1;i--){
    
    if(!vis[order[i]])
    dfsreverse(order[i],col);
    col++;
  }

  for(int i=1;i<=n;i++){
    cout<<i<<" "<<comp[i]<<" "<<endl;
  }
}