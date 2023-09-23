#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char buffer[100];
    printf("Input file name: ");
    fgets(buffer, sizeof(buffer), stdin);

    size_t length = strlen(buffer);

    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }

    FILE *file = fopen(buffer, "r");

    if (file == NULL) {

        perror("Openning file error ");

        return 1;
    }

    fseek(file, 0, SEEK_END); // Перемещение в конец файла
    long file_size = ftell(file); // Получение текущей позиции
    rewind(file); // Возвращаемся в начало файла

    char *buffer1 = (char *)malloc(file_size + 1); // Выделение памяти под хранение инфы из файла

    if (buffer1 == NULL) {

        perror("Memory error");
        free(buffer1);

        return 1;
    }

    size_t result = fread(buffer1, 1, file_size, file);

    if (result != file_size) {

        perror("Reading file error");
        free(buffer1);

        return 1;
    }

    buffer1[file_size] = '\0';

    fclose(file);

    printf("Данные считанные с файла: \n%s\n", buffer1);

    free(buffer1);

    return 0;

}