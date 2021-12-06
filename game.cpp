 
/*/
###########################
written by Jason Shen, 2021
###########################
/*/

#include <iostream>
#include <unistd.h>

/*/ The Class of Life /*/

class life
{
    #define DEFAULT_GRID_SIZE_X 20
    #define DEFAULT_GRID_SIZE_Y 20


private:
    int LivingNeighbors(int x, int y)
    {
        /*/
        counts the number of living neighbors of a cell
        will not work if the target cell is on the boundry of the grid
        /*/

        int NumLivingNeigbors = 0;

        //if(grid[x][y] == true) ++NumLivingNeigbors;

        if(grid[x - 1][y + 1] == true){NumLivingNeigbors++;}

        if(grid[x][y + 1] == true){NumLivingNeigbors++;}

        if(grid[x + 1][y + 1] == true){NumLivingNeigbors++;}

        if(grid[x - 1][y] == true){NumLivingNeigbors++;}

        if(grid[x + 1][y] == true){NumLivingNeigbors++;}

        if(grid[x - 1][y - 1] == true){NumLivingNeigbors++;}

        if(grid[x][y - 1] == true){NumLivingNeigbors++;}

        if(grid[x + 1][y - 1] == true){NumLivingNeigbors++;}

        return NumLivingNeigbors;
    }

public:

    bool **grid;        //boolean finite 2D life grid
    int GridSize_x, GridSize_y;     //contains the x and y size of the grid

    /*/ constructors /*/
    life()
    {
        grid = (bool **) malloc(sizeof(bool *) * DEFAULT_GRID_SIZE_X);      //initializes the x pointer range to 20
        for(int x = 0; x < DEFAULT_GRID_SIZE_X; ++x)
        {
            grid[x] = (bool *) malloc(sizeof(bool) * DEFAULT_GRID_SIZE_X);      //initializes the y pointer range to 20
            for(int y = 0; y < DEFAULT_GRID_SIZE_Y; ++y)
            {
                grid[x][y] = false;     //sets all grids to 0/false
            }
        }

        GridSize_x = DEFAULT_GRID_SIZE_X;
        GridSize_y = DEFAULT_GRID_SIZE_Y;    bool **grid;        //boolean finite 2D life grid
    int GridSize_x, GridSize_y;     //contains the x and y size of the grid

    }

    life(int size_x, int size_y)
    {
        grid = (bool **) malloc(sizeof(bool *) * size_x);      //initializes the x pointer range to 20
        for(int x = 0; x < size_x; ++x)
        {
            grid[x] = (bool *) malloc(sizeof(bool) * size_x);      //initializes the y pointer range to 20
            for(int y = 0; y < size_y; ++y)
            {
                grid[x][y] = false;     //sets all grids to 0/false
            }
        }

        GridSize_x = size_x;
        GridSize_y = size_y;
    }

    int set(int x, int y, bool value)
    {
        /*/ sets inputed coordinate to the inputed value /*/
        grid[x][y] = value;
        return 0;
    }



    void iterate(void)
    {
        life NextGen(GridSize_x, GridSize_y);
        /*/ iterates to the next iteration /*/
        for(int x = 0; x < GridSize_x; ++x)
        {
            for(int y = 0; y < GridSize_y; ++y)
            {

                if (x == 0 || y == 0 || x >= GridSize_x-1 || y >= GridSize_y-1)
                {
                    //if the cell is on the boundry of the grid, the cell dies
                    NextGen.set(x,y,false);
                }

                else
                {
                    int n = LivingNeighbors(x,y);   // gets the number of living neighbors of the cell
                    //if(n > 0) std::cout << x << "," << y << ": " << n << "\n";


                    if (n == 3)
                    {
                        /*/ Any dead cell with exactly three live neighbours becomes a live cell /*/
                        NextGen.set(x,y,true);
                    }

                    else if (n == 2 && grid[x][y] == true)
                    {
                        NextGen.set(x,y,true);
                    }

                    else
                    {
                        NextGen.set(x,y,false);
                    }
                }
            }
        }

        grid = NextGen.grid;
        return;
    }

    void dump(void)
    {
        /*/ prints the grid to the terminal /*/
        for(int y = GridSize_y; y >= 0; --y)
        {
            for(int x = 0; x < GridSize_x; ++x)
            {
                if(grid[x][y])
                {
                    std::cout << "1" << " ";
                }

                else
                {
                    std::cout << "-" << " ";
                }
            }
                std::cout << "\n";

        }
        std::cout << "\n";
        return;
    }
};


void sleep(int millisec)
{
    usleep(millisec * 1000); // takes microseconds
    return;
}


int main(int argc, char** argv)
{
    life MyLife(95,42); //For 190x46 terminator screen

    /*/ Glider /*/
    MyLife.set(2, 38, true);
    MyLife.set(3, 37, true);
    MyLife.set(3, 36, true);
    MyLife.set(4, 38, true);
    MyLife.set(4, 37, true);

    /*/ Blinker /*/
    MyLife.set(73, 35, true);
    MyLife.set(74, 35, true);
    MyLife.set(75, 35, true);

    /*/ R /*/
    MyLife.set(48, 20, true);
    MyLife.set(49, 20, true);
    MyLife.set(49, 19, true);
    MyLife.set(49, 21, true);
    MyLife.set(50, 21, true);


    int generation = 0;
    while(true)
    {
        std::system("clear");
        std::cout << "Generation " << generation << "\n";
        MyLife.dump();
        sleep(150);
        MyLife.iterate();
        generation ++;
    }

    return 0;
}
