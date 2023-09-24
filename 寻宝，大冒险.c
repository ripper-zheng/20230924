#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int n, L, S;
int b[110][110], x[1010], y[1010];
int tmp[110][110];

int i,j,k;
int main()
{
    scanf("%d%d%d", &n, &L, &S);

    for ( i = 0; i < n; i ++ )
        scanf("%d%d", &x[i], &y[i]);

    for ( i = S; i >= 0; i -- )
        for ( j = 0; j <= S; j ++ )
            scanf("%d", &b[i][j]);

    int res = 0;
    for ( i = 0; i < n; i ++ )
    {
        memset(tmp, 0, sizeof tmp);
        for ( j = 0; j < n; j ++ )
            if (x[j] >= x[i] && x[j] <= x[i] + S && y[j] >= y[i] && y[j] <= y[i] + S)
                tmp[x[j] - x[i]][y[j] - y[i]] = 1;

        int  flag = 1;
        for ( j = 0; j <= S; j ++ )
            for ( k = 0; k <= S; k ++ )
                if (tmp[j][k] != b[j][k] || x[i] + j > L || y[i] + k > L)
                {
                    flag = 0;
                    break;
                }

        res += flag;
    }

    printf("%d", res);

    return 0;
}






