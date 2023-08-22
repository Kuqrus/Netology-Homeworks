#pragma once
#include <iostream>

#ifdef dynamicLib_EXPORTS
#define dynamicLib_API __declspec(dllexport)
#else
#define dynamicLib_API __declspec(dllimport)
#endif


class createShape {
public:
    dynamicLib_API createShape(std::string name_, int side_);
    dynamicLib_API std::string getName();

    dynamicLib_API virtual void info();

private:
    std::string name;
    int side;
};