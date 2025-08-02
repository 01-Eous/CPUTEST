#include<bits/stdc++.h>
#pragma GCC optimize(0)
#define int unsigned long long
using namespace std;
const int maxn = 4e7 + 5;
int n,idx;
bool vis[maxn];
int pr[maxn],phi[maxn];
unordered_map<int,int> mem;
int sum(int x)
{
    if (x & 1)
        return ((x + 1) >> 1) * x;
    else
        return (x >> 1) * (x + 1);
}
void init(int n = 4e7)
{
    vis[1] = 1,phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
        }
    }
    for (int i = 1; i <= n; i++)
        phi[i] += phi[i - 1];
}
int du(int n)
{
    if (n <= 4e7)
        return phi[n];
    if (mem.find(n) != mem.end())
        return mem[n];
    int res = sum(n);
    for (int l = 2,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res -= (r - l + 1) * du(n / l);
    }
    return mem[n] = res;
}
void solve()
{
    scanf("%llu",&n);
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += (sum(r) - sum(l - 1)) * (du(n / l) - 1);
    }
    printf("%llu\n",ans);
}
signed main()
{
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    signed t;
    scanf("%d",&t);
    while (t--)
        solve();
    fprintf(stderr,"%.3lf\n",clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
