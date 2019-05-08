#include <bits/stdc++.h>
using namespace std;
#define sz size()
#define x first
#define y second
#define mp make_pair
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
#define pb push_back
#define all(v) v.begin(),v.end()
#define EPS 1e-9
#define MOD 1000000007
#define MAX 1005
typedef pair<int,int> pii;
typedef long long ll;

struct Matrix
{
    vector< vector<int> > mat;
    int n_rows, n_cols;

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + (mat[i][k] * 1ll * other.mat[k][j]) % MOD) % MOD;
                }
            }
        return Matrix(result);
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix fast_exponentiation(Matrix m, int power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main()
{
    vector<vector<int>> r(3);

    int cnt = 1;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            r[i].pb(cnt++);

    vector<vector<int>> _r(1);
    for(int i=0; i<3; i++)
        _r[0].pb(1);

    Matrix m(r),_m(_r);


    Matrix res = fast_exponentiation(m,3);

    Matrix ans = _m * res;

    for(int i=0; i<1; i++,printf("\n"))
        for(int j=0; j<3; j++)
            printf("%d ",ans.mat[i][j]);

}
