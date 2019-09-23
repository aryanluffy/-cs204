#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector<vector<int>>
#define v4096 vector<vector<lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli, lli>
#define m32 map<int, int>
#define m64it map<lli, lli>::iterator
#define m32it map<int, int>::iterator
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue
#define min_p_q priority_queue<int, vt<int>, greater<int>>
using namespace std;
using namespace __gnu_pbds;
ld solve(vt<ld> dist, lli k)
{
  vt<ld> newdist;
  f(i, 0, dist.size() / 5)
  {
    sort(dist.begin() + i * 5, dist.begin() + i * 5 + 5);
    newdist.pb(dist[5 * i + 2]);
  }
  vt<ld> temp;
  f(i, 5 * (dist.size() / 5), dist.size())
  {
    temp.pb(dist[i]);
  }
  sort(temp.begin(), temp.end());
  if(temp.size()>0)
  newdist.pb(temp[temp.size() / 2]);
  
  ld median_of_medians ;
  if(newdist.size()!=1)
  median_of_medians= solve(newdist, newdist.size() / 2);
  else median_of_medians=newdist[0];
  int pos = -1;
  f(i, 0, dist.size()) if (median_of_medians == dist[i]) pos = i;
  swap(dist[pos], dist.back());
  int i = -1;
  int low = 0, high = (int)dist.size() - 1;
  for (int j = low; j <= high - 1; j++)
  {
    if (dist[j] < dist.back())
    {
      i++;
      swap(dist[i], dist[j]);
    }
  }
  swap(dist[i + 1], dist[high]);
  //cout<<i+1<<"\n";
  //cout<<k<<"\n";
  if (i + 1 == k)
    return dist[i + 1];
  else if (i + 1 > k)
  {
    vt<ld> DIST;
    f(j, 0, i + 1) DIST.pb(dist[j]);
    return solve(DIST, k);
  }
  else
  {
    vt<ld> DIST;
    f(j, i + 2, k+1) DIST.pb(dist[j]);
    return solve(DIST, k - i - 2);
  }
  return 0;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int k;
    cin >> k;
    vt<pair<ld, ld>> pnt(k);
    f(i, 0, k) cin >> pnt[i].first >> pnt[i].second;
    vt<ld> dist(k);
    f(i, 0, k) dist[i] = (pnt[i].first * pnt[i].first + pnt[i].second * pnt[i].second);
    cout << sqrt(solve(dist, (k - 1) / 2)) << "\n";
  }
  return 0;
}
