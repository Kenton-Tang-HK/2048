/**
* ESTR 1002 Problem Solving by Programming
*
* Course Project
*
* I declare that the assignment here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* http://www.cuhk.edu.hk/policy/academichonesty/
* Faculty of Engineering Guidelines to Academic Honesty:
* http://www.erg.cuhk.edu.hk/erg-intra/upload/documents/ENGG_Discipline.pdf *
* Student Name : Tang King Long
* Student ID : 1155174724
* Date : 11/11/2021
*/
#ifndef game_h
#define game_h

#include <stdio.h>
#include "game.h"

#include <time.h>
#include <stdlib.h>

#define swap(a,b) { int temp=a; a=b; b=temp; }
#define combine(a,b) { a=0 ; b*=2 ;}

int change(int game_board[4][4],int direction);
int lose(int gameboard[4][4]);
#endif /* game_h */
