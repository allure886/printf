#include "main.h"

/**
 * _print_percent - prints a percent out to the screen
 * @valist: va_list parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 * Return: number of characters
 */

int _print_percent(va_list valist, flag_t *f, mod_t *m)
{
	(void)valist;
	(void)f;
	(void)m;
	return (_putchar('%'));
}

/**
 * _print_specifier - function to handle custom conversion specifier
 * @valist: variable list of arguments
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 * Return: counts of characters
 */

int _print_specifier(va_list valist, flag_t *f, mod_t *m)
{
	int i;
	int count = 0;
	char *hex;
	char *str = va_arg(valist, char *);

	if (str == NULL)
	{
		str = "(null)";
		return (_puts(str));
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex = convert(str[i], 16, 0);
			if (!hex[1])
			{
				count += _putchar('0');
			}
			count += _puts(hex);
		}
		else
			count += _putchar(str[i]);
	}
	(void)f;
	(void)m;
	return (count);
}

/**
 * _print_reverse - prints a string in reverse
 * @valist: va_list parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_m
 * Return: count of characters in a string
 */

int _print_reverse(va_list valist, flag_t *f, mod_t *m)
{
	char *str = va_arg(valist, char *);
	int i = 0, j;

	(void)f;
	(void)m;

	if (!str)
		return (_puts("(null)"));

	while (str[i])
		i++;
	for (j = i - 1; j >= 0; j--)
		_putchar(str[j]);

	return (i);
}

/**
 * _print_rot13 - prints rot 13 encodingof certain letters
 * @valist: va_list parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 * Return: count of characters
 */

int _print_rot13(va_list valist, flag_t *f, mod_t *m)
{
	char *str = va_arg(valist, char *);
	char *input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *output = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYSABCDEFGHIJKLM";
	int i, j;

	(void)f;
	(void)m;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
			_putchar(str[i]);
		else
		{
			for (j = 0; j < 52; j++)
			{
				if (input[j] == str[i])
					_putchar(output[j]);
			}
		}
	}
	return (i);
}

