#include <stdio.h>
#include <stdlib.h>

void solve();

int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    scanf("%d",&t);
    while(t--) solve();
    
    return 0;
}

void solve()
{
    printf("Hello world\n");
    return ;
}