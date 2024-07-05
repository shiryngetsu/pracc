#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ARRAY_SIZE 1000

int main() {
    int arr[ARRAY_SIZE];
    int key, found = 0;

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение массива случайными числами
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;  // Генерируем случайное число от 0 до 99
    }

    // Вывод сгенерированного массива
    setlocale(LC_ALL, "Russian");
    printf("Сгенерированный массив:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Запрашиваем у пользователя ключ для поиска
    printf("Введите ключ для поиска: ");
    scanf_s("%d", &key);

    // Выполняем поиск методом перебора
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == key) {
            printf("Элемент %d найден в массиве на позиции %d\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Элемент %d не найден в массиве\n", key);
    }
    system("pause");

    return 0;
}