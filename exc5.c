#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("exc5.txt", "r");

    if (file == NULL) {

        perror("File error opening");

        return 1;
    }

    fseek(file, 0, SEEK_END); // Переходим в конец файла
    long file_size = ftell(file); // Получение текущей позиции
    rewind(file); // Возвращение в начало файла

    char *buffer = (char *)malloc(file_size + 1); // Выделение памяти под инфу из файла
    
    if (buffer == NULL) {

        perror("Memory error");

        return 1;
    }

    size_t result = fread(buffer, 1, file_size, file); // Считываем инфу из файла в буффер 

    if (result != file_size) {

        perror("File reading error");
        free(buffer);

        return 1;
    }

    fclose(file);

    char buffer2[256];

    printf("Введите строку: "); // Просим пользователя ввести строку 
    fgets(buffer2, sizeof(buffer2), stdin); // Считываем строку во второй буффер 

    file = fopen("exc5.txt", "w"); // Открываем файл для записи
    fprintf(file, "%s", buffer2); // Заисываем вверх файла то что ввел пользователь
    fprintf(file, "%s", buffer); // Записывем исходную информацию ниже того, что ввел пользователь
    printf("Запись в файл успешно выполнена!\n");

    fclose(file);

    free(buffer);
    
    return 0;
}