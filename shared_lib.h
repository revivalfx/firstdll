#ifndef SHARED_LIB_H
#define SHARED_LIB_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>

using namespace std;

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef BUILD_MY_DLL
    #define SHARED_LIB __declspec(dllexport)
#else
    #define SHARED_LIB __declspec(dllexport)
#endif

void SHARED_LIB pipecommand(string strCmd);

#ifdef __cplusplus       
    }
#endif

void SHARED_LIB SaySomething(string str);

#endif
