#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int i = 9 ;
    printf("vaule of i =  %f \n %d\n",i,i);  // second part no print 9 exchane it print 4200891 ?
    i = i ;
    printf("value is i = %d\n",i);
    return 0;
 }