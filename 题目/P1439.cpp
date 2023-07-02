// Problem:      P1439 【模板】最长公共子序列
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1439
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-06 20:12:20

/*
    FileName: AT_dp_f_LCS.cpp
        + randomhash: 6b9fb26582be2075bbc6aec8
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/21 星期五
    Time: 19:13:05
        + Unix Timestamp(second): 1666350785
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '
#define tab '\t'

using namespace std;

int n;
int a[100010], b[100010];
int f[10010][10010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> n;
    for (reg int i = 1; i <= n; ++i)
    	cin >> a[i];
    for (reg int i = 1; i <= n; ++i)
    	cin >> b[i];
			
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);

    cout << f[n][n] << endl;
    return 0;
}