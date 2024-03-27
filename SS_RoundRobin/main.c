#include "main.h"

int main()
{
    SS_RoundRobin *queue = NULL;

    Initialize_SS_RoundRobin_1(&queue);

    Print_SS_RoundRobin(queue);

    Terminal target1 = {2, 22};
Terminal target2 = {5, 55};

    printf("This node is%spresent\n", isTerminalPresent(target1, queue) ? " " : " not ");
    printf("This node is%spresent\n", isTerminalPresent(target2, queue) ? " " : " not ");

    removeTerminal(target1, &queue);
    printf("\n after removeTerminal");
    Print_SS_RoundRobin(queue);

    free(queue);

    return 0;
}

void Initialize_SS_RoundRobin(SS_RoundRobin **queue)
{
    int num_nodes; // Number of nodes in the queue

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++)
    {
        SS_RoundRobin *new_node = malloc(sizeof(SS_RoundRobin));
        if (!new_node) // Check if memory allocation is successful
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter direction (0-255): "); // Get direction
        scanf("%hhu", &new_node->myTerm.direction);

        printf("Enter address (0-65535): "); // Get address
        scanf("%hu", &new_node->myTerm.address);

        new_node->nextOne = NULL; // Set next node to NULL

        if (!*queue) // Check if queue is empty
        {
            *queue = new_node; // If empty, set new node as the head of the queue
        }
        else
        {
            SS_RoundRobin *current = *queue; // Get the head of the queue
            while (current->nextOne) // Find the last node in the queue
            {
                current = current->nextOne;
            }
            current->nextOne = new_node; // Set the next node of the last node
        }
    }
}


void Initialize_SS_RoundRobin_1(SS_RoundRobin **queue)
{
    int nodes = 3;
    uint8_t dir_base = 2;
    uint16_t addr_base = 22;

    for (int i = 0; i < nodes; i++)
    {
        SS_RoundRobin *new_node = malloc(sizeof(SS_RoundRobin));
        if (!new_node)
        {
            return;
        }

        new_node->myTerm.direction = dir_base + i;
        new_node->myTerm.address = addr_base + i * 11;
        new_node->nextOne = NULL;

        if (!*queue)
        {
            *queue = new_node;
        }
        else
        {
            SS_RoundRobin *current = *queue;
            while (current->nextOne)
            {
                current = current->nextOne;
            }
            current->nextOne = new_node;
        }
    }
}


void Print_SS_RoundRobin(SS_RoundRobin *queue)
{
    SS_RoundRobin *node = queue;
    int index = 1;

    while (node)
    {
        printf("Print Node %d:\n\tDirection: %hhu\n\tAddress: %hu\n", index++,
               node->myTerm.direction, node->myTerm.address);
        node = node->nextOne;
    }
}


uint8_t isTerminalPresent(Terminal trm, SS_RoundRobin *queue)
{
    SS_RoundRobin *current = queue;

    while (current != NULL)
    {
        if (current->myTerm.direction == trm.direction &&
            current->myTerm.address == trm.address)
        {
            return TRUE;
        }
        current = current->nextOne;
    }

    return FALSE;
}


uint8_t removeTerminal(Terminal trm, SS_RoundRobin **queue) {
    SS_RoundRobin *previous = NULL;
    SS_RoundRobin *current = *queue;

    while (current != NULL &&
        !(current->myTerm.direction == trm.direction &&
            current->myTerm.address == trm.address)) {
        previous = current;
        current = current->nextOne;
    }

    if (current == NULL) {
        return FALSE;
    }

    if (previous != NULL) {
        previous->nextOne = current->nextOne;
    } else {
        *queue = current->nextOne;
    }
    return TRUE;
}

