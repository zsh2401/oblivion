package main

import (
	"fmt"
	"net/http"
	"github.com/nacos-group/nacos-sdk-go/v2"
)

func main() {
	Nacos()
	fmt.Print("Go!")
	http.HandleFunc("/", HelloServer)
	http.ListenAndServe(":24010", nil)
}

func HelloServer(w http.ResponseWriter, r *http.Request) {
	//w.Write(w)
	a := Result[int8]{1, true, "", 3}
	w.Write(a.toJSON())
	fmt.Printf("Hello %s", a.toJSON())
	//fmt.Fprintf(w, "Hello, %s!", r.URL.Path[1:])
}
