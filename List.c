//#include <stdint.h>
//#include <stdlib.h>
#include "List.h"


uint32_t count_list_uint32(nodeUInt32_t *head)
{
    nodeUInt32_t *current = head;
     uint32_t count = 1;
    while (current->next != NULL) { // iterate to end of list
        current = current->next;
        count++;
    }

    return count;
}

nodeUInt32_t *create_list_uint32(uint32_t number)
{
    nodeUInt32_t *head = NULL;
    head = (nodeUInt32_t*) malloc(sizeof *head);
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else {
        head->next = NULL;
        head->number = number;
        return head;
    }
}

nodeInt64_t *create_list_int64(int64_t number)
{
    nodeInt64_t *head = NULL;
    head = (nodeInt64_t*)malloc(sizeof * head);
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else {
        head->next = NULL;
        head->number = number;
        return head;
    }
}

listInt64_t* create_list_list_int64(nodeInt64_t *element)
{
    listInt64_t *head = NULL;
    head = (listInt64_t*) malloc(sizeof * head);
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else {
        head->list = element;
        head->next = NULL;

        return head;
    }
}

uint8_t free_list_uint32(nodeUInt32_t *head)
{
    nodeUInt32_t *current = head;
    nodeUInt32_t *next = current->next;

    while (next != NULL)
    {
        free(current);
        current = next;
        next = current->next;
    }
    free(current);

    return EXIT_SUCCESS;
}

uint8_t free_list_int64(nodeInt64_t *head)
{
    nodeInt64_t *current = head;
    nodeInt64_t *next = current->next;

    while (next != NULL)
    {
        free(current);
        current = next;
        next = current->next;
    }
    free(current);

    return EXIT_SUCCESS;
}

uint8_t free_list_list_int64(listInt64_t *head)
{
    listInt64_t *current = head;
    listInt64_t *next = current->next;

    while (next != NULL)
    {
        free_list_int64(current->list);
        free(current);
        current = next;
        next = current->next;
    }
    free_list_int64(current->list);
    free(current);

    return EXIT_SUCCESS;
}

uint8_t push_uint32(nodeUInt32_t *head, uint32_t number)
{
    nodeUInt32_t *current = head;
    while (current -> next != NULL) { // iterate to end of list
        current = current -> next;
    }

    nodeUInt32_t *ptrNode = NULL;
    ptrNode = (nodeUInt32_t*) malloc(sizeof *ptrNode );
    if (ptrNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else {
        current->next = ptrNode;
        current = current->next;
        current->number = number;
        current->next = NULL;

        return EXIT_SUCCESS;
    }
}

uint8_t push_int64(nodeInt64_t *head, int64_t number)
{
    nodeInt64_t *current = head;
    while (current->next != NULL) { // iterate to end of list
        current = current->next;
    }

    nodeInt64_t *ptrNode = NULL;
    ptrNode = (nodeInt64_t*) malloc(sizeof *ptrNode );
    if (ptrNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else {
        current->next = ptrNode;
        current = current->next;
        current->number = number;
        current->next = NULL;

        return EXIT_SUCCESS;
    }
}

uint8_t push_list_int64(listInt64_t *head, nodeInt64_t *list)
{
    listInt64_t *current = head;
    while (current->next != NULL) { // iterate to end of list
        current = current->next;
    }

    listInt64_t *ptrNode = NULL;
    ptrNode = (listInt64_t*) malloc(sizeof *ptrNode);
    if (ptrNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else {
        current->next = ptrNode;
        current = current->next;
        current->list = list;
        current->next = NULL;

        return EXIT_SUCCESS;
    }
}

uint8_t print_list_uint32(nodeUInt32_t *head)
{
    if (head == NULL)
    {
        return EXIT_FAILURE;
    }
    else 
    {
        nodeUInt32_t *current = head;
        printf("{ ");
        printf("%d", current->number);
        while (current->next != NULL)
        {
            current = current->next;
            printf(", %d", current->number);
        }
        printf(" }");
        return EXIT_SUCCESS;
    }
}

uint8_t print_list_int64(nodeInt64_t *head)
{
    if (head == NULL)
    {
        return EXIT_FAILURE;
    }
    else
    {
        nodeInt64_t *current = head;
        printf("{ ");
        printf("%lld", current->number);
        while (current->next != NULL)
        {
            current = current->next;
            printf(", %lld", current->number);
        }
        printf(" }");
        return EXIT_SUCCESS;
    }
}

uint8_t print_list_list_int64(listInt64_t *head)
{
    {
        if (head == NULL)
        {
            return EXIT_FAILURE;
        }
        else
        {
            listInt64_t *current = head;
            printf("{ ");
            print_list_int64(current->list);
            while (current->next != NULL)
            {
                current = current->next;
                printf(", ");
                print_list_int64(current->list);
            }
            printf(" }");
            return EXIT_SUCCESS;
        }
    }
}