#include <iostream>
#include <vector>

using namespace std;

enum operation
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    EQUAL
};

enum numberType
{
    ODD,
    EVEN
};

class sequenceOfNumberTypes
{
    vector<numberType> sequence;

public:
    void add(int newNumber)
    {
        if(newNumber & 1) sequence.push_back(ODD);
        else    sequence.push_back(EVEN);
    }
    numberType operator[](int index)
    {
        return sequence[index];
    }
    void doOperationOnNextAndThis(operation op, int index = 0)
    {
        switch(op)
        {
            case ADDITION:
            case SUBTRACTION:
                if(sequence[index] == sequence[index + 1])
                {
                    sequence[index] = EVEN;
                }
                else
                {
                    sequence[index] = ODD;
                }
            break;

            case MULTIPLICATION:
                if(sequence[index] == EVEN || sequence[index + 1] == EVEN)
                {
                    sequence[index] = EVEN;
                }
        }
        sequence.erase(sequence.begin() + index + 1);
    }
};

class sequenceOfOperations
{
    vector<operation> sequence;

public:
    void add(char newOperation)
    {
        switch(newOperation)
        {
            case '+':
                sequence.push_back(ADDITION);
            break;

            case '-':
                sequence.push_back(SUBTRACTION);
            break;

            case '*':
                sequence.push_back(MULTIPLICATION);
            break;

            case '=':
                sequence.push_back(EQUAL);
            break;
        }
    }
    operation operator[](int index)
    {
        return sequence[index];
    }
    void erase(int index)
    {
        sequence.erase(sequence.begin() + index);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int amountOfTests;
    cin >> amountOfTests;

    for(int t = 0; t < amountOfTests; t++)
    {
        sequenceOfNumberTypes numbers;
        sequenceOfOperations operations;
        int number;
        char operation;

        do
        {
            cin >> number >> operation;
            numbers.add(number);
            operations.add(operation);
            
        } while(operation != '=');

        while(operations[0] != EQUAL)
        {
            if(operations[1] == MULTIPLICATION)
            {
                numbers.doOperationOnNextAndThis(MULTIPLICATION, 1);
                operations.erase(1);
            }
            else
            {
                numbers.doOperationOnNextAndThis(operations[0]);
                operations.erase(0);
            }
        }

        cout << (numbers[0] == EVEN ? "TAK" : "NIE") << endl;     
    }
}