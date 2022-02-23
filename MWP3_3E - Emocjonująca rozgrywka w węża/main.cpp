#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class coordinates
{
    int x;
    int y;

public:
    coordinates(int p_x = 0, int p_y = 0)
    : x(p_x), y(p_y)
    {}
    int distanceInNodesFrom(coordinates secondCoords)
    {
        int deltaX = abs(x - secondCoords.x);
        int deltaY = abs(y - secondCoords.y);
        
        return deltaX + deltaY;
    }
    void addToX(int value)
    {
        x += value; 
    }
    void addToY(int value)
    {
        y += value;
    }
};

class snake
{
    vector<coordinates> nodesPositions;

    enum direction
    {
        NORTH, SOUTH, EAST, WEST
    };
    direction snakeDirection;

    void rotateRight()
    {
        switch(snakeDirection)
        {
            case NORTH:
                snakeDirection = EAST;
            break;

            case EAST:
                snakeDirection = SOUTH;
            break;

            case SOUTH:
                snakeDirection = WEST;
            break;

            case WEST:
                snakeDirection = NORTH;
            break;
        }
    }
    void rotateLeft()
    {
        switch(snakeDirection)
        {
            case NORTH:
                snakeDirection = WEST;
            break;

            case WEST:
                snakeDirection = SOUTH;
            break;

            case SOUTH:
                snakeDirection = EAST;
            break;

            case EAST:
                snakeDirection = NORTH;
            break;
        }
    }
public: 
    void move(char moveType);
    bool isDead();
    snake()
    {
        snakeDirection = NORTH;
        nodesPositions.push_back( coordinates(0,0) );
    }
};

bool snake::isDead()
{
    int index = 0;
    int headIndex = nodesPositions.size() - 1; 

    while(index < headIndex)
    {
        int distance = nodesPositions[headIndex].distanceInNodesFrom( nodesPositions[index] );

        if(distance == 0) return true;

        index += distance;
    }

    return false;
}

void snake::move(char moveType)
{
    switch (moveType)
    {
        case 'R':
            rotateRight();
        break;
        case 'L':
            rotateLeft();
        break;
    }

    coordinates newPosition = nodesPositions.back();

    switch(snakeDirection)
    {
        case NORTH:
            newPosition.addToY(1);
        break;

        case SOUTH:
            newPosition.addToY(-1);
        break;

        case EAST:
            newPosition.addToX(1);
        break;

        case WEST:
            newPosition.addToX(-1);
        break;
    }

    nodesPositions.push_back( newPosition );
    
    if(moveType != 'E')
    {
        nodesPositions.erase( nodesPositions.begin() );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int amountOfTests;
    cin >> amountOfTests;

    for(int i = 0; i < amountOfTests; i++)
    {
        snake testSnake;

        int amountOfMoves;
        cin >> amountOfMoves;
        
        string moves;
        cin >> moves;
        
        int currMoveIndex = 0;
        int amountOfMeals = 0;

        //skiping until snake have nodes > 2, after his second meal he is 3 nodes long straight snake, up to this moment symulating his every move is worthlesss   
        while(amountOfMeals < 2 && currMoveIndex < amountOfMoves)
        {
            if(moves[currMoveIndex] == 'E')
            {
                amountOfMeals++;
                testSnake.move('E');
            } 
            currMoveIndex++;
        }
   
        for(; currMoveIndex < amountOfMoves; currMoveIndex++)
        {
            testSnake.move(moves[currMoveIndex]);
            if(testSnake.isDead())
            {
                cout << currMoveIndex + 1 << endl;
                break;
            }
        }
        
        if( !testSnake.isDead() )
        {
            cout << "TAK" << endl;
        }
    }
}
