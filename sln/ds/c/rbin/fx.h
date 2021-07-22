/*
Version 0.5-Lee
*/
#ifndef ___x_FX_H
#define ___x_FX_H
#include "iostream"
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#define RETCODE_SUCC = 0;
#define RETCODE_ERR_NULL = -1;
#define RETCODE_ERR_OVERFLOW = 2;
typedef int result_t;
typedef void* dsdata_t;
namespace fx
{
typedef int ExecStatus;
typedef void *data_t;
typedef std::function<bool(fx::data_t,size_t,size_t)> Traveller;
const ExecStatus RETCODE_ERR = -1;
const ExecStatus RETCODE_EMPTY = 1;
const ExecStatus RETCODE_SUCCESS = 0;
const ExecStatus RETCODE_OVERFLOW = 2;
} // namespace fx
#endif
