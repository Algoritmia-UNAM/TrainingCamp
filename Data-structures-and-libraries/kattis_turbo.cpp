#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int MAXN = 100000;

int tree[MAXN+5], a[MAXN+5], swaps[MAXN+5];

void update(int x)
{
	for (int i = x; i <= MAXN; i += i & (-i))
		++tree[i];
}

int query(int x)
{
	int sum = 0;
	for (int i = x; i > 0; i -= i & (-i))
		sum += tree[i];
	return sum;
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int n;
	scanf("%d", &n);

	For(i, 0, n)
		scanf("%d", &a[i]);

	For(i, 0, n)
	{
		if (a[i] <= n/2 + (n & 1))
		{
			int l = a[i]+1, r = n-a[i]+1;
			int s = 0;
			if (l <= r)
				s = query(r) - query(l-1);

			swaps[a[i]] = s;
		}
		update(a[i]);
	}
	
	memset(tree, 0, sizeof tree);
	for(int i = n-1; i >= 0; --i)
	{
		if (a[i] > n/2 + (n & 1))
		{
			int l = n-a[i]+2, r = a[i]-1;
			int s = 0;
			if (l <= r)
				s = query(r) - query(l-1);

			swaps[a[i]] = s;
		}
		update(a[i]);
	}

	For(i, 1, n+1)
	{
		if (i & 1)
			printf("%d\n", swaps[i/2 + 1]);
		else
			printf("%d\n", swaps[n - i/2 + 1]);
	}

	return 0;
}
