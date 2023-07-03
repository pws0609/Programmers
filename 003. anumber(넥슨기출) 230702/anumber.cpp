#include<iostream>
using namespace std;
int F(int n);
int len(int n);
int main() {
	int n;
	cin >> n;
	cout << F(n);
	return 0;
	while (true) {
		if (F(n) == 1)
			break;
		n--;
	}
	cout << n;
	return 0;
}

int F(int n) {
	int tmp = n;
	int tmp2 = n;
	int cnt = 0;
	int fin = 0;
	long int res = 0;
	while (tmp > 0) {
		tmp /= 10;
		cnt++;
	}
	tmp = n;
	for (int i = 1; i <= cnt; i++) {
		res += (tmp % 10) * tmp2;
		tmp /= 10;
		tmp2 = len(tmp2);
	}
	cout << res<<'\n';
	for (int i = 0; i < cnt; i++) {
		int a = res % 10;
		for (int j = 1; j < i; j++)
			a *= 10;
		fin += a;
		res /= 10;
	}
	cout << fin << '\n';
	if (fin == n)
		return 1;
	return 0;
}

int len(int n) {
	int orgn = n;
	int cntt = 0;
	while (orgn > 10) {
		orgn /= 10;
		cntt++;
	}
	for (int i = 1; i <= cntt; i++)
		orgn *= 10;
	return n - orgn;
}
