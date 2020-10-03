#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd, fd2;
  fd = open("output.txt", O_RDONLY);
  fd2 = open("output2.txt", O_CREAT | O_WRONLY, 0644);
  char c;
  int filesize;
  
  filesize = lseek(fd, 0, SEEK_END);

  for (int i = filesize - 1; i >= 0; i--) {
    lseek(fd, i, SEEK_SET);
    read(fd, &c, 1);
    write(fd2, &c, 1);
    printf("%c", c);
 
  }
  

  
  close(fd);
  close(fd2);
}
