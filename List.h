#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

// This line is necessary to inform the compiler of the type, 
// which allows to recursively call the struct in it's own type definition
typedef struct nodeUInt32 nodeUInt32_t;
/// <summary>
/// Data structure of a list, with each node containing a number
/// </summary>
typedef struct nodeUInt32 {
    uint32_t number;
    nodeUInt32_t* next;
} nodeUInt32_t;

// This line is necessary to inform the compiler of the type, 
// which allows to recursively call the struct in it's own type definition
typedef struct nodeInt64 nodeInt64_t;
/// <summary>
/// Data structure of a list, with each node containing a number
/// </summary>
typedef struct nodeInt64 {
    int64_t number;
    nodeInt64_t *next;
} nodeInt64_t;

/// <summary>
/// Data structure of a list of lists, with each node containing a list of integers
/// </summary>
typedef struct listInt64 listInt64_t;
typedef struct listInt64 {
    nodeInt64_t *list;
    listInt64_t *next;
} listInt64_t;



/// <summary>
/// Counts the nodes of a specified list. 
/// </summary>
/// <param name="head">The first node of the list.</param>
/// <returns>Number of nodes in the specified list.</returns>
 uint32_t count_list_uint32(nodeUInt32_t *head);
 /// <summary>
 /// Creates a list of integers.
 /// </summary>
 /// <param name="number">First number to be added to the list.</param>
 /// <returns>Head-Node of the new created list.</returns>
 nodeUInt32_t* create_list_uint32(uint32_t number);
 /// <summary>
/// Creates a list of integers.
/// </summary>
/// <param name="number">First number to be added to the list.</param>
/// <returns>Head-Node of the new created list.</returns>
 nodeInt64_t* create_list_int64(int64_t number);
 /// <summary>
/// Creates a list of lists of integers.
/// </summary>
/// <param name="number">First list to be added to the list of lists.</param>
/// <returns>Head-Node of the new created list of lists.</returns>
 listInt64_t* create_list_list_int64(nodeInt64_t *element);
 /// <summary>
/// Deallocates the memory space of a specified list. 
/// </summary>
/// <param name="head">The first node of the list.</param>
/// <returns>EXIT_SUCCESS iff the deallocation was successful.</returns>
 uint8_t free_list_uint32(nodeUInt32_t *head);
 /// <summary>
/// Deallocates the memory space of a specified list. 
/// </summary>
/// <param name="head">The first node of the list.</param>
/// <returns>EXIT_SUCCESS iff the deallocation was successful.</returns>
 uint8_t free_list_int64(nodeInt64_t *head);
 /// <summary>
/// Deallocates the memory space of a specified list. 
/// </summary>
/// <param name="head">The first node of the list.</param>
/// <returns>EXIT_SUCCESS iff the deallocation was successful.</returns>
 uint8_t free_list_list_int64(listInt64_t *head);
 /// <summary>
/// Adds a specified number at the end of the list. 
/// </summary>
/// <param name="head">The first node of the list.</param>
/// <param name="number">Number to add.</param>
/// <returns>EXIT_SUCCESS iff the operation was successful.</returns>
 uint8_t push_uint32(nodeUInt32_t* head, uint32_t number);
 /// <summary>
/// Adds a specified number at the end of the list. 
/// </summary>
/// <param name="head">The first node of the list.</param>
/// <param name="number">Number to add.</param>
/// <returns>EXIT_SUCCESS iff the operation was successful.</returns>
 uint8_t push_int64(nodeInt64_t *head, int64_t number);
 /// <summary>
 /// Adds a specified list at the end of the list of lists
 /// </summary>
 /// <param name="head">The first node of the list of lists.</param>
/// <param name="list">List to add.</param>
/// <returns>EXIT_SUCCESS iff the operation was successful.</returns>
 uint8_t push_list_int64(listInt64_t *head, nodeInt64_t *list);
 /// <summary>
 /// Prints the specified list on the standard output stream.
 /// </summary>
 /// <param name="head">Head of the list to print.</param>
 /// <returns>EXIT_SUCCESS iff the operation was successful.</returns>
 uint8_t print_list_uint32(nodeUInt32_t *head);
 /// <summary>
 /// Prints the specified list on the standard output stream.
 /// </summary>
 /// <param name="head">Head of the list to print.</param>
 /// <returns>EXIT_SUCCESS iff the operation was successful.</returns>
 uint8_t print_list_int64(nodeInt64_t *head);
 /// <summary>
 /// Prints the specified list of lists on the standard output stream.
 /// </summary>
 /// <param name="head">Head of the list of lists to print.</param>
 /// <returns>EXIT_SUCCESS iff the operation was successful.</returns>
 uint8_t print_list_list_int64(listInt64_t *head);

#endif
