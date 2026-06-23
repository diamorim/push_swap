#ifndef TEST_H
#define TEST_H

int	test_count = 0;

typedef struct s_test
{
	char *name;
	void (*fn)(void);
}	t_test;

t_test test_list[100];

void register_test(char *name, void (*func) (void))
{
	test_list[test_count].name = name;
	test_list[test_count].fn = func;
	test_count++;
}

void run_test(void (*fn)(void))
{
	for (int i = 0; i < test_count; i++)
		test_list[i].fn;
}

#endif