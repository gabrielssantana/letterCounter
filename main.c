#include <stdio.h>
#include <unistd.h>

#define MAX_STR_LEN 255

typedef struct s_characterCount
{
  char character;
  int count;
} t_characterCount;

int ft_strlen(char *str)
{
  int len = 0;
  while (str[len])
  {
    len++;
  }

  return len;
}

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(char *str)
{
  int len = -1;
  while (str[++len])
  {
    ft_putchar(str[len]);
  }
}

void ft_putnbr(int number)
{
  char nbr = number + '0';
  ft_putchar(nbr);
}

int ft_isnormalchar(char c)
{
  if (c >= 33 && c <= 126)
  {
    return 1;
  }
  return 0;
}

void ft_printresult(t_characterCount *result)
{

  int len = -1;
  ft_putstr("\nResultado: \n");
  while (ft_isnormalchar(result[++len].character) == 1)
  {
    ft_putstr("   Caracter: ");
    ft_putchar(result[len].character);
    ft_putstr(",\n   Quantidade: ");
    ft_putnbr(result[len].count);
    ft_putstr(",\n");
  }
}

void ft_initstruct(t_characterCount *charCount, int maxLen)
{
  int len = -1;
  while (++len <= maxLen)
  {
    charCount[len].character = '\0';
    charCount[len].count = 0;
  }
}

void ft_sanitizestr(char *str)
{
  int len = -1;
  char sanitized[MAX_STR_LEN];
  int sanitizedLen = 0;

  while (str[++len])
  {
    if (ft_isnormalchar(str[len]) == 1)
    {
      sanitized[sanitizedLen] = str[len];
      sanitizedLen++;
    }
  }

  len = -1;
  sanitizedLen = 0;

  while (str[++len])
  {
    str[len] = sanitized[sanitizedLen];
    sanitizedLen++;
  }
}

int main()
{
  t_characterCount charactersCountArr[MAX_STR_LEN];
  char input[MAX_STR_LEN];
  fgets(input, MAX_STR_LEN, stdin);
  ft_sanitizestr(input);
  int inputLen = 0;
  int maxLen = ft_strlen(input);

  ft_initstruct(charactersCountArr, maxLen);

  while (input[inputLen])
  {
    char character = input[inputLen];
    int auxLen = 0;
    int found = 0;

    while (auxLen <= maxLen)
    {
      if (charactersCountArr[auxLen].character == character)
      {
        found = 1;
        break;
      }
      auxLen++;
    }

    if (found == 1)
    {
      charactersCountArr[auxLen].count++;
      inputLen++;
      continue;
    }

    auxLen = 0;
    while (auxLen <= maxLen)
    {
      if (charactersCountArr[auxLen].character == '\0')
      {
        charactersCountArr[auxLen].character = character;
        charactersCountArr[auxLen].count = 1;
        break;
      }
      auxLen++;
    }
    inputLen++;
  }

  ft_printresult(charactersCountArr);

  return 0;
}
