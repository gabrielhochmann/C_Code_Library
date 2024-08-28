/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 28, 2024
 File        : static_list_1.c
 Source      : List in C (data structure) - Professor Rômulo Silva;
 Description : Implementation of static list data structure in c.
 ========================================================================================
 */

#include "static_list_1.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Creates an empty static list.
 *
 * @pre None.
 * @post A new empty list is created and initialized.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation fails.
 */
StaticList *create_empty_list()
{
    StaticList *new_list = (StaticList *)malloc(sizeof(StaticList));
    if (new_list == NULL)
    {
        perror("Failed to allocate memory for the list");
        return NULL;
    }
    new_list->free_position = 0;

    return new_list;
}

/**
 * @brief Checks if the list is empty.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post None.
 *
 * @param list A pointer to the StaticList structure.
 * @return 1 if the list is empty, 0 otherwise.
 */
int is_empty(const StaticList *list)
{
    return (list->free_position == 0);
}

/**
 * @brief  Inserts an item into the static list.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post The item is inserted into the list if it is not full.
 *
 * @param list A pointer to the StaticList structure.
 * @param item The item to be inserted into the list.
 */
void insert(StaticList *list, ItemType item)
{
    if (list == NULL)
    {
        fprintf(stderr, "NULL pointer provided to the list.\n");
        return;
    }

    if (list->free_position >= MAX_SIZE)
    {
        printf("List is full. Cannot insert new item.\n");
        return;
    }
    list->items[list->free_position++] = item;
}

/**
 * @brief Removes an item from the static list.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post The specified item is removed from the list if it exists.
 *
 * @param list A pointer to the StaticList structure.
 * @param item The item to be removed from the list.
 */
void remove_item(StaticList *list, ItemType item)
{
    if (list == NULL)
    {
        fprintf(stderr, "NULL pointer provided to the list.\n");
        return;
    }

    if (is_empty(list))
    {
        printf("Empty List: no elements to remove.\n");
        return;
    }

    int position = 0;

    // Find the position of the item in the list
    while (position < list->free_position && item != list->items[position])
    {
        position++;
    }

    if (position == list->free_position)
    {
        printf("Item not found in the list.\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < list->free_position - 1; i++)
    {
        list->items[i] = list->items[i + 1];
    }

    list->free_position--;
}

void print_list(StaticList *list)
{
    for (int i = 0; i < list->free_position; i++)
    {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}

