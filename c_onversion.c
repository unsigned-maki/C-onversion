/** 
MIT License

Copyright (c) 2021 Niclas (unsigned-maki)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**/

#include <stdlib.h>
#include <stdio.h>

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
 *@brief ASCII lookup list with each alphabetical character replaced with it's opposite.
 *
 */

const unsigned int ascii_reverse_lookup[123] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
	60, 61, 62, 63, 64, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
	109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 91, 92,
	93, 94, 95, 96, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
	81, 82, 83, 84, 85, 86, 87, 88, 89, 90
};

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
		if ((lower[i] < 123 && lower[i] >= 0) && (lower[i] < 65 || lower[i] > 90))
			upper[i] = ascii_reverse_lookup[lower[i]];
		else
			upper[i] = lower[i];
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
		if (upper[i] < 97 && upper[i] >= 0) {
			lower[i] = ascii_reverse_lookup[upper[i]];
		}
		else
			lower[i] = upper[i];
	}

	return lower;
}

Converter* new_converter()
{
	Converter *converter = malloc(sizeof(Converter));
	Char character = {
		&char_to_upper, 
		&char_to_lower
	};
	converter->character = character;
	return converter;
}
