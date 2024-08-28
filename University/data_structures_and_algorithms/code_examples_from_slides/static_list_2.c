/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 28, 2024
 File        : static_list_2.c
 Source      : List in C (data structure) - Professor Rômulo Silva;
 Description : Implementation of static list data structure in c.
 ========================================================================================
 */

#include "static_list_2.h"
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

    new_list->first = 0;
    new_list->last = 0;
    new_list->position = -1;

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
    return (list->first == list->last);
}

/**
 * @brief Returns the first item in the list.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post The internal position is reset to the start of the list.
 *
 * @param list A pointer to the StaticList structure.
 * @return The first item in the list
 */
ItemType first_item(StaticList *list)
{
    list->position = list->first - 1;
    return next_item(list);
}

/**
 * @brief Returns the next item in the list
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post The internal position is incremented.
 *
 * @param list A pointer to the StaticList structure.
 * @returns The next item in the list, or -1 if the end of the list is reached.
 */
ItemType next_item(StaticList *list)
{
    list->position++;
    if (list->position >= list->last)
    {
        return -1; // End of the list
    }
    else
    {
        return list->items[list->position];
    }
}

/**
 * @brief  Inserts an item into the static list.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post The item is inserted into the list if there is space.
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

    if (list->last >= MAX_SIZE)
    {
        printf("List is full. Cannot insert new item.\n");
        return;
    }
    list->items[list->last++] = item;
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

    int position = list->first;

    // Find the position of the item in the list
    while (position < list->last && item != list->items[position])
    {
        position++;
    }

    if (position == list->last)
    {
        printf("Item not found in the list.\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < list->last - 1; i++)
    {
        list->items[i] = list->items[i + 1];
    }

    list->last--;
}

/**
 * @brief Prints the items in the list.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post None.
 *
 * @param list A pointer to the StaticList structure.
 */
void print_list_1(StaticList *list)
{
    if (is_empty(list))
    {
        printf("Empty List.\n");
    }
    else
    {
        printf(" [");
        for (int i = list->first; i < list->last; i++)
        {
            printf("%d ", list->items[i]);
        }
        printf("]\n");
    }
}

/**
 * @brief Prints the items in the list using iterator functions.
 *
 * @pre A non-NULL pointer to a StaticList structure.
 * @post None.
 *
 * @param list A pointer to the StaticLista structure.
 */
void print_list_2(StaticList *list)
{
    if (is_empty(list))
    {
        printf("Empty List.\n");
    }
    else
    {
        ItemType item = first_item(list);
        printf(" [");

        while (item != -1)
        {
            printf("%d ", item);
            item = next_item(list);
        }
        printf("]\n");
    }
}