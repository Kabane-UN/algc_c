#include <stdio.h>

int main()
{
	long long int x0, a, s=0,sp=0;
	int n;
	scanf("%d", &n);
	long long int arr[n];
	scanf("%lld", &x0);
	scanf("%lld", &a);
	if (n==0)
	{
		printf("%ld\n", a);
		printf("%d\n", 0);
		return 0;
	}
	s=a;
	sp=a*n;
	for(long long int i = 0; i < n; i++)
	{
		s*=x0;
		scanf("%ld", &a);
		s+=a;
		if ((n-i) > 1)
		{
			sp*=x0;
			sp+=a*(n-i-1);
		}
	}

	printf("%lld\n", s);
	printf("%lld\n", sp);
	return 0;
}
