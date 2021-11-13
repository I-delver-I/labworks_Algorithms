#include <iostream>
#include <cmath>

void input(int &n);
void pythagorean_trio(int &n, int& a, int& b, int& c, int& count);
void output(int& a, int& b, int& c, int& count);

// TASK 25

int main()
{
    int n, a = 1, b = 1, c = 1, count = 0;
    
    input(n); // Input of the numbers
    pythagorean_trio(n, a, b, c, count);
    std::cout << "The quantity of pythagorean trios is: " << count / 2 << std::endl;
}

void input(int& n)
{
    std::cout << "Please, enter the natural n: ";
    std::cin >> n;
    while(n <= 0)
    {
        std::cout << "n is less or equal to 0. Please, enter a natural one: ";
        std::cin >> n;
    }
}

void pythagorean_trio(int& n, int& a, int& b, int& c, int& count)
{
    if (pow(a, 2) + pow(b, 2) == pow(c, 2))
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

void output(int& a, int& b, int& c, int& count)
{
    std::cout << "There is the " << count << " pythagorean trio! It's consisted of: " << std::endl;
    std::cout << "a, which equals to: " << a << std::endl;
    std::cout << "b, which equals to: " << b << std::endl;
    std::cout << "c, which equals to: " << c << std::endl;
}