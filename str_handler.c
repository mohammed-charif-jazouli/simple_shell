#include "shell.h"

/**
 * int_to_ascii - Convert an integer to an ASCII string.
 * @n: The integer to convert.
 *
 * Return: A dynamically allocated ASCII string representing the integer.
 */
char *int_to_ascii(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
        buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    reverse_string(buffer, i);

    return _strdup(buffer);
}

/**
 * reverse_string - Reverse a string in place.
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

/**
 * is_positive_number - Check if a string represents a positive integer.
 * @s: The string to check.
 *
 * Return: 1 if the string is a positive integer, 0 otherwise.
 */
int is_positive_number(const char *s)
{
    int i;

    if (!s)
        return 0;

    for (i = 0; s[i]; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }

    return 1;
}

/**
 * _atoi - Convert an ASCII string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(const char *s)
{
    int i, number = 0;

    for (i = 0; s[i]; i++)
    {
        number *= 10;
        number += (s[i] - '0');
    }

    return number;
}
