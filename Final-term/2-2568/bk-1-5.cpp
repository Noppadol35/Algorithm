#include <iostream>
using namespace std;

int target_length;
int lengths[] = {2, 3, 5};
int min_pieces = 1000000;
bool found_solution = false;

void cutWire(int remain, int count)
{

    if (remain == 0)
    {
        if (count < min_pieces)
        {
            min_pieces = count;
            found_solution = true;
        }
        return;
    }

    if (remain < 0)
    {
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        cutWire(remain - lengths[i], count + 1);
    }
}

int main()
{
    cin >> target_length;

    int temp;
    for (int i = 0; i < 3; i++)
        cin >> temp;

    cutWire(target_length, 0);

    if (found_solution)
    {
        cout << min_pieces << endl;
    }
    else
    {

        cout << "0" << endl;
    }

    return 0;
}