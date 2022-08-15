/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:20:15 by gpiccion          #+#    #+#             */
/*   Updated: 2022/01/29 18:20:15 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Converts string to integer. Returns the converted value.
// If no valid conversion could be performed, it returns 0.
int		ft_atoi(const char *nptr);

// Sets the first 'n' bytes of the area starting at 's' to zero.
void	ft_bzero(void *s, size_t n);

// Allocates memory for an array of 'nmemb' elements of 'size' bytes each.
// The memory is set to zero.
// If 'nmemb' or 'size' is 0, then calloc() returns either NULL,
// or a unique pointer value that can later be successfully passed to free().
// Returns a void pointer to the allocated memory.
// Returns NULL on error, or when 'nmemb' or 'size' are equal to zero.
void	*ft_calloc(size_t nmemb, size_t size);

// Returns 1 if 'c' is an alphabetic or numeric character, otherwise returns 0.
int		ft_isalnum(char c);

// Returns 1 if 'c' is an alphabetic character, otherwise returns 0.
int		ft_isalpha(char c);

// Returns 1 if 'c' is a 7-bit unsigned char value
// that fits into the ASCII character set, otherwise returns 0.
int		ft_isascii(size_t c);

// Returns 1 if 'c' is a digit, otherwise returns 0.
int		ft_isdigit(char c);

// Returns 1 if 'c' is a printable character, otherwise returns 0.
int		ft_isprint(char c);

// Allocates and returns a string representing the integer 'n'.
// Negative numbers are handled.
// Returns NULL if the allocation fails.
char	*ft_itoa(int n);

// Scans the initial 'n' bytes of the memory pointed to by 'str'
// for the first instance of 'c'.
// Returns a pointer to the matching byte, if one is found.
// Otherwise, the result is unspecified.
void	*ft_memchr(const void *str, int c, size_t n);

// Compares the first 'n' bytes (each interpreted as unsigned char)
// of the memory areas s1 and s2.
// Returns an integer less than, equal to, or greater than zero
// if the first 'n' bytes of 's1' is found, respectively, 
// to be less than, to match, or be greater than the first 'n' bytes of 's2'.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Copies 'n' bytes from memory area 'src' to memory area 'dest'.
// The memory areas must not overlap.
// Returns a pointer to 'dest'.
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Copies 'n' bytes from memory area 'src' to memory area 'dest'.
// The memory areas may overlap.
// First copies into a temporary array, then copies from that array to 'dest'.
// Returns a pointer to 'dest'.
void	*ft_memmove(void *dest, const void *src, size_t n);

// Fills the first 'n' bytes of the memory area pointed to by 's'
// with the constant byte 'c'.
// Returns a pointer to the memory area 's'.
void	*ft_memset(void *s, int c, size_t n);

// Outputs the character 'c' to the given file descriptor.
void	ft_putchar_fd(char c, int fd);

// Outputs the string 's' to the given file descriptor, followed by a newline. 
void	ft_putendl_fd(char *s, int fd);

// Outputs the integer 'n' to the given file descriptor. 
void	ft_putnbr_fd(int n, int fd);

// Outputs the string 's' to the given file descriptor. 
void	ft_putstr_fd(char *s, int fd);

// Allocates and returns an array of strings obtained by splitting 's'
// using the character 'c' as a delimiter.
// The array must be ended by a NULL pointer.
// Returns NULL if the allocation fails. 
char	**ft_split(char const *s, char c);

// Returns a pointer to the first occurrence of the char 'c' in 'str'.
// If no match is found, returns NULL.
char	*ft_strchr(const char *str, int c);

// Returns a pointer to a new string which is a duplicate of the string 's'.
// Memory for the new string is obtained with malloc and can be freed with free.
char	*ft_strdup(const char *s);

// Applies the function 'f' to each character of the string passed as argument,
// and passing its index as first argument.
// Each character is passed by address to 'f' to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Allocates and returns a new string,
// which is the result of the concatenation of 's1' and 's2'. 
// Returns the new string, or NULL if the allocation fails. 
char	*ft_strjoin(char const *s1, char const *s2);

// Concatenates strings (dst + src). At most 'size - strlen(dst) - 1' bytes,
// NUL-terminating the result.
// Returns the total length of the string it tried to create.
// That means, the initial length of 'dst' plus the length of 'src'.
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// Copies up to 'size' - 1 characters from the NUL-terminated string 'src' 
// to 'dst', NUL-terminating the result.
// Returns the total length of the string they tried to create
// (that means, the length of 'src').
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// Returns the number of bytes of the NUL-terminated string 'str'.
// Excludes the terminating null byte.
size_t	ft_strlen(const char *str);

// Applies the function 'f' to each character of the string 's',
// and passing its index as first argument to create a new string
// (with malloc(3)) resulting from successive applications of 'f'.
// Returns the string created from the successive applications of 'f',
// or NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Compares the first (at most) 'n' bytes of 's1' and 's2'.
// Returns an int less than, equal to, or greater than zero if 's1' is found,
// respectively, to be less than, to match, or be greater than 's2'.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Locates the first occurrence of the null-terminated string 'little'
// in the string 'big', where not more than 'len' characters are searched.
// Characters that appear after a ‘\0’ character are not searched.
char	*ft_strnstr(const char *big, const char *little, size_t len);

// Returns a pointer to the last occurrence of the char 'c' in the string 's'.
char	*ft_strrchr(const char *str, int c);

// Allocates (with malloc) and returns a copy of 's1' with the chars
// specified in 'set' removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set);

// Allocates (with malloc) and returns a substring from the string 's'. 
// The substring begins at index 'start' and is of maximum size 'len'. 
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Converts the letter 'c' to lower case, if possible.
int		ft_tolower(int c);

// Converts the letter 'c' to upper case, if possible.
int		ft_toupper(int c);

/*-----------BONUS-----------*/

// Allocates (with malloc) and returns a new element.
t_list	*ft_lstnew(void *content);

// Adds the element ’new’ at the beginning of the list 'lst'. 
void	ft_lstadd_front(t_list **lst, t_list *new);

//  Adds the element 'new' at the end of the list 'lst'.
void	ft_lstadd_back(t_list **lst, t_list *new);

// Counts the number of elements in the list 'lst'.
int		ft_lstsize(t_list *lst);

// Returns the last element of the list 'lst'.
t_list	*ft_lstlast(t_list *lst);

// Frees the memory of the element pointed by 'lst',
// using the function 'del'.
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// Deletes and frees the element 'lst' and every successor
// of that element, using the function 'del' and free(3).
// Sets pointer to the list to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *));

// Iterates the list 'lst' and applies the function 'f'
// to the content of each element.
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Iterates the list 'lst' and applies the function 'f' to the
// content of each element, creating a new list as a result.
// The 'del' function is used to delete the content of an element if needed.
// Returns a pointer to the new list, or NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif