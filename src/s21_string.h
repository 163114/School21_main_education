typedef long unsigned s21_size_t;
#define s21_NULL ((void *)0)


void	*s21_memchr(const void *__s, int __c, s21_size_t __n);
int	 s21_memcmp(const void *__s1, const void *__s2, s21_size_t __n);
void	*s21_memcpy(void *__dst, const void *__src, s21_size_t __n);
void	*s21_memmove(void *__dst, const void *__src, s21_size_t __len);
void	*s21_memset(void *__b, int __c, s21_size_t __len);

char	*s21_strcat(char *__s1, const char *__s2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char	*s21_strchr(const char *__s, int __c);
int	 s21_strcmp(const char *__s1, const char *__s2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

s21_size_t	 s21_strcspn(const char *__s, const char *__charset);
char	*s21_strerror(int __errnum);
s21_size_t	 s21_strlen(const char *__s);
char	*s21_strncat(char *__s1, const char *__s2, s21_size_t __n);
int	 s21_strncmp(const char *__s1, const char *__s2, s21_size_t __n);
char	*s21_strncpy(char *__dst, const char *__src, s21_size_t __n);
char	*s21_strpbrk(const char *__s, const char *__charset);
char	*s21_strrchr(const char *__s, int __c);
s21_size_t	 s21_strspn(const char *__s, const char *__charset);
char	*s21_strstr(const char *__big, const char *__little);
char	*s21_strtok(char *__str, const char *__sep);
s21_size_t	 s21_strxfrm(char *__s1, const char *__s2, s21_size_t __n);
