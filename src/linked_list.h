#ifndef ___LINKED_LIST_H
#define ___LINKED_LIST_H

struct linked_list_node
{
    struct linked_list_node *Next;
    struct linked_list_node *Prev;
    void *Data;
};

struct linked_list
{
    unsigned int Size;
    struct linked_list_node *Head;
    struct linked_list_node *Tail;
};

void linked_list_insert(struct linked_list *list, struct linked_list_node *node, int position);
void linked_list_remove(struct linked_list *list, struct linked_list_node *node);

#endif /* ___LINKED_LIST_H */
