#include "palindrome.h"

/**
 * is_palindrome - checks if an int is a palindrome
 * @n: number to check
 *
 * Return: 1 if true 0 if false
 */
int is_palindrome(unsigned long n)
{
    int div = 1;
    while ( n / div >= 10) {
        div *= 10;
    }
    while (n != 0)
    {
        int l = n / div;
        int r = n % 10;
        if ( l != r) {
            return (0);
        }
        n = ( n % div) / 10;
        div = div / 10;
    }
    return (1);
}

