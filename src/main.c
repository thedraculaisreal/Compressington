#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct word {
    int count; // how many we have.
    char buffer[15];
};

typedef struct word word;

int main(void){
    char buffer[1024];
    FILE *stream;
    stream = fopen("black.txt", "r");
    int count = fread(&buffer, sizeof(char), sizeof(buffer), stream);
    fclose(stream);
    // we create an array or word structs, to store each word in. for calculations.
    word *array_words;
    array_words = (word*)malloc(count * sizeof(word));
    int j = 0;
    // keep track of word count.
    int word_count = 0;

    for (int i = 0; i <= count; i++) {
	// if we encounter, a ' ' store everything before it into a new instance of word.
        if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\0') {
            if (j < i) {
                int difference = i - j;
                char word_buf[difference + 1];
                strncpy(word_buf, &buffer[j], difference);
                word_buf[difference] = '\0'; // null terminate word.
		// copy everything but null terminator
                strncpy(array_words[word_count].buffer, word_buf, sizeof(array_words[word_count].buffer) - 1);
                array_words[word_count].buffer[sizeof(array_words[word_count].buffer)] = '\0'; // add null terminator to end
                word_count++;
		// have to always null terminate or rjust doesnt work idk why :C.
            }
            j = i + 1; // move to the start of the next word
        }
    }

    printf("WORDCOUNT = %d\n", word_count);
    for(int i = 0; i < word_count; i++){
	printf("%s, ", array_words[i].buffer);
    }
    printf("number of chars: %d\n", count);
    return 0;
}
