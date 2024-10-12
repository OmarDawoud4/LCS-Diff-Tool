#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcs.h"

void read_file(const char *filename, char **buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = malloc(length + 1);
    fread(*buffer, 1, length, file);
    (*buffer)[length] = '\0';
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file1_content;
    char *file2_content;

    read_file(argv[1], &file1_content);
    read_file(argv[2], &file2_content);

    int len1 = strlen(file1_content);
    int len2 = strlen(file2_content);

    printf("Length of LCS: %d\n", lcs_length(file1_content, file2_content, len1, len2));
    print_lcs(file1_content, file2_content, len1, len2);

    free(file1_content);
    free(file2_content);

    return EXIT_SUCCESS;
}