#include <iostream>

using namespace std;
/*
Problem Statement
Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits,
leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not
include ‘1’.
*/

class HappyNumber
{

public:
    static string find(int num)
    {
        int slow = num;
        int fast = num;

        do
        {
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        } while (slow != fast);
        return slow == 1 ? ("happy number") : "not happy number";
    }

private:
    static int findSquare(int num)
    {
        int sum = 0;
        int digit;

        while (num > 0)
        {
            digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};

int main(int, char **)
{
    cout << HappyNumber::find(23) << endl;
    cout << HappyNumber::find(12) << endl;
}
