#ifndef MAIN_H
#define MAIN_H

int _isupper(int c);
char *_strcat(char *dest, char *src);
int _isdigit(int c);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
int _islower(int c);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_memset(char *s, char b, unsigned int n);
int _atoi(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);
void _puts(char *str);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
int _abs(int a);

#endif
