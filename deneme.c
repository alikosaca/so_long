# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("den.txt", O_RDONLY);
    int i;
    char c;
    i = 0;
    if (!fd)
        return (1);

    while (read(fd, &c, 1))
    {
        if (c == '\n')
            printf("\nyazdı\n");
        printf("%c", c);
    }
    
}