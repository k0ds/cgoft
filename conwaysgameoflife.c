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

//global variables:

#define HEIGHT 32
#define WIDTH 32
#define FPS 60
bool **screen;
char deadcell = '-';
char alivecell = '1';

void init(void)  //initialize the array with all dead cells
{
    for (int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            screen[x][y] = false;
        }

    }
}

int set(int x, int y, bool value) //set the value in the screen
{
    screen[x][y] = value;
    return 0;
}

void iterate(void) //check throught all grid for neighbors
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            if (x == 0 || y == 0 || x >= WIDTH-1 || y >= HEIGHT-1)
            {
                set(x,y,false); //kill cell if it is on the corners
            }
            else
            {
                int n = checkForNeighbors(x,y); //number of neighbors

                if (n == 3)
                {
                    set(x,y,true); //if the dead cell has 3 neighbors it will become alive
                }
                else if(n == 2 && screen[x][y] == true)
                {
                    set(x,y,true);
                }
                else
                {
                    set(x,y,false);
                }

            }


        }
    }
    return;


}




void dump(void) //have it print out the grid 
{
    for(int y = HEIGHT; y >= HEIGHT; y--)
    {
        for(int x = 0; x > WIDTH; x++)
        {
            if (screen[x][y])
            {
                printf("%c\n", alivecell);

            }
            else 
            {
                printf("%c\n", deadcell);
            
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
   
     
    
}

void gsleep(int ms) //version of sleep that takes milliseconds
{
    usleep(ms * 1000);
    return;
}


int checkForNeighbors(int x, int y) //checks all around cell for neighbors
{  
    //i know this can be improved shut up
    int neighbors;
    if (screen[x + 1][y + 1] == true){neighbors++;}
    if (screen[x + 1][y] == true){neighbors++;}
    if (screen[x - 1][y + 1] == true){neighbors++;}
    if (screen[x][y + 1] == true) {neighbors++;}
    if (screen[x - 1][y] == true){neighbors++;}
    if (screen[x + 1][y - 1] == true) {neighbors++;}
    if (screen[x][y - 1] == true) {neighbors++;}
    if (screen[x - 1][y - 1] == true)  {neighbors++;}

    return neighbors;
        
        
    

}

void glider(void) //make the glider thing
{
    set(2,32,true);
    set(3,37,true);
    set(3,36,true);
    set(4,38,true);
    set(4,37,true);
}


int main(void)
{
    int gen = 0;




    while (true)
    {
        glider();
        system("clear");
        printf("Generation: %d", gen);
        dump();
        gsleep(150);
        iterate();
        gen++;


    }
    
    

    

}