#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct word_copies {
    size_t count;  // how many we have.
    char buffer[12];
};

typedef struct word_copies word;

int main(void) {
    char buffer[1024];
    FILE *stream;
    stream = fopen("black.txt", "r");
    int count = fread(&buffer, sizeof(char), sizeof(buffer), stream);
    fclose(stream);
    // we create an array or word structs, to store each word in. for
    // calculations.
    word *array_words;
    array_words = (word *)malloc(count * sizeof(word));
    size_t j = 0;
    // keep track of word count.
    size_t word_count = 0;


    for (size_t i = 0; i <= (size_t) count; i++) {
        // if we encounter, a ' ' store everything before it into a new instance of word.
        if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\0') {
            if (j < i) {
		int string_comp_result = 1; // for strcomp
                size_t difference = i - j;
                char word_buf[difference + 1];
                strncpy(word_buf, &buffer[j], difference); // difference is how many chars to copy over.
		// null terminate word.
                word_buf[difference] = '\0';
		// looping through list of already had words, if it is equal increment that word by 1
		if (word_count > 0){
		    for (size_t d = 0; d < word_count; ++d){
			string_comp_result = strcmp(word_buf, array_words[d].buffer);
			if (string_comp_result == 0){
			    array_words[d].count += 1;
			    break;
			}
		    }
		}
		if (string_comp_result != 0){
		    strncpy(array_words[word_count].buffer, word_buf, sizeof(array_words[word_count].buffer));
		    array_words[word_count].count = 1;
		    word_count++;
		}
            }
            j = i + 1;  // move to the start of the next word
        }
    }

    for (size_t i = 0; i < word_count; i++) {
        printf("%ld -> %s, ", array_words[i].count ,array_words[i].buffer);
    }

    return 0;
}
