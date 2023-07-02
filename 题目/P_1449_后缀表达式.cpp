#include <iostream>

#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define push push_back
#define pop pop_back
#define top back

using namespace std;

char ch;
int x = 0, x1, x2;
vector<int> st;

int main()
{
    while (ch != '@')
    {
        ch = getchar();
        if (ch == '.')      { st.push(x); x = 0; }
        else if (ch == '+') { x2 = st.top(); st.pop(); x1 = st.top(); st.pop(); st.push(x1 + x2); }
        else if (ch == '-') { x2 = st.top(); st.pop(); x1 = st.top(); st.pop(); st.push(x1 - x2); }
        else if (ch == '*') { x2 = st.top(); st.pop(); x1 = st.top(); st.pop(); st.push(x1 * x2); }
        else if (ch == '/') { x2 = st.top(); st.pop(); x1 = st.top(); st.pop(); st.push(x1 / x2); }
        else x = x * 10 + ch - '0';
    }
    printf("%d\n", st.top());
    return 0;
}