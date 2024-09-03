#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char value[20];
    struct node *next;
} node, *list;

void create_list(list *lst, char val[20])
{
    *lst = (list)malloc(sizeof(node));

    if (*lst == NULL)
        exit(1);

    (*lst)->value = val;
    (*lst)->next = NULL;
    return;
}

void insert_first(list *lst, char val[20])
{
    if (*lst == NULL)
        return create_list(lst, val);

    list new = (list)malloc(sizeof(node));

    if (new == NULL)
        exit(1);

    new->value = val;
    new->next = *lst;
    *lst = new;
}

float remove_first(list *lst)
{
    if (*lst == NULL)
        exit(1);

    list first = *lst;

    char val = (*lst)->value;
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

    insert_first(&lst, "ana");
    insert_first(&lst, "bruno");
    insert_first(&lst, "daniel");

    print_list(lst);

    printf("Item removido: %.1f\n", remove_first(&lst));

    print_list(lst);
}
