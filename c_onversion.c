#include <stdlib.h>

typedef struct {
    int placeholder;
} Converter;

Converter* new_converter() {
    Converter* converter = malloc(sizeof(converter));
    return converter;
}
