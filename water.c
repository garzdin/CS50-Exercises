#include <stdio.h>

int main(void){
  int minutes;
  int bottles_per_minute = 12;
  printf("minutes: ");
  do {
    scanf("%i", &minutes);
  } while(minutes <= 0);
  printf("bottles: %i\n", bottles_per_minute * minutes);
  return 0;
}
