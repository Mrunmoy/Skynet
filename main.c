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

static bool has_valid_path_recursive(int ** const pArray, int ** const pVisited, const int N, const int src_i, const int dst_i)
{
    for (int i = 0; i < N; i++)
    {
        if (pArray[src_i][i] && (!pVisited[src_i][i])) {// if path exists ?
            pVisited[src_i][i] = 1;
            if (i == dst_i) {
                return true;
            }
            else {
                return has_valid_path_recursive(pArray, pVisited, N, i, dst_i);
            }
        }
    }
    return false;
}


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N = 12; // the total number of nodes in the level, including the gateways
    int L = 23; // the number of links
    int E = 1; // the number of exit gateways
    //scanf("%d%d%d", &N, &L, &E);
    fprintf(stderr,"%d%d%d\n", N, L, E);

    // allocate game board
    int **board = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (int *)calloc(N, sizeof(int));
    }
    int **visited = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++) {
        visited[i] = (int *)calloc(N, sizeof(int));
    }

    int arr[23][2] = { {11,6}, {0,9}, {1,2}, {0,1}, {10,1}, {11,5}, {2,3}, {4,5}, {8,9}, {6,7}, {7,8}, {0,6}, {3,4}, {0,2}, {11,7}, {0,8}, {0,4}, {9,10}, {0,5}, {0,7}, {0,3}, {0,10}, {5,6}  };

    for (int i = 0; i < L; i++) {
        int N1 = arr[i][0]; // N1 and N2 defines a link between these nodes
        int N2 = arr[i][1];
        //scanf("%d%d", &N1, &N2);
        fprintf(stderr,"%d%d\n", N1, N2);
        board[N1][N2] = 1;
        board[N2][N1] = 1;
    }
    fprintf(stderr,"Exit nodes at: ");
    int *exit_nodes = (int *)calloc(E, sizeof(int));
    for (int i = 0; i < E; i++) {
        int EI = 0; // the index of a gateway node
        // scanf("%d", &EI);
        fprintf(stderr,"%d ", EI);
        exit_nodes[i] = EI;
    }
    fprintf(stderr,"\n");

    int SI_List[2] = {11, 2};
    int iter = 0;
    do // game loop
    {
        int SI = SI_List[iter++]; // The index of the node on which the Skynet agent is positioned this turn
        //scanf("%d", &SI);
        fprintf(stderr,"Skynet Agent at: %d\n", SI);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        for (int ea = 0; ea < E; ea++)
        {
            for (int i = 0; i < N; i++) {
                memset(visited[i], 0, N * sizeof(int));
            }
            fprintf(stderr, "Looking at Exit node: %d\n", exit_nodes[ea]);
            int index_of_exit = exit_nodes[ea];
            bool done = false;
            for (int i = 0; i < N; i++) {
                if (board[index_of_exit][i]) {
                    // quick look
                    if ( (i == SI) || has_valid_path_recursive(board, visited, N, i, SI) ) { //sever this link
                        board[index_of_exit][i] = 0;
                        board[i][index_of_exit] = 0;
                        fprintf(stderr, "Path from %d to %d via %d severed!\n", index_of_exit, SI, i);
                        if (index_of_exit < i) {
                            printf("%d %d\n", index_of_exit, i);
                        }
                        else {
                            printf("%d %d\n", i, index_of_exit);
                        }
                        done = true;
                        break;
                    }
                }
            }

            if (!done) {
                fprintf(stderr, "No Valid Right path from %d to %d\n", index_of_exit, SI);
            }
        }
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        //printf("0 1\n");
    } while(iter < 2);

    free(board);
    free(visited);
    free(exit_nodes);

    return 0;
}