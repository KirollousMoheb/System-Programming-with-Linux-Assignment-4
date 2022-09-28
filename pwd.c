#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
  long size;
  char *buff;
  char *ptr;

  size = pathconf (".", _PC_PATH_MAX);
  if ((buff = (char *) malloc ((size_t) size)) != NULL)
    {
      ptr = getcwd (buff, (size_t) size);
      if (ptr != NULL)
	{

	  printf ("%s\n", buff);

	}
      else
	{
	 ("Error");
	 return -1;
	}
	
    }
  else
    {
      perror ("Error");
      return -1;
    }
 free(buff);
 
  return 0;
}
