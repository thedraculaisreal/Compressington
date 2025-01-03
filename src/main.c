#include <stdio.h>
#include <stdbool.h>

int main(void){
    char buffer[1024];
    FILE *stream;
    stream = fopen("black.txt", "r");
    int count = fread(&buffer, sizeof(char), sizeof(buffer), stream);
    fclose(stream);

    for(int i = 0; i <= count; i++){
	printf("%c, ", buffer[i]);
    }
    printf("number of chars: %d\n", count);
    return 0;
}
