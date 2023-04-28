#include <libgeometry/func.h>

int main()
{
    FILE* file;
    file = fopen("../input.txt", "r");
    if (file == NULL) 
	{
        printf("Can't oppening the file");
        return 1;
    }
    char str[N];
    
    while (fgets(str, N, file)) 
	{
        finaler(str);
    }
    fclose(file);
    
    return 0;
   
}

