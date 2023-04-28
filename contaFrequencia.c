#include <stdio.h>

int main(int argc, char** argv) {
    int frequency[256] = {0};
    FILE *file;


    file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        frequency[byte]++;
    }

    fclose(file);

    printf("Letra:\tFrequencia:\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("%c\t%d\n", (char) i, frequency[i]);
        }
    }

    return 0;
}