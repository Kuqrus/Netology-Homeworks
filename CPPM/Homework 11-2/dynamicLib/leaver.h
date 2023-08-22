#pragma once
#include <iostream>

#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif


class Leaver {
public:
	/*DYNAMICLIB_API*/ void bye(std::string);
};
