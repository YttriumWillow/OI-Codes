#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, ans;
int schedule[410];      // 给出的计划表

int mac[21][21];        // 每个零件每道工序所需机器
int tim[21][21];       // 每个零件每道工序所需时间

int nowGoingStep[21];   // 零件正在进行工序
int nowEndingTime[21];  // 零件上次结束

bool table[21][100010];  // 时间表

int main()
{
    scanf("%d%d", &m, &n);
    for (reg int i = 1; i <= m * n; ++i)
        scanf("%d", &schedule[i]);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            scanf("%d", &mac[i][j]);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            scanf("%d", &tim[i][j]);
    
    for (reg int i = 1; i <= m * n; ++i)
    {
        int nowWorking = schedule[i];                   // 目前加工的零件
        int nowstep = ++nowGoingStep[nowWorking];       // 目前该零件的工序
        int nowWorkingMac = mac[nowWorking][nowstep];   // 目前工序所需的机器
        int nowNeedTime = tim[nowWorking][nowstep];     // 目前该工序所需时间
        int countingTime = 0;                           // 逐 tick 计算当前时间
        int startTimeStamp = nowEndingTime[nowWorking] + 1;                           
        
        for (reg int p = nowEndingTime[nowWorking] + 1; ; ++p)
        {
            // 按每 tick 统计一次
            if (table[nowWorkingMac][p] == 0)
                countingTime++;
            else
                countingTime = 0, startTimeStamp = p + 1;
            if (countingTime == nowNeedTime)
            {
                for (reg int j = startTimeStamp; j <= p; ++j)
                    table[nowWorkingMac][j] = 1;
                ans = max(ans, p);
                nowEndingTime[nowWorking] = p;
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}