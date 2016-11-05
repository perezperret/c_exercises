#include <stdio.h>

/* Count chars in input */

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
      ;

    printf("%.0f\n", nc);
}
