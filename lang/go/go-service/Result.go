package main

import (
	"encoding/json"
)

type Result[T interface{}] struct {
	Code    int32
	Success bool
	Msg     string
	Data    T
}

func from[T any](result T, err error) Result[T] {
	if err == nil {
		return Result[T]{0, true, "", result}
	} else {
		return Result[T]{1, false, "Error", nil}
	}
}
func (p *Result[T]) toJSON() []byte {
	output, _ := json.Marshal(p)
	return output
}
