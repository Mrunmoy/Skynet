#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum path_t {
    PATH_None = 0,
    PATH_Curr,
    PATH_Left,
    PATH_Right
}path_t;

typedef struct node_t {
    int index;
    int left;//struct node_t *pLeft;
    int right; //struct node_t *pRight;
}node_t;

static path_t has_valid_path_recursive(const node_t * pArray, int src_i, int dst_i)
{
    fprintf(stderr," Trying path from %d to %d\n", src_i, dst_i);
    path_t result = PATH_None;
    if ( (src_i == -1) ) {
        result = PATH_None;
    }
    else if (pArray[src_i].index == dst_i) {
        result = PATH_Curr;
    }
    else {
        result = has_valid_path_recursive(pArray, pArray[src_i].left, dst_i);
        if (PATH_None != result) {
            result = PATH_Left;
        }
        else {
            result = has_valid_path_recursive(pArray, pArray[src_i].right, dst_i);
            if (PATH_None != result) {
                result = PATH_Right;
            }
        }
    }

    return result;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N = 3; // the total number of nodes in the level, including the gateways
    int L = 2; // the number of links
    int E = 1; // the number of exit gateways
    //scanf("%d%d%d", &N, &L, &E);
    fprintf(stderr,"%d%d%d\n", N, L, E);

    // allocate game board
    node_t *board = (node_t *)malloc(N * sizeof(node_t));
    for (int i = 0; i < N; i++) {
        board[i].index = i;
        board[i].left = board[i].right = -1;
    }

    int arr[2][2] = { {1,2}, {1,0} };
    for (int i = 0; i < L; i++) {
        int N1 = arr[i][0]; // N1 and N2 defines a link between these nodes
        int N2 = arr[i][1];
        //scanf("%d%d", &N1, &N2);
        fprintf(stderr,"%d%d\n", N1, N2);

        if (-1 == board[N1].left) {
            board[N1].left = N2;
        }
        else {
            board[N1].right = N2;
        }

        if (-1 == board[N2].right) {
            board[N2].right = N1;
        }
        else {
            board[N2].left = N1;
        }
    }
    fprintf(stderr,"Exit nodes at: ");
    int *exit_nodes = (int *)calloc(E, sizeof(int));
    for (int i = 0; i < E; i++) {
        int EI = 2; // the index of a gateway node
        // scanf("%d", &EI);
        fprintf(stderr,"%d ", EI);
        exit_nodes[i] = EI;
    }
    fprintf(stderr,"\n");

    // game loop
    {
        int SI = 1; // The index of the node on which the Skynet agent is positioned this turn
        //scanf("%d", &SI);
        fprintf(stderr,"Skynet Agent at: %d\n", SI);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        for (int ea = 0; ea < E; ea++)
        {
            fprintf(stderr, "Looking at Exit node: %d\n", exit_nodes[ea]);
            int index_of_exit = exit_nodes[ea];
            bool done = false;
            // look left, right
            path_t result = has_valid_path_recursive(board, index_of_exit, SI);
            if (PATH_None != result)
            {   // sever this link's path
                done = true;
                if (PATH_Left == result)
                { //sever left link
                    fprintf(stderr,"Valid Left path from %d to %d\n", index_of_exit, SI);
                    if (board[index_of_exit].index < board[index_of_exit].left) {
                        printf("%d %d\n", board[index_of_exit].index, board[index_of_exit].left);
                    }
                    else {
                        printf("%d %d\n", board[index_of_exit].left, board[index_of_exit].index);
                    }

                    if (board[index_of_exit].index == board[board[index_of_exit].left].left) { //sever left link
                        board[board[index_of_exit].left].left = -1;
                    }
                    else if (board[index_of_exit].index == board[board[index_of_exit].left].right) { //sever right link
                        board[board[index_of_exit].left].right = -1;
                    }
                    board[index_of_exit].left = -1;
                }
                else if (PATH_Right == result)
                { //sever right link
                    fprintf(stderr,"Valid Right path from %d to %d\n", index_of_exit, SI);
                    if (board[index_of_exit].index < board[index_of_exit].right) {
                        printf("%d %d\n", board[index_of_exit].index, board[index_of_exit].right);
                    }
                    else {
                        printf("%d %d\n", board[index_of_exit].right, board[index_of_exit].index);
                    }

                    if (board[index_of_exit].index == board[board[index_of_exit].right].left)
                    { //sever left link
                        board[board[index_of_exit].right].left = -1;
                    }
                    else if (board[index_of_exit].index == board[board[index_of_exit].right].right)
                    { //sever right link
                        board[board[index_of_exit].right].right = -1;
                    }
                    board[index_of_exit].right = -1;
                }
                else {
                    fprintf(stderr,"No path from %d to %d\n", index_of_exit, SI);
                }
            }
        }
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        //printf("0 1\n");
    }

    free(board);
    free(exit_nodes);

    return 0;
}