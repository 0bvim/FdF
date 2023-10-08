![libft](../../../42-project-badges/blob/main/covers/cover-libft-bonus.png)

<div align='center'>
  
## This is a project that I need to make my own lib replying function of `C` lib.
## Concatenating with header file `(.h)` and using Makefile to compile a statib lib.
</div>

### implemented functions so far:
| Functions                        | Details                                                                                                                                                                                                                                                                                                |
|----------------------------------|--------------------------------------------|
| [`ft_atoi.c`](./ft_atoi.c)       | Converts the initial portion of the string pointed to by str to int representation|
| [`ft_bzero.c`](./ft_bzero.c)     | The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.|
| [`ft_calloc.c`](./ft_calloc.c)   | The calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero.|
| [`ft_isalnum.c`](./ft_isalnum.c) | Checks for an alphanumeric character; it is equivalent to (isal‐pha(c) \|\| is-digit(c)).\|\| isdigit(c)).|
| [`ft_isalpha.c`](./ft_isalpha.c) | Checks for an alphabetic character; in the standard "C" locale,  it  is  equivalent  to (isupper(c)  \|\|  islower(c)). In some locales, there may be additional characters for which isalpha() is true—letters which are neither uppercase nor lowercase.|
| [`ft_isascii.c`](./ft_isascii.c) | Checks whether c is a `7‐bit unsigned char` value that fits into the ASCII character set.|
| [`ft_isdigit.c`](./ft_isdigit.c) | Checks for a digit (0 through 9).|
| [`ft_isprint.c`](/ft_isprint.c)  | Checks for any printable character including space.|
| [`ft_itoa.c`](/ft_itoa.c)        | he string representing the integer. NULL if the allocation fails.|
| [`ft_memchr.c`](./ft_memchr.c)   |  The  memchr()  function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.|
| [`ft_memcmp.c`](./ft_memcmp.c)   | The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.|
| [`ft_memcpy.c`](./ft_memcpy.c)   | The memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. `Use memmove(3) if the memory areas do overlap.`|
| [`ft_memmove.c`](./ft_memmove.c) | The memmove() function copies n bytes from memory area src to memory area dest. `The memory areas may overlap:` copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest. |
| [`ft_memset.c`](./ft_memset.c)   | The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.|
| [`ft_split.c`](./ft_split.c)     | The array of new strings resulting from the split. NULL if the allocation fails.|
| [`ft_strchr.c`](./ft_strchr.c)   | The strchr() function returns a pointer to the first occurrence of the character c in the string s.|
| [`ft_strdup.c`](./ft_strdup.c)   | The strncmp() function  is similar, except it compares only the first (at most) n bytes of s1 and s2.|
| [`ft_striteri.c`](./ft_striteri.c) | Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to ’f’ to be modified if necessary.
| [`ft_strjoin.c`](./ft_strjoin.c) | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.|
| [`ft_strlcat.c`](./ft_strlcat.c) | The strlcat() function concatenate strings. And the explanation is the same of strlcpy function.|
| [`ft_strlcpy.c`](./ft_strlcpy.c) | The strlcpy() function copy a string. This function are designed to be safer, more consistent, and less error prone replacements for strncpy(3). Strlcpy take the full size of the buffer (not just the lenght) and guarantee to NUL-terminate the result.|
| [`ft_strlen.c`](./ft_strlen.c)   | Calculate the `length` of a string.|
| [`ft_strmapi.c`](./ft_strmapi.c) | Applies the function ’f’ to each character of the string ’s’, and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.|
| [`ft_strncmp.c`](./ft_strncmp.c) | The strncmp() function  is similar, except it compares only the first (at most) n bytes of s1 and s2.|
| [`ft_strnstr.c`](./ft_strnstr.c) | The strnstr() function locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.|
| [`ft_strrchr.c`](./ft_strrchr.c) | The strrchr() function returns a pointer to the last occurrence of the character c in the string s.|
| [`ft_strtrim.c`](./ft_strtrim.c) | Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.|
| [`ft_tolower.c`](./ft_substr.c)  | Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.|
| [`ft_tolower.c`](./ft_tolower.c) | Convert to lowercase.|
| [`ft_toupper.c`](./ft_toupper.c) | Convert to uppercase.|

#

## Bonus
| Functions                        | Details                                                                                                                                                                                                                                                                                                |

### Header file
[`libft.h`](./libft.h)

### Make
[`Makefile`](./Makefile)
