/*
        formatting: C will format your variables however you tell it
*/
#include <limits.h> // includes some system constants like INT_MAX and INT_MIN
#include <stdio.h>


int main() {
  printf("maximum integer = %d, minimum integer = %d\n\n", INT_MAX, INT_MIN);

  int myint = 41;
  float myfloat = 16.23591;
  double mydouble = 39.172438103536;
  char mychar = 'n';
  unsigned myunsigned = 125;

  printf("printing all as int:\n");
  printf("myint = %d, myfloat = %d, mydouble = %d, mychar = %d\n", myint,
         (int)myfloat, (int)mydouble, mychar);

  union f2u {
    float f;
    double d;
    char c;
    unsigned u;
  };

  union f2u myfloat_u = {.f = myfloat};
  union f2u mydouble_u = {.d = mydouble};
  union f2u mychar_u = {.c = mychar};

  printf("printing all as char:\n");
  printf("myint = %c, myfloat = %c, mydouble = %c, mychar = %c\n", myint,
         (char)myfloat, (char)mydouble, mychar);

  printf("printing all as hex:\n");
  printf("myint = %X, myfloat = %x, mydouble = %x, mychar = %X\n", myint,
         myfloat_u.u, mydouble_u.u, mychar_u.u);

  printf("printing all with floating-point notation:\n");
  printf("myint = %f, myfloat = %f, mydouble = %f, mychar = %f\n", (float)myint,
         myfloat, mydouble, (float)mychar);

  printf("printing all with floating-point e-notation:\n");
  printf("myint = %e, myfloat = %e, mydouble = %e, mychar = %e\n", (float)myint,
         myfloat, mydouble, (float)mychar);

  printf("printing all with floating-point notation, decimals specified:\n");
  printf("myint = %.10f, myfloat = %.10f, mydouble = %.10f, mychar = %.10f\n",
         (float)myint, myfloat, mydouble, (float)mychar);

  printf("printing all with floating-point notation, with \" 9 \" precision and "
                                                              "maximum width "
                                                              "of the entire "
                                                              "number is 4.\n");
  printf("myint = %9.4f, myfloat = %9.4f, mydouble = %9.4f, mychar = %9.4f\n",
         (float)myint, myfloat, mydouble, (float)mychar);

  return 0;
}