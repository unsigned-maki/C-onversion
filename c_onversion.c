#include <stdlib.h>

typedef char *(*to_upper)(char *lower);

typedef char *(*to_lower)(char *upper);

/**
 *@brief Holds pointers to character conversion utility functions.
 *
 */

typedef struct
{
	to_upper to_upper;
	to_lower to_lower;
}

Char;

/**
 *@brief Holds structs with conversion utility functions.
 *
 */

typedef struct
{
	Char character;
}

Converter;

/**
 *@brief Determines the length of a passed array of characters.   
 * 
 *@param c_str pointer to an array of characters.
 *@return size_t length of the passed array of characters.
 */

size_t length(char *c_str);

/**
 *@brief Copies a passed array of characters and converts all lower-case characters to upper-case.
 * 
 *@param lower pointer to an array of characters containing lower-case characters. 
 *@return char* pointer to a copy of the passed array with all lower-case characters converted to upper-case.
 */

char *char_to_upper(char *lower);

/**
 *@brief Copies a passed array of characters and converts all lower-case characters to lower-case.
 * 
 *@param upper pointer to an array of characters containing upper-case characters. 
 *@return char* pointer to a copy of the passed array with all upper-case characters converted to lower-case.
 */

char *char_to_lower(char *upper);

/**
 *@brief Constructs a Converter struct and returns a pointer to it. 
 * 
 *@return Converter* pointer to Converter struct.
 */

Converter* new_converter();

size_t length(char *c_str)
{
	size_t length;
	for (length = 0; c_str[length] != '\0'; length++);
	return length;
}

char *char_to_upper(char *lower)
{
	size_t lower_length = length(lower);
	char *upper = malloc(lower_length);
	upper[lower_length] = '\0';

	for (size_t i = 0; i < lower_length; i++)
	{
		switch (lower[i])
		{
			case 'a':
				upper[i] = 'A';
				break;
			case 'b':
				upper[i] = 'B';
				break;
			case 'c':
				upper[i] = 'C';
				break;
			case 'd':
				upper[i] = 'D';
				break;
			case 'e':
				upper[i] = 'E';
				break;
			case 'f':
				upper[i] = 'F';
				break;
			case 'g':
				upper[i] = 'G';
				break;
			case 'h':
				upper[i] = 'H';
				break;
			case 'i':
				upper[i] = 'I';
				break;
			case 'j':
				upper[i] = 'J';
				break;
			case 'k':
				upper[i] = 'K';
				break;
			case 'l':
				upper[i] = 'L';
				break;
			case 'm':
				upper[i] = 'M';
				break;
			case 'n':
				upper[i] = 'N';
				break;
			case 'o':
				upper[i] = 'O';
				break;
			case 'p':
				upper[i] = 'P';
				break;
			case 'q':
				upper[i] = 'Q';
				break;
			case 'r':
				upper[i] = 'R';
				break;
			case 's':
				upper[i] = 'S';
				break;
			case 't':
				upper[i] = 'T';
				break;
			case 'u':
				upper[i] = 'U';
				break;
			case 'v':
				upper[i] = 'V';
				break;
			case 'w':
				upper[i] = 'W';
				break;
			case 'x':
				upper[i] = 'X';
				break;
			case 'y':
				upper[i] = 'Y';
				break;
			case 'z':
				upper[i] = 'Z';
				break;
			default:
				upper[i] = lower[i];
				break;
		}
	}

	return upper;
}

char *char_to_lower(char *upper)
{
	size_t upper_length = length(upper);
	char *lower = malloc(sizeof(char) *upper_length);
	lower[upper_length] = '\0';

	for (size_t i = 0; i < upper_length; i++)
	{
		switch (upper[i])
		{
			case 'A':
				lower[i] = 'a';
				break;
			case 'B':
				lower[i] = 'b';
				break;
			case 'C':
				lower[i] = 'c';
				break;
			case 'D':
				lower[i] = 'd';
				break;
			case 'E':
				lower[i] = 'e';
				break;
			case 'F':
				lower[i] = 'f';
				break;
			case 'G':
				lower[i] = 'g';
				break;
			case 'H':
				lower[i] = 'h';
				break;
			case 'I':
				lower[i] = 'i';
				break;
			case 'J':
				lower[i] = 'j';
				break;
			case 'K':
				lower[i] = 'k';
				break;
			case 'L':
				lower[i] = 'l';
				break;
			case 'M':
				lower[i] = 'm';
				break;
			case 'N':
				lower[i] = 'n';
				break;
			case 'O':
				lower[i] = 'o';
				break;
			case 'P':
				lower[i] = 'p';
				break;
			case 'Q':
				lower[i] = 'q';
				break;
			case 'R':
				lower[i] = 'r';
				break;
			case 'S':
				lower[i] = 's';
				break;
			case 'T':
				lower[i] = 't';
				break;
			case 'U':
				lower[i] = 'u';
				break;
			case 'V':
				lower[i] = 'v';
				break;
			case 'W':
				lower[i] = 'w';
				break;
			case 'X':
				lower[i] = 'x';
				break;
			case 'Y':
				lower[i] = 'y';
				break;
			case 'Z':
				lower[i] = 'z';
				break;
			default:
				lower[i] = upper[i];
				break;
		}
	}

	return lower;
}

Converter *new_converter()
{
	Converter *converter = malloc(sizeof(Converter));
	Char character = { 
        &char_to_upper,
        &char_to_lower
	};
	converter->character = character;
	return converter;
}
