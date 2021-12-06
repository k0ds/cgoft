#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
    char deadcell = '0';

    static char screen[32][64];
    memset(screen, ' ', sizeof(screen));
    memset(screen, deadcell, 32 * 32);
    

    screen[2][3] = '1';


    

    for (int i = 0; i < 32/2; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            
            
                if (screen[i][j] == '1')
                {
                    screen[j][j] = '1';
                }
                printf(screen);



                usleep(1000 * 1000 / 60);
            
           
        }
    }

   

       


}