#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        printf("The result of No. %d Case is:  ", i);
        system("gen");
        system("ans");
        system("test");
        if (system("fc a.ans a.out"))
        {
            printf("Wrong Answer\n");
            break;
        }
        else
            printf("Accepted\n");
    }
    return 0;
}
