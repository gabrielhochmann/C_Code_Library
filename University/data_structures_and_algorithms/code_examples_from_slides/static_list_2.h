/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 28, 2024
 File        : static_list_2.h
 Source      : List in C (data structure) - Professor Rômulo Silva;
 Description : This file contains the header for a static list implementation in c.
 ========================================================================================
 */

#ifndef STATIC_LIST_2_H
#define STATIC_LIST_2_H

#define MAX_SIZE 1000 // Maximum number of Items in the static List

// ItemType represents the type of elements in the list. In this case, it's an int.
typedef int ItemType;

// Structure to a static list. Insertions are always made at the last free position.
// To delete an element at position i, all elements from position i+1 onwards are shifted left.
typedef struct
{
    ItemType items[MAX_SIZE]; // Array to store the elements of the list
    int first, last;          // 'first' is the index of the first element, 'last' is the index of the first free position after the last element
    int position;             // Used to navigate through the list
} StaticList;

/**
 * @brief Creates an empty static list.
 *
 * @return A pointer to the newly created empty static list.
 */
StaticList *create_empty_list();

/**
 * @brief Checks if the static list is empty.
 * 
 * @param list A pointer to the static list to check.
 * 
 * @return 1 if the list is empty, 0 otherwise.
*/
int is_empty(const StaticList *list);

/**
 * @brief Inserts an item into the static list.
 * 
 * The item is inserted at the next free positon. If the list is full, the item cannot be added.
 * 
 * @param list A pointer to the static list where the item will be inserted.
 * @param item The item to be inserted into the list.
 */
void insert(StaticList *list, ItemType item);

/**
 * @brief Retrieves the first item in the static list.
 * 
 * @param list A pointer to the static list.
 * 
 * @return The first item in the list.
 */
ItemType first_item(StaticList *list);

/**
 * @brief Retrieves the next item in the static list based on the current position.
 * 
 * @param list A pointer to the static list.
 * 
 * @return The next item in the list.
 */
ItemType next_item(StaticList *list);

/**
 * @brief Removes an item from the static list.
 * 
 * To remove an item, all elements following the item are shifted left to fill the gap.
 * 
 * @param list A pointer to the static list from which the item will be removed.
 * @param item The item to be removed from the list.
 */
void remove_item(StaticList *list, ItemType item);

/**
 * @brief Prints all items in the static list by iterating through each element.
 * 
 * This function simply iterates through the list from the first element to the last 
 * and prints each item.
 * 
 * @param list A pointer to the static list to be printed. 
*/
void print_list_1(StaticList *list);

/**
 * @brief Prints all items in the static list using the iterator functions 'first_item' and 'next_item'.
 * 
 * This function leverages the iterator functions to traverse the list and print each item.
 * 
 * @param list A pointer to the static list to be printed.
 */
void print_list_2(StaticList *list);

#endif // STATIC_LIST_2_H