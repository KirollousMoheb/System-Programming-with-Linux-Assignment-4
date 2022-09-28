#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{

  int chars_printed;

  for (int i = 1; i < argc; i++)
    {

      chars_printed = printf ("%s ", argv[i]);
      if (chars_printed != strlen (argv[i]) + 1)
        {
          perror ("printf() failed");
        }
    }
  printf ("\n");




  return 0;
}
