#include <stdio.h>
#include <stdlib.h>

typedef struct numset
{
   unsigned long long int prime[10000];
   struct numset *next;
} set;

int getint()
{
   int power;
   scanf("%d", &power);
   return power;
}

int main(int argc, char *argv[])
{
   register set *head, *p, *q;
   register unsigned long long int n, last_num, *arr, no_prime, k ;
   register int m , i;
   register char ch;

   head = (set *)malloc(sizeof(set));
   head->next = NULL;
   p = head;

   printf("Enter the power of 10 for finding prime number in 0 to that range : ");
   m = getint();

   for (last_num = 10; m > 1; --m)
      last_num *= 10;

   for (n = 5, no_prime = 1, p->prime[0] = 3, m = 0; n < last_num; n += 2)
   {
      for (i = 0, ch = 'y', q = head, arr = head->prime; (arr[i] * arr[i]) <= n; ++i) // Find the prime number.
      {
         if ((n % (arr[i])) == 0)
         {
            ch = '\0';
            break;
         }
         if (i == 9999)
         {
            q = q->next;
            arr = q->prime;
            i = (-1);
         }
      }

      if (ch) // Store the find prime number.
      {
         ++no_prime;
         ++m;
         if (m == 10000)
         {
            p->next = (set *)malloc(sizeof(set));
            p = p->next;
            p->next = NULL;
            m = 0;
         }
         p->prime[m] = n;
      }
   }

   FILE *fptw; // Store the prime number in file.
   if (argc == 1)
      fptw = fopen("prime.txt", "a");
   else fptw = fopen(argv[1], "a"); 
   if (fptw == NULL)
   {
      printf("Error! for open the %s file.\n", argv[1]);
      exit(-1);
   }

   fprintf(fptw, "No of Prime number in between 0 to %llu is %llu.\n", last_num, no_prime + 1);
   fprintf(fptw, "Below the following prime number\n 2 ,\t\tdelt(prime)\t\tdelt_squr(prime)\n");
   for (k = 0, m = 0, q = head, n = 2,i=0; k < no_prime; ++k, ++m)
   {
      if (m == 10000)
      {
         p = q->next;
         free(q);
         q = p;
         arr = q->prime;
         m = 0;
      }
      n=(arr[m] - n);
      fprintf(fptw, " %llu ,\t\t%llu ,\t\t%d\n",arr[m],n,(n-i));
      i=n;
      n = arr[m];
   }
   free(q);
   fprintf(fptw, "number is finished.\n");
   fclose(fptw);
   printf("\ncomputation is finished.\n");

   return 0;
}