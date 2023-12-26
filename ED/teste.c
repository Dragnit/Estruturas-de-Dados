#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float value;
    struct node *next;
} node, *list;

void mem_error()
{
    perror("Not enough memory");
    exit(1);
}

void create_list(list *lst, float val)
{
    *lst = (list)malloc(sizeof(node));

    if (*lst == NULL)
        mem_error();

    (*lst)->value = val;
    (*lst)->next = NULL;
    return;
}

void insert_last(list *lst, float val)
{
    if (*lst == NULL)
        return create_list(lst, val);

    // A lista nao e vazia
    list head = *lst;

    while (head->next != NULL)
        head = head->next;

    list new = (list)malloc(sizeof(node));

    if (new == NULL)
        mem_error();

    new->value = val;
    new->next = NULL;

    head->next = new;
}

void insert_first(list *lst, float val)
{
    if (*lst == NULL)
        return create_list(lst, val);

    list new = (list)malloc(sizeof(node));

    if (new == NULL)
        mem_error();

    new->value = val;
    new->next = *lst;
    *lst = new;
}

float remove_last(list *lst)
{
    if (*lst == NULL)
        mem_error();

    list head = *lst;
    list prev = NULL;

    while (head->next != NULL) {
        prev = head;
        head = head->next;
    }

    if (prev != NULL)
        prev->next = NULL;
    else
        *lst = NULL;

    float val = head->value;
    free(head);

    return val;
}

float remove_first(list *lst)
{
    if (*lst == NULL)
        mem_error();

    list first = *lst;

    float val = (*lst)->value;
    *lst = (*lst)->next;

    free(first);

    return val;
}

void print_list(list lst)
{
    printf("[ ");
    while (lst->next != NULL)
    {
        printf("%.1f, ", lst->value);
        lst = lst->next;
    }
    printf("%.1f ]", lst->value);
    printf("\n");
}

void main()
{
    list lst = (list)NULL;

    insert_last(&lst, 12.3);
    insert_last(&lst, 45.6);
    insert_last(&lst, 78.9);

    insert_first(&lst, -12.3);

    print_list(lst);

    printf("%.1f\n", remove_last(&lst));

    print_list(lst);

    printf("%.1f\n", remove_first(&lst));

    print_list(lst);
}
