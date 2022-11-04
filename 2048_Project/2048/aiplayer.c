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
#include "aiplayer_1155174724.h"
#include <stdio.h>


void right(int game_board[4][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=3;j>=0;j--)
            if (game_board[i][j]==0)
            {
                for (int k=j-1;k>=0;k--)
                    if(game_board[i][k]!=0)
                    {
                        swap(game_board[i][j],game_board[i][k]);
                        break;
                    }
            }
        
    }
    
    for (int i=0;i<4;i++)
        for (int j=3;j>=1;j--)
            if (game_board[i][j]==game_board[i][j-1] && game_board[i][j] != 0 && game_board[i][j] != 2048)
                combine(game_board[i][j-1],game_board[i][j]);
    
    for (int i=0;i<4;i++)
    {
        for (int j=3;j>=0;j--)
            if (game_board[i][j]==0)
            {
                for (int k=j-1;k>=0;k--)
                    if(game_board[i][k]!=0)
                    {
                        swap(game_board[i][j],game_board[i][k]);
                        break;
                    }
            }
        
    }
    
}

void left(int game_board[4][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            if (game_board[i][j]==0)
            {
                for (int k=j+1;k<4;k++)
                    if(game_board[i][k]!=0)
                    {
                        swap(game_board[i][j],game_board[i][k]);
                        break;
                    }
            }
        
    }
    
    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++)
            if (game_board[i][j]==game_board[i][j+1] && game_board[i][j] != 0 && game_board[i][j] != 2048)
                combine(game_board[i][j+1],game_board[i][j]);
    
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            if (game_board[i][j]==0)
            {
                for (int k=j+1;k<4;k++)
                    if(game_board[i][k]!=0)
                    {
                        swap(game_board[i][j],game_board[i][k]);
                        break;
                    }
            }
        
    }
    
}

void up(int game_board[4][4])
{
    for (int j=0;j<4;j++)
    {
        for (int i=0;i<4;i++)
            if (game_board[i][j]==0)
            {
                for (int k=i+1;k<4;k++)
                    if(game_board[k][j]!=0)
                    {
                        swap(game_board[k][j],game_board[i][j]);
                        break;
                    }
            }
        
    }
    
    for (int j=0;j<4;j++)
        for (int i=0;i<3;i++)
            if (game_board[i][j]==game_board[i+1][j] && game_board[i][j] != 0 && game_board[i][j] != 2048)
                combine(game_board[i+1][j],game_board[i][j]);
    
    for (int j=0;j<4;j++)
    {
        for (int i=0;i<4;i++)
            if (game_board[i][j]==0)
            {
                for (int k=i+1;k<4;k++)
                    if(game_board[k][j]!=0)
                    {
                        swap(game_board[k][j],game_board[i][j]);
                        break;
                    }
            }
        
    }
}

void down(int game_board[4][4])
{
    for (int j=0;j<4;j++)
    {
        for (int i=3;i>=0;i--)
            if (game_board[i][j]==0)
            {
                for (int k=i-1;k>=0;k--)
                    if(game_board[k][j]!=0)
                    {
                        swap(game_board[k][j],game_board[i][j]);
                        break;
                    }
            }
        
    }
    
    for (int j=0;j<4;j++)
        for (int i=3;i>=1;i--)
            if (game_board[i][j]==game_board[i-1][j] && game_board[i][j] != 0 && game_board[i][j] != 2048)
                combine(game_board[i-1][j],game_board[i][j]);
    
    for (int j=0;j<4;j++)
    {
        for (int i=3;i>=0;i--)
            if (game_board[i][j]==0)
            {
                for (int k=i-1;k>=0;k--)
                    if(game_board[k][j]!=0)
                    {
                        swap(game_board[k][j],game_board[i][j]);
                        break;
                    }
            }
        
    }
}

int change(int game_board[4][4],int direction)
{
    int temp[4][4];
    
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            temp[i][j]=game_board[i][j];
    
    switch ( direction )
    {
        case 0:
            up(temp);
            break;
        case 1:
            down(temp);
            break;
        case 2:
            left(temp);
            break;
        case 3:
            right(temp);
            break;
    }
    
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (temp[i][j]!=game_board[i][j])
                return 1;
    
    return 0;
    
}

int aiplayer_1155174724(int game_board[4][4] )
{
    int x1flag=1;
    for (int j=0;j<4;j++)
        if (game_board[3][j]==0)
            x1flag=0;
    
    int y1flag=1;
    for (int i=0;i<4;i++)
        if (game_board[i][0]==0)
            y1flag=0;
    
    int x2flag=1;
    for (int j=0;j<4;j++)
        if (game_board[2][j]==0)
            x2flag=0;
    
    int y2flag=1;
    for (int i=0;i<4;i++)
        if (game_board[i][0]==0)
            y2flag=0;
    
    if (change(game_board, 3) && game_board[3][0] != 0
        && game_board[3][0]==2*game_board[3][1]
        && game_board[3][0]==2*game_board[2][0]
        && game_board[2][0]==2*game_board[3][2]
        && game_board[2][0]==2*game_board[2][1]
        && game_board[2][0]==2*game_board[1][0]
        && game_board[1][0]==2*game_board[0][0]
        && game_board[1][0]==2*game_board[1][1]
        && game_board[1][0]==2*game_board[2][2]
        && game_board[1][0]==2*game_board[3][3])
        return 3;
    
    if (change(game_board, 1)
        &&  game_board[3][0] !=0
        &&  game_board[2][3]==  game_board[3][3]
        &&  game_board[3][2]==2*game_board[3][3]
        &&  game_board[3][1]==2*game_board[3][2]
        &&  game_board[3][0]==2*game_board[3][1] )
        return 1;
    
    if (change(game_board, 2))
        return 2;
    else if (change(game_board, 1))
        return 1;
    
    
    if (change(game_board, 3) && x1flag)
        return 3;
  

    if (change(game_board, 0) && y1flag)
        return 0;
    

    if (change(game_board, 3) && x2flag)
        return 3;
    

    if (change(game_board, 0) && y2flag)
        return 0;
    
    if (change(game_board,3))
        return 3;
    else
        return 0;
    
}

