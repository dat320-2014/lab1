#include <stdio.h>
int main(void)
{
#ifdef DEBUG
printf("Some smart debugcomment\n");
#endif
printf("Hello, world!\n");
return 0;
}

