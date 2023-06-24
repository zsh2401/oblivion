#include <stdio.h>
double y(int n, double x){
    if(n == 0){
        return 1;
    }
    double yn = y(n - 1,x);
    return 0.5 * (yn + x / yn);
}
double my_sqrt(double x){
    return y(20,x);
}
int main(void){
    printf("%f\n",my_sqrt(10000 * 10000));
    return 0;
}
