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
#include "game.h"



void printgrid(int game_board[4][4])
{
    for (int i=0;i<4;i++)
    {
        printf("+----+----+----+----+\n");
        for (int j=0;j<4;j++)
        {
            printf("|");
            if (game_board[i][j]!=0)
                printf("%4d",game_board[i][j]);
            else
                printf("    ");
        }
        printf("|\n");
    }
    printf("+----+----+----+----+\n");
}

int human_player(int game_board[4][4] )
{
    char input[2];
    int tmp=0;
    do
    {
        do
        {
            scanf("%s",input);
            if ( (input[0]!='U') && (input[0]!='D') && (input[0]!='L') && (input[0]!='R'))
                printf("Invalid input. Please input again.\n");
        
        } while( (input[0]!='U') && (input[0]!='D') && (input[0]!='L') && (input[0]!='R'));
        
        switch(input[0])
        {
            case 'U':
                tmp=0;
                break;
            case 'D':
                tmp=1;
                break;
            case 'L':
                tmp=2;
                break;
            case 'R':
                tmp=3;
                break;
        }
        
        if (!change(game_board, tmp))
            printf("Cannot make any changes. Please input again.\n");
            
    } while (!change(game_board, tmp));
    
    switch(input[0])
    {
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'L':
            return 2;
        case 'R':
            return 3;
        default:
            return 0;
    }
}

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

void random_generate(int game_board[4][4])
{
    int i,j;
    while ( 1 )
    {
        i = rand() % 4 ;
        j = rand() % 4 ;
        if ( game_board[i][j] == 0 )
        {
            game_board[i][j] = 2 ;
            break ;
        }
    }
}

int score(int game_board[4][4])
{
    int temp=0;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            temp+=game_board[i][j];
    return temp;
}

int lose(int game_board[4][4])
{
    int tmp=1;
    
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (game_board[i][j]==0)
                tmp=0;
        }
    }
    
    if (change(game_board,0)==1 || change(game_board,1)==1 || change(game_board,2)==1
         || change(game_board,3)==1)
        tmp=0;
    
    return tmp;
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

int main(void)
{   
    srand(time(NULL));  
    int game_board[4][4]={0} ;
    
    while (1)
    {
        random_generate(game_board);
        printgrid(game_board);
        
        if (lose(game_board))
            break;
            
        switch (human_player(game_board))
        {
            case 0:
                up(game_board);
                break;
            case 1:
                down(game_board);
                break;
            case 2:
                left(game_board);
                break;
            case 3:
                right(game_board);
                break;
        }
    }
    
    if (lose(game_board))
    {
        printf("Under this scenario:\n");
        printf("Your score is %d\n",score(game_board));
        printf("The game is over!\n");
    }
        
    return 0;
}
