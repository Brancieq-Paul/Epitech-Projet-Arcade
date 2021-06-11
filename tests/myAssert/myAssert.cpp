/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** myAssert
*/

#include "myAssert.hpp"
#include <iostream>

bool myTests::Assert::_error = false;

myTests::Assert::Assert(std::string testCateg, std::string testName, std::string testDesc, bool toTest)
{
    if (toTest == false)
    {
        myTests::Assert::_error = true;
    }
    display(testCateg, testName, testDesc, toTest);
}

void myTests::Assert::display(std::string testCateg, std::string testName, std::string testDesc, bool toTest)
{
    std::cout << testCateg << " | " << testName << ": ";
    if (toTest)
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl << testDesc << std::endl;
    std::cout << std::endl;
}
