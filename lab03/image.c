#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Функция для загрузки изображения из файла
void load_image(const char* filename, uint8_t** image_data, int* width, int* height)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }

    // Чтение заголовка BMP файла
    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);
    fseek(file, 28, SEEK_CUR);

    // Выделение памяти для данных изображения
    *image_data = (uint8_t*)malloc((*width) * (*height) * 3);
    if (!(*image_data))
    {
        printf("Не удалось выделить память для изображения.\n");
        exit(1);
    }

    // Чтение данных изображения
    fread(*image_data, sizeof(uint8_t), (*width) * (*height) * 3, file);

    fclose(file);
}

// Функция для вывода изображения на экран
void display_image(uint8_t* image_data, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            uint8_t r = image_data[(y * width + x) * 3];
            uint8_t g = image_data[(y * width + x) * 3 + 1];
            uint8_t b = image_data[(y * width + x) * 3 + 2];

            printf("(%d, %d, %d) ", r, g, b);
        }
        printf("\n");
    }
}

int main()
{
    const char* filename = "image.bmp"; // Путь к файлу изображения
    uint8_t* image_data; // Данные изображения
    int width, height; // Ширина и высота изображения

    load_image(filename, &image_data, &width, &height);
    display_image(image_data, width, height);

    free(image_data); // Освобождаем память

    return 0;
}
