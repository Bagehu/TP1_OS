/* TP1 - Bastien HUBERT */

#include "iplot.h"

int main() {
  pid_t pid;
  int* boundaries = calloc(2, sizeof(int));

  while(1) {
    boundaries = askForBoundaries();
    pid = fork();
    if(pid < 0) {
      exit(EXIT_FAILURE);
    }
    else if(pid > 0) {
      manage_parent(boundaries);
    }
    else {
      manage_child();
    }
    
  }
  /*
  printf("Lower boundary is %d, and the higher boundary is %d\n", boundaries[0], boundaries[1]);
  */
  free(boundaries);
  return 0;
}
