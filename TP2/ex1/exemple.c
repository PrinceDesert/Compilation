#include <stdio.h>

// Une variable globale
int g;

int fact(int a);
int ack(int m, int n);

int fact(int a) {
  if (a==0)
    return g;
  else
    return a*fact(a-1);
}

int ack(int m, int n) {
    if (m==0)
       { return n+1; }
    if (n==0)
       return ack(m-1,1);
    return ack(m-1,ack(m,n-1));
}

// La fonction main est obligatoire pour faire un programme
int main() {
  printf ("Hello gentle world!\n");
  g=1;
  printf ("fact(5)=");
  printf ("%d", fact(5));
  printf ("\n"); // Affichage: fact(5)=120
  g=3;
  printf ("fact(5)=");
  printf ("%d", fact(5));
  printf ("\n"); // Affichage: fact(5)=360
  printf ("%d", 1+2*3==6+2);
  printf ("\n"); // Affichage: false
  printf ("ack(3,2)=");
  printf ("%d", ack(3,2));
  printf ("\n"); // Affichage: ack(3,2)=29
  printf ("Goodbye cruel world!\n");
  return 0;
}
