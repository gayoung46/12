#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE 6

int rolldie(void)
{
    return rand()%MAX_DIE +1;
}

int main(int argc, char *argv[])
{
    int cnt; 
    int pos = 0;
    int coinResult = 0 ;
    
    srand((unsigned)(time(NULL)));
    
    printf("=============================================\n");
    printf("             SHARK ISLAND GAME               \n");
    printf("=============================================\n");
    
    //step 1 player name setting & reset
    board_initBoard();
    //step 2 turn play(do while)
    cnt = 0;
    do 
    {
        int die_result;
        #if 1
           //2-1. print present status
           board_printBoardStatus();
           //2-2. roll die
           die_result = rolldie();
           //2-3. move(result)
           pos += die_result;
           
           printf("pos : %i (die: %i)\n", pos, die_result);
           
           coinResult += board_getBoardCoin(pos);
           
           printf("coin : %i\n", coinResult);
           #endif
           //2-4. change turn, shark move
           cnt++;
    }
    
    while(cnt <5);
    
    //step 3 game end(out do while)
    printf("=============================================\n");
    printf("                   GAME END                  \n");
    printf("=============================================\n");
  
  system("PAUSE");	
  return 0;
}
