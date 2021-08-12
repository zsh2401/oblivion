package main

/*
extern int div(int a, int b);
*/
// import "C"
func main(){}

//export mydiv
func mydiv(a int,b int) int {
	return a / b;
}