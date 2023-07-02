// Problem:			P3389 【模板】高斯消元法
// Contest:			Luogu
// URL:				https://www.luogu.com.cn/problem/P3389
// Memory Limit:	125 MB
// Time Limit:		1000 ms
// Created Time:	2023-02-19 20:48:09

#include <iostream>

#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const double eps = 1e-7;

int n;
double matrix[110][110];
double ans[110];

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n + 1; ++j)
            scanf("%lf", &matrix[i][j]);
    for (reg int i = 1; i <= n; ++i)
    {
        int r = i;
        for (reg int j = i + 1; j <= n; ++j)
            if (fabs(matrix[r][i]) < fabs(matrix[j][i]))
                r = j; // 找到第一行最大系数
        if (fabs(matrix[r][i]) < eps)
        {
            printf("No Solution\n");
            return 0;
        }
        if (i != r)
            swap(matrix[i], matrix[r]); // 交换行操作
        double div = matrix[i][i];
        for (reg int j = i; j <= n + 1; ++j)
            matrix[i][j] /= div; // 对每一行除同一个数
        for (reg int j = i + 1; j <= n; ++j)
        {
            div = matrix[j][i];
            for (reg int k = i; k <= n + 1; ++k)
                matrix[j][k] -= matrix[i][k] * div;
        }
    }
    ans[n] = matrix[n][n + 1];
    for (reg int i = n - 1; i >= 1; --i)
    {
        ans[i] = matrix[i][n + 1];
        for (reg int j = i + 1; j <= n; ++j)
            ans[i] -= (matrix[i][j] * ans[j]);
        if (fabs(ans[i] - 0) < eps)
            ans[i] = eps;
    }
    for (reg int i = 1; i <= n; ++i)
        printf("%.2lf\n", ans[i]);
    return 0;
}