/*
    Conways Game of Life in terminal
    
    Author: k0ds
    https://github.com/k0ds
    
*/
/*----------------------------------------------------------------
rules:
    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>



#define HEIGHT 32
#define WIDTH 32
#define FPS 60


static char screen[HEIGHT][WIDTH];
char deadcell = '0';
char alivecell = '1';

void fill(void) { memset(screen, deadcell,sizeof(screen)); }


void randomseen(void) 
{
    //add cell in random location on screen
}


void show(void) //might not work as int
{
   
        printf(screen);   
     
    
}

void killCell(int x, int y)
{
    screen[x][y] = '0';



}

void reviveCell(int x, int y)
{
    screen[x][y] = '1';

}

int checkForNeighbors(int x, int y) //this should iterate though all the dead/alive cells around the location of the input
{  
    int neighbors;
    if (screen[x + 1][y + 1] == '1')
    {
        neighbors++;
        
    }

}



int main(void)
{
    fill();
    screen[1][60] = alivecell;
    screen[1][2] = alivecell;
    screen[1][3] = alivecell;
    
    
    while (true) //MainLoop
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (checkForNeighbors(i, j) > 3)
                {
                    killCell(i, j);

                }
                else if(checkForNeighbors(i,j) < 2)
                {
                    killCell(i, j);
                }
                else if (checkForNeighbors(i, j) == 2 || 3)
                {
                    continue;
                }
                else if (checkForNeighbors(i, j) == 3)
                {
                    reviveCell(i, j);
                }
                
                show();


            }
        }

        usleep(1000 * 1000 / FPS);
    }
   
    
    

    



}