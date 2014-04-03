#include <stdio.h>

int main () {
  int i = 0, j = 0;
  bool flag;
  for (i = 2520; true; i++) {
    flag = true;
    for (j = 1; j < 20; j++) {
      if ( !(i % j == 0) ) {
	flag = false;
	break;
      }
    }
    if (flag) {
      cout << i << endl;
    }
  }
}
