#include "factors.h"

int main(int argc __attribute__((unused)), char *argv[])
{
	char *cmd = NULL;
	size_t len = 0;
	FILE *fp;

	fp = fopen(argv[1], "r");
	while (getline(&cmd, &len, fp) != EOF)
	{
		get_fact(atoi(cmd));
	}
	free(cmd);
	fclose(fp);
	return (0);
}
