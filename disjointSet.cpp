#include <bits/stdc++.h>
using namespace std;
#define sz size()
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define MAX 1024

int M[MAX],R[MAX];

int fn(int p)
{
    if (p != M[p]) M[p] = fn(M[p]);
    return M[p];
    //return M[p]==p ? p : fn(M[p]);
}

void un(int p1,int p2)
{
    if(R[p2] > R[p1]) swap(p1,p2);
    M[p2] = p1;
    R[p1] += R[p2];
}

int main()
{

}
