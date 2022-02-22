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

class snakeNode
{
    coordinates position;
    snakeNode *nextNode;

public:
    snakeNode(coordinates p_position)
    : position(p_position), nextNode(nullptr)
    {}
    coordinates getPosition()
    {
        return position;
    }
    void setNextNode(snakeNode *newNextNode)
    {
        nextNode = newNextNode;
    }
    void setPosition(coordinates newPosition)
    {
        position = newPosition;
    }
    snakeNode* nextPtr()
    {
        return nextNode;
    }
    bool isHead()
    {
        if(nextNode == nullptr) return true;
        return false;
    }
};

class snake
{
    vector<snakeNode> nodes;

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
        nodes.push_back( snakeNode( coordinates(0,0) ) );
    }
};

bool snake::isDead()
{
    int index = 0; 

    while(index < nodes.size() - 1)
    {
        int distance = nodes.back().getPosition().distanceInNodesFrom( nodes[index].getPosition() );

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

    coordinates newPosition = nodes.back().getPosition();

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

    nodes.push_back( snakeNode(newPosition) );
    
    if(moveType != 'E')
    {
        nodes.erase( nodes.begin() );
    }
}

int main()
{
    int amountOfTests;
    cin >> amountOfTests;

    for(int i = 0; i < amountOfTests; i++)
    {
        snake testSnake;
        int amountOfMoves;
        cin >> amountOfMoves;
        
        string moves;
        cin >> moves;
        
        int k = 0;
        int amountOfEaten = 0;

        while(amountOfEaten < 2 && k < amountOfMoves)
        {
            if(moves[k] == 'E')
            {
                amountOfEaten++;
                testSnake.move('E');
            } 
            k++;
        }
   
        for(; k < amountOfMoves; k++)
        {
            testSnake.move(moves[k]);
            if(testSnake.isDead())
            {
                cout << k + 1 << endl;
                break;
            }
        }
        
        if( !testSnake.isDead() )
        {
            cout << "TAK" << endl;
        }
    }
}
