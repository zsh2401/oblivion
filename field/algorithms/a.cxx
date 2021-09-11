#include <stdio.h>
class A{
    public:
        A(){

        }
        A(int a){
            printf("%d\n",a);
        }
};
int main(int argc, char **const argv, char **const env)
{
    A a(1);
    // mos_printk();
    // char **pCurrent = env;
    // for (char **pCurrnet = env; *pCurrent != NULL; pCurrent++)
    // {
    //     printf("%s\n", *pCurrent);
    // }
    return 0;
}