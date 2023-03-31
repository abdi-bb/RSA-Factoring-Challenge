#include "factors.h"

void get_fact(unsigned long long int num)
{
	unsigned long long int i;

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%llu=%llu*%llu\n", num, (num / i), i);
			break;
		}
	}
}

