#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x);

int main() {

  float a, b,delta, x,step,f_out;
  int N, num;
  float **input_tabl = NULL, **binary= NULL;
  char group_name[6], student_name[20];

  FILE *input, *output, *filebinary;

  input = fopen("input.txt", "r");
  output = fopen("output.txt", "w");
  filebinary = fopen("filebinary.bin", "w+b");


  while (num = getc(input) != '\n');
  putchar(num);
    fscanf(input,  " %f %f %d %s %s ", &a, &b, &N, &step, &group_name);
    fgets(&student_name, 20, input);
if(delta==0)
{
   delta = (b - a) / (N - 1);
}

  if (N == 0)
  {
        delta==step;
   N=((b-a)/delta)+1;
  }

  input_tabl = (int**)calloc(N, sizeof(int));
  binary = (int**)calloc(N, sizeof(int));
  for (int i = 0; i < N; i++) {
    input_tabl[i] = (int*)calloc(3, sizeof(int));
    binary[i] = (int*)calloc(3, sizeof(int));
  }


  printf("y=-0.5*pow((x-64),3)-3*pow(x,2)+10\n X1= %.0f\n X2= %.0f\n N= %d\n Delta= %.1f\n group = %s\n name = %s\n\n", a, b, N, delta, group_name, student_name);
  for (int i = 0; i < N; i++)
    {
    a += delta;
    x = a;
    input_tabl[i][0] = i + 1;
    input_tabl[i][1] = x;
    input_tabl[i][2] = func(input_tabl[i][1]);
  }


    fprintf(output, " N  \tx   f(x)\n");
    for (int i = 0; i < N; i++) {
    fprintf(output, "  %5.0f", input_tabl[i][0]);
    for (int j = 1; j < 3; j++) {
    fprintf(output, "  %5.1f", input_tabl[i][j]);
    }
    fprintf(output, "\n");
  }


    fwrite(&N, sizeof(int), 1, filebinary);
    for (int i = 0; i < N; i++) {
    for (int j = 1; j < 3; j++) {
      fwrite(&input_tabl[i][j], sizeof(float), 1, filebinary);
    }
  }
  fclose(filebinary);


  filebinary = fopen("filebinary.bin", "r+b");
  printf("\n***************************************");
  printf("\n*     N     *     X      *     F(X)   *");
  printf("\n***************************************");
  fread(&N, sizeof(int), 1, filebinary);
  printf("\n\n", N);
  for (int i = 0; i < N; i++) {
    int f = i+1;
    printf("|%11.0d|", f);
    for (int j = 1; j < 3; j++) {
      fread(&f_out, sizeof(float), 1, filebinary);

      printf(  "%12.f|",f_out);
    }
    printf("\n\n");
  }

  printf( "| %s %s                 |\n", group_name, student_name, f_out );

  printf("\n|-----------|------------|------------|\n");



  fclose(input);
  fclose(output);
  fclose(filebinary);
}
double func(double x) {
  return -0.5*pow((x-64),3)-3*pow(x,2)+10;
}
