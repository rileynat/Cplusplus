#include <stdio.h>

int main () {
	int i = 2520;
	int flag = 1;
	int j = 1;
  for (i = 2520; 1; i++) {
    flag = 1;
    for (j = 1; j < 20; j++) {
      if ( !(i % j == 0) ) {
	flag = 0;
	break;
      }
    }
    if (flag) {
      printf("%d", i);
    }
  }
}
