#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1
#define FALSE 0

#define MAX_TERM    5

typedef struct
{
    uint8_t    direction;
    uint16_t   address;
} Terminal;

typedef struct
{
    Terminal myTerm;
    struct SS_RoundRobin *nextOne;
}SS_RoundRobin;

void Print_SS_RoundRobin(SS_RoundRobin *queue);
void Initialize_SS_RoundRobin(SS_RoundRobin **queue);
uint8_t isTerminalPresent(Terminal trm, SS_RoundRobin *queue);
uint8_t removeTerminal(Terminal trm, SS_RoundRobin **queue);
void Initialize_SS_RoundRobin_1(SS_RoundRobin **queue);
