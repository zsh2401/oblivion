// #include <cstdio>
#include <iostream>
class A
{
private:
    int64_t a;
public:
    A(int a)
    {
        this->a = a;
        std::cout << this->a << std::endl;
    }

    ~A()
    {
        std::cout << "Disposing" << std::endl;
    }
};
int main(void)
{
    A* a = new A(0);
    std::cout << sizeof(A) << std::endl;
}