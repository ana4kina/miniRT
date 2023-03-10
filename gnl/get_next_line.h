#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
char	*ft_strljoin(char const *s1, char const *s2, size_t l);
char	*ft_strchr(const char *s, int c);
// size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif