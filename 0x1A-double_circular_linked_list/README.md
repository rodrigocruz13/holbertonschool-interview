# 0x1A. Double Circular Linked List

## Specializations - Interview Preparation ― Algorithms

![insert](https://i.imgur.com/J7zGZ4S.png)

## Tasks

Create the source file 0-add_node.c that contains the following functions:

- Add a new node to the end of a double circular linked list:
Prototype: List *add_node_end(List **list, char *str);
List: the list to modify
str: the string to copy into the new node
Returns: Address of the new node, or NULL on failure

- Add a new node to the beginning of a double circular linked list:
Prototype: List *add_node_begin(List **list, char *str);
List: the list to modify
str: the string to copy into the new node
Returns: Address of the new node, or NULL on failure

```bash
$cat 0-main.c
```

```C
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
    List *tmp;

    tmp = list;
    while (tmp)
    {
        printf("%s\n", tmp->str);
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
        if (tmp == list)
            break;
    }
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    List *list;

    list = NULL;
    add_node_end(&list, "Holberton");
    add_node_end(&list, "School");
    add_node_end(&list, "Full");
    add_node_end(&list, "Stack");
    add_node_end(&list, "Engineer");

    printf("Added to the end:\n");
    print_list(list);
    list = NULL;
    add_node_begin(&list, "Holberton");
    add_node_begin(&list, "School");
    add_node_begin(&list, "Full");
    add_node_begin(&list, "Stack");
    add_node_begin(&list, "Engineer");

    printf("Added to the beginning:\n");
    print_list(list);
    return (0);
}
```

```bash
$gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
```

```bash
$ ./a.out
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```
