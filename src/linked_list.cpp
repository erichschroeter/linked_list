#include <assert.h>

#include "linked_list.h"

void linked_list_insert(struct linked_list *list, struct linked_list_node *node, int position)
{
    int i;
    struct linked_list_node *temp;
    struct linked_list_node *cursor;

    assert(list != NULL);
    assert(node != NULL);
    // TODO Add support for negative numbers to iterate backwards.
    assert(position >= 0);

    if (position > list->Size)
    {
        fprintf(stderr, "linked_list: position outside size boundary %d > %u\n",
            position, list->Size);
        return;
    }

    cursor = list->Head;

    // If the list is empty, simply add the first item.
    if (cursor == NULL)
    {
        list->Head = node;
        list->Size++;
        return;
    }

    // Iterate through the list to get to the position specified.
    for (i = 0; i < position; i++)
    {
        cursor = cursor->Next;

        if (cursor == NULL)
        {
            fprintf(stderr, "linked_list: break in the list\n");
            return;
        }
    }

    // The cursor is now pointing to the position we need to insert before.
    // Now update the pointers to the existing nodes.
    //
    // inserting [x]
    // [a]-->[b]-->[c]-->[d]...
    //              ^
    // cursor = [c]
    // [b].Next = [x]
    // [c].Prev = [x]
    //
    // [a]-->[b]-->[x]-->[c]-->[d]...

    // Set temp to [b]
    temp = cursor->Prev;
    // Update [b] to point to our new node.
    temp->Next = node;
    // Update [x] to point Prev to [b].
    node->Prev = temp;
    // Update [x] to point Next to [c].
    node->Next = cursor;
    // Update [c] to point to our new node.
    cursor->Prev = node;
}

void linked_list_remove(struct linked_list *list, struct linked_list_node *node)
{
    int i;
    struct linked_list_node *temp;
    struct linked_list_node *cursor;

    assert(list != NULL);
    assert(node != NULL);

    // Iterate through the list to get to find the position of the node.
    for (i = 0; i < list->Size; i++)
    {
        cursor = cursor->Next;

        if (cursor == NULL)
        {
            fprintf(stderr, "linked_list: break in the list\n");
            return;
        }

        if (cursor == node)
        {
            break;
        }
    }

    // The cursor is now pointing to the position we need to remove.
    // Now update the pointers to forget about the specified node.
    //
    // removing [c]
    // [a]-->[b]-->[c]-->[d]...
    //              ^
    // cursor = [c]
    // [b].Next = [d]
    // [d].Prev = [b]
    //
    // [a]-->[b]-->[d]...

    // Set temp to [b]
    temp = cursor->Prev;
    // Update [b] to forget about cursor.
    temp->Next = cursor->Next;
    // Update [d] to forget about cursor.
    cursor->Next = temp;
}
