#include <iostream>
#include <cmath>

void pythagorean_trio(int n, int a, int b, int c, int& count);
void output(int a, int b, int c, int count);

// TASK 25

int main()
{
    int n, a = 1, b = 1, c = 1, count = 0;
    // Input of the numbers
    std::cout << "Please, enter the natural n: ";
    std::cin >> n;
    while (n <= 0)   // The codition of a natural number
    {
        std::cout << "n is less or equal to 0. Please, enter a natural one: ";
        std::cin >> n;
    }
    pythagorean_trio(n, a, b, c, count);    // Calculation of pythagorean trios
    std::cout << "The quantity of pythagorean trios is: " << count / 2 << std::endl;    // Output of the count of trios
}

void pythagorean_trio(int n, int a, int b, int c, int& count)
{
    if (a <= n && b <= n && c <= n)
    {
        if (pow(a, 2) + pow(b, 2) == pow(c, 2)) // Completed pythagorean trio
        {
            count++;
            output(a, b, c, count);
        }

        if (c != n)
        {
            pythagorean_trio(n, a, b, ++c, count);
        }
        else if (c == n && b != n)
        {
            c = 1;
            pythagorean_trio(n, a, ++b, c, count);
        }
        else if (c == n && b == n && a != n)
        {
            b = 1;
            c = 1;
            pythagorean_trio(n, ++a, b, c, count);
        }
    }
}

void output(int a, int b, int c, int count) // Output of a, b and c
{
    std::cout << "There is the " << count << " pythagorean trio! It's consisted of: " << std::endl;
    std::cout << "a, which equals to: " << a << std::endl;
    std::cout << "b, which equals to: " << b << std::endl;
    std::cout << "c, which equals to: " << c << std::endl;
}