// program to add a word to a file
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;

  fp = fopen("output.txt", "w");
  int a = 8;
  int b = 2;
  // fprintf(fp,"writing out info to the file: %d + %d = %d\n",a,b,a+b);
  fprintf(fp, "%d\t%d\n%d\n", a, b, a + b);
  fclose(fp);

  fp = fopen("output.txt", "r");
  int c, d, e;
  //   fscanf(fp, "%d\t%d\n", &c, &d);
  //   fscanf(fp, "%d", &e);

  // fscanf(fp,"%d %d\n",&c,&d);
  // fscanf(fp,"%d",&e);

  fscanf(fp, "%d%d%d", &c, &d, &e);
  fclose(fp);

  printf("c=%d, d=%d, e=%d\n", c, d, e);
}
/** I think it is the same whenever I comment lines 18-19 and uncomment lines
 * 21-22, or comment line 21-22 and uncomment 18-19**/
/**The result is also the same as before, when I comment lines 18-19 (and 21-22)
 * and uncomment line 24**/