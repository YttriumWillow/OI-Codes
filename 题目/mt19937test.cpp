#include <iostream>

#include <random>
#include <ctime>
#include <chrono>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

// 请自行更改数据类型，不传默认 int
// 例如
// const i64 L = 114514;
// uniform_int_distribution<i64> rnd(L, R);

// 其他分布详见 https://zh.cppreference.com/w/cpp/numeric/random

const int L = 0; 	  // 均匀分布生成函数的区间
const int R = 5;
const double P = 0.5; // 伯努利分布生成真值的概率

mt19937 seed(random_device{}());
mt19937 tseed(time(0));
mt19937 ltseed(std::chrono::system_clock::now().time_since_epoch().count());

int main()
{
	// 均匀分布随机整数生成
	uniform_int_distribution<> rnd(L, R); // 生成整数
	for (reg int i = 1; i <= 5; ++i)
		cout << rnd(seed) << " \n"[i == 5];
	
	
	
	// 均匀分布实数生成
	uniform_real_distribution<> frnd(L, R); // 生成实数
	for (reg int i = 1; i <= 5; ++i)
		cout << frnd(seed) << " \n"[i == 5];
		
		
		
	// 伯努利分布布尔值生成
	bernoulli_distribution brnd(P); // 生成布尔值
	int is1 = 0, is0 = 0;
	for (reg int i = 1; i <= 1e7; ++i)
		(brnd(seed) == 1) ? ++is1 : ++is0;
	cout << "true " << is1 * 1.0 / (is1 + is0) << endl;
	
	
	
	// 简单正态分布生成
	normal_distribution<> prnd(5, 2); // 生成正态分布布尔值
									  // 参数：平均值、标准差
	for (reg int i = 1; i <= 5; ++i)
        cout << prnd(seed) << " \n"[i == 5];
    
    
    
	return 0; 
}