#include <iostream>

#define longint long long
#define reg register

using namespace std;

bool isPrime[50000010];
longint Prime[3000010], cnt, n;

void GetPrime(longint n)
{
	for (reg int i = 1; i <= n; ++i)
        isPrime[i] = 1;
	isPrime[1] = 0;
	for (reg int i = 2; i <= n; ++i)
	{
		if (isPrime[i])
			Prime[++cnt] = i;
		for (reg int j = 1; j <= cnt && i * Prime[j] <= n; ++j) 
		{
			isPrime[i * Prime[j]] = 0;
			if (i % Prime[j] == 0) break;
		}
	}
	return;
}

int main()
{
	GetPrime(10010);
	cout << cnt << endl;
	for (reg int i = 0; i <= cnt; ++i)
		cout << Prime[i] << ',';
	return 0;
}