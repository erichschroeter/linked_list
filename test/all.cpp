#include <string.h>

#include <linked_list.h>

#define NODE_COUNT 3

int main(int argc, char **argv)
{
    int i;
    struct linked_list list;
    struct linked_list_node nodes[NODE_COUNT];
    int data[NODE_COUNT];

    // Initialize all the nodes to known memory.
    memset(nodes, 0, sizeof(nodes));

    // Add a bunch of nodes.
    for (i = 0; i < NODE_COUNT; i++)
    {
        // Set data to something unique.
        data[i] = i;
        nodes[i].Data = &data[i];
        linked_list_insert(&list, &nodes[i], i);
    }

    return 0;
}
