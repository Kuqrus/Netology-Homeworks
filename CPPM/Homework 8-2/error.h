#pragma once
#include <iostream>

class shapeError180 : public std::exception
{
public:
    std::string what();
};

class shapeError90 : public std::exception
{
public:
    std::string what();
};

class shapeErrorNotIsosceles : public std::exception
{
public:
    std::string what();
};

class shapeErrorNotEqual : public std::exception
{
public:
    std::string what();
};

class shapeErrorQuad : public std::exception
{
public:
    std::string what();
};

class shapeErrorRect : public std::exception
{
public:
    std::string what();
};

class shapeErrorSquare : public std::exception
{
public:
    std::string what();
};

class shapeErrorParall : public std::exception
{
public:
    std::string what();
};

class shapeErrorRhomb : public std::exception
{
public:
    std::string what();
};