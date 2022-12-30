#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

#define BASE_2 2
#define BASE_10 10
#define BASE_16 16

void clear_screen();

long safe_strtol(const char *str, bool exit_on_error);

long safely_convert_string_to_long(const char *str, bool exit_on_error);

#endif