#include <stdio.h>
#include <stdlib.h>

typedef struct link{
 int n;
 struct link *next;
} string_node;

int main()
{
    printf("%d\n%d\n%d\n",sizeof(int ),sizeof(int *),sizeof(string_node ));
    return 0;
}
