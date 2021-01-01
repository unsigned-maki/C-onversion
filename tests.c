#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_onversion.h"
#define TEST_COUNT 2

int main()
{
	Converter *converter = new_converter();

	int passed_test_count = 0;

	printf("%s\n", "Running tests...");

	if (!strcmp(converter->character.to_upper("test123"), "TEST123"))
	{
		printf("%s\n", "Converter.Char.to_upper function test passed.");
		passed_test_count++;
	}
	else
		printf("%s\n", "Converter.Char.to_upper function test not passed.");

	if (!strcmp(converter->character.to_lower("TEST123"), "test123"))
	{
		printf("%s\n", "Converter.Char.to_lower function test passed.");
		passed_test_count++;
	}
	else
		printf("%s\n", "Converter.Char.to_lower function test not passed.");

	printf("%d/%d tests passed.", passed_test_count, TEST_COUNT);

	return 0;
}