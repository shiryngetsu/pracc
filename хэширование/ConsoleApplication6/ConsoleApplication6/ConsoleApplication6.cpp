#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TABLE_SIZE 1000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(int key) {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Возвращаем -1, если элемент не найден
}

int main() {
    srand(time_t(NULL));
    memset(table, 0, sizeof(table));

    // Генерация случайных чисел и заполнение таблицы
    setlocale(LC_ALL, "Russian");
    printf("Сгенерированные числа:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        int key = rand() % 100;
        int value = rand() % 1000;
        printf("Ключ: %d, Значение: %d\n", key, value);
        insert(key, value);
    }

    // Выполняем поиск элемента
    int searchKey;
    printf("\nВведите ключ для поиска: ");
    scanf_s("%d", &searchKey);

    int result = search(searchKey);

    if (result != -1) {
        printf("Значение для ключа %d: %d\n", searchKey, result);
    }
    else {
        printf("Элемент с ключом %d не найден\n", searchKey);
    }

    return 0;
}