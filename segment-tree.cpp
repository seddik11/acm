#include <bits/stdc++.h>
using namespace std;
#define sz size()
#define x first
#define y second
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
#define pb push_back
#define all(v) v.begin(),v.end()
#define EPS 1e-9
#define MOD 1000000007
#define INF 1000000009
#define MAX 100005
typedef pair<int,int> pii;
typedef long long ll;

int S[MAX * 3];
int T[MAX * 3];
int N;

void build(int n,int l,int r)
{
    if(l == r)
    {
        //S[n] = T[l];
        S[n] = l;
        return;
    }

    int m = (l+r)/2;
    build(n*2,l,m);
    build(n*2+1,m+1,r);
    //S[n] = S[n*2] + S[n*2+1];
    //S[n] = min(S[n*2] , S[n*2+1]);
}

void update(int n,int l,int r,int idx,int v)
{
    if(l == r)
    {
        //T[idx] = v;
        S[n] = v;
        return;
    }

    int m = (l+r)/2;
    if(l <= idx && idx <= m)
    update(n*2,l,m,idx,v);
    else
    update(n*2+1,m+1,r,idx,v);

    //S[n] = S[n*2] + S[n*2+1];
    S[n] = min(S[n*2] , S[n*2+1]);
}

int query(int n,int l,int r,int s,int e)
{
    if(e < l || s > r)
    return 0;

    if(s <= l && r <= e)
    return S[n];

    int m = (l+r)/2;
    int p1 = query(n*2,l,m,s,e);
    int p2 = query(n*2+1,m+1,r,s,e);
    //return (p1 + p2);
    //return min(p1 , p2);
    if(T[p1] <= T[p2])
    return p1;
    else
    return p2;
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
    scanf("%d",T+i);
    T[0] = INF;
    build(1,1,N);
    //update(1,1,N,3,2);
    int Q,u,v;
    scanf("%d",&Q);
    for(int i=0; i<Q; i++)
    {
        scanf("%d %d",&u,&v);
        printf("%d\n",query(1,1,N,u,v));
    }
}
