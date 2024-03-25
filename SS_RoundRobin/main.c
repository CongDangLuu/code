#include "main.h"

int main()
{
    SS_RoundRobin *queue = NULL;

    Initialize_SS_RoundRobin(&queue);

    Print_SS_RoundRobin(queue);

    Terminal target1 = {2, 22};
    Terminal target2 = {5, 55};

    printf("This node is%spresent\n", isTerminalPresent(target1, queue) ? " " : " not ");
    printf("This node is%spresent\n", isTerminalPresent(target2, queue) ? " " : " not ");

    removeTerminal(target1, queue);

    Print_SS_RoundRobin(queue);

    free(queue);

    return 0;
}

void Initialize_SS_RoundRobin(SS_RoundRobin **queue)
{
    int NumNode;
    printf("Enter number of nodes: ");
    scanf("%d", &NumNode);
    for (int i = 0; i < NumNode; i++)
    {

        SS_RoundRobin *newNode = (SS_RoundRobin *)malloc(sizeof(SS_RoundRobin));
        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter direction (0-255): ");
        scanf("%d", &newNode->myTerm.direction);

        printf("Enter address (0-65535): ");
        scanf("%d", &newNode->myTerm.address);

        newNode->nextOne = NULL;

        if (*queue == NULL)
        {
            *queue = newNode;
        }
        else
        {
            SS_RoundRobin *current = *queue;
            while (current->nextOne != NULL)
            { // find new node
                current = current->nextOne;
            }
            current->nextOne = newNode;
        }
    }
}

void Print_SS_RoundRobin(SS_RoundRobin *queue)
{
    SS_RoundRobin *current = queue;
    int cnt = 1;
    printf("\nEnter Print_SS_RoundRobin\n");
    while (current != NULL)
    {
        printf("Print Node %d:\n", cnt++);
        printf("\tDirection: %d\n", current->myTerm.direction);
        printf("\tAddress:   %d\n", current->myTerm.address);
        current = current->nextOne;
        if (cnt > MAX_TERM)
        {
            return;
        }
    }
}

uint8_t isTerminalPresent(Terminal trm, SS_RoundRobin *queue) {
    SS_RoundRobin *current = queue;
    while (current != NULL) {
        if (current->myTerm.direction == trm.direction &&
            current->myTerm.address == trm.address) {
            return TRUE;
        }
        current = current->nextOne;
    }
    return FALSE;
}


uint8_t removeTerminal(Terminal trm, SS_RoundRobin *queue) {

    SS_RoundRobin *current = queue;
    SS_RoundRobin *prev = NULL;
    printf("\nEnter removeTerminal\n");

    if (!isTerminalPresent(trm,queue)){
        printf("This node is not present\n");
        return FALSE;// not present
    }   

    while (current != NULL) {
        if (current->myTerm.direction == trm.direction &&
            current->myTerm.address == trm.address) {
            if (prev != NULL) {
                prev->nextOne = current->nextOne; //skip current node
            } else {
                printf("The first node\n");
                queue = current->nextOne;//The first node   
            }
            Print_SS_RoundRobin(queue);
            return TRUE;
        }
        prev = current;
        current = current->nextOne;
    }
    return FALSE;
}