#ifndef aiplayer_1155174724_h

#define aiplayer_1155174724_h


#include <stdio.h>

#define swap(a,b) { int temp=a; a=b; b=temp; }
#define combine(a,b) { a=0 ; b*=2 ;}

void right(int game_board[4][4]);
void left(int game_board[4][4]);
void up(int game_board[4][4]);
void down(int game_board[4][4]);
int change(int game_board[4][4],int direction);
int aiplayer_1155174724(int game_board[4][4] );

#endif /* aiplayer_1155174724_h */
