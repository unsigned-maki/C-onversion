#ifndef C_ONVERSION_
#define C_ONVERSION_

typedef char *(*to_upper)(char *lower);

typedef char *(*to_lower)(char *upper);

typedef struct
{
	to_upper to_upper;
	to_lower to_lower;
}

Char;

typedef struct
{
	Char character;
}

Converter;

Converter *new_converter();

#endif
