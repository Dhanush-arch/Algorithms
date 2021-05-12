#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
const long double PI = acos(-1);
const ll mod = 1e9 + 7; // 10^9 + 7

//predefined functions
int power(ll x, ll y, ll m);  //  (x^y)%m

ll node_next_level = 0;
ll node_left_curr_level = 0;
ll move_cnt = 0;
ll r, c;
queue<int> rq, cq;

void exploreNeighbor(ll cur_r, ll cur_c, vector<vector<char>> &mat, vector<vector<bool>> &visited){
	vi rd = {1, -1, 0, 0};
	vi cd = {0, 0, -1, 1};
	for(ll i=0;i<4;i++){
		ll rc = cur_r+rd[i];
		ll cc = cur_c+cd[i];

		if(rc<0 or cc<0) continue;
		if(rc>=r or cc>=c) continue;
		if(mat[rc][cc] == '#') continue;
		if(visited[rc][cc]) continue;

        rq.push(rc);
        cq.push(cc);
		visited[rc][cc]=true;
		node_next_level++;
	}
}

ll solve()
{
    cin>>r>>c;
    vector<vector<char>> mat(r, vector<char> (c));
    vector<vector<bool>> visited(r, vector<bool> (c, false));
    for(ll i=0;i<r;i++){
	for(ll j=0;j<c;j++){
		cin>>mat[i][j];
	}
    }
    ll a, b;
    bool reached_end=false;
    cin>>a>>b;

    rq.push(a);
    cq.push(b);
    visited[a][b] = true;
    node_left_curr_level = 1;
    node_next_level=0;
    while(!rq.empty()){
	ll cur_r = rq.front();
	ll cur_c = cq.front();
	rq.pop();cq.pop();
	if(mat[cur_r][cur_c] == 'E'){
		reached_end = true;
		break;
	}
	exploreNeighbor(cur_r, cur_c, mat, visited);
	node_left_curr_level--;
	if(node_left_curr_level == 0){
		node_left_curr_level = node_next_level;
		node_next_level = 0;
		move_cnt++;
	}
    }
    if(reached_end){
	return move_cnt;
    }
    return (ll)-1;
}

int power(ll x, ll y, ll m){ //  (x^y)%m
   ll res = 1;
   x = x%m;
   while(y>0){
      if(y&1)
         res = (res*x)%m;
      y = y/2;
      x = (x*x)%m;
   }
   return res;
}

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--)
   {
      ll re = solve();
      if(re != -1)
	      cout<<re<<endl; // no of moves(shortest) to reach 'E' from 'S'
      else
	      cout<<"NO PATH EXISTS"<<endl;
   }

   // solve();

   #ifndef ONLINE_JUDGE
   cerr<<"Executed In: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   #endif
      return 0;
}
