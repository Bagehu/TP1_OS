/* Lab 1 - Bastien HUBERT */

#ifndef __IPLOT_H__
#define __IPLOT_H__

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int* askForBoundaries();
int writeCommands(int* boundaries);
void manage_parent(int* boundaries);
void manage_child();
  
#endif
  
