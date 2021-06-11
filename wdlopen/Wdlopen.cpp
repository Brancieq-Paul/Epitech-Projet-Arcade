/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Wdlopen
*/

#include <dlfcn.h>
#include "Wdlopen.hpp"

Wdlopen::Wdlopen(std::string libPath)
{
    hndl = dlopen(libPath.c_str(), RTLD_LAZY);
    if(hndl == NULL)
    {
        printf("erreur dlopen : %s\n", dlerror());
        exit(84);
    }
}

Wdlopen::~Wdlopen()
{
    dlclose(hndl);
}

void *Wdlopen::fetchFunc(std::string name)
{
    void *myfunc = dlsym(hndl, name.c_str());
    if (myfunc == NULL)
    {
        printf("erreur dlsym : %s\n", dlerror());
        dlclose(hndl);
        exit(EXIT_FAILURE);
    }
    return myfunc;
}
