#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFFSIZE 4096

int main (int argc, char **argv)
{
  int src_fd, dest_fd, src_flags, dest_flags, char_count;
  char *src_file = NULL;
  char *dest_file = NULL;
  mode_t dest_perms;
  char buf[BUFFSIZE];

  src_file = argv[1];
  dest_file = argv[2];
  src_flags = O_RDONLY;
  dest_flags = O_CREAT | O_WRONLY | O_TRUNC;
  dest_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;	/*rw-rw-rw */
  src_fd = open (src_file, src_flags);
  if (src_fd == -1)
    {

      perror ("Can't open source file");
      return -1;

    }
  dest_fd = open (dest_file, dest_flags, dest_perms);
  if (dest_fd == -1)
    {

      perror ("Can't open destination file");
      return -1;
    }
  while ((char_count = read (src_fd, buf, BUFFSIZE)) > 0)
    {
      if (write (dest_fd, buf, char_count) != char_count)
	{
	  fprintf (stderr, "Failed to write");
	  return -1;

	}

    }
  if (char_count == -1)
    {
      fprintf (stderr, "Failed to read");
      return -1;

    }
  close (src_fd);
  close (dest_fd);
  printf ("Successfull Copy\n");




return 0;




}
