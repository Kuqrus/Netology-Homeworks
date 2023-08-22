#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
 
#include "quad.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhomb.h"

#include "print_info.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    createTriangle triangle(5, 5, 2, 80, 30, 70);
    printInfo(&triangle);

    createRightTriangle right_triangle(5, 3, 4, 30, 60);
    printInfo(&right_triangle);

    createIsoscelesTriangle isosceles_triangle(10, 30, 60, 70);
    printInfo(&isosceles_triangle);

    createEquilateralTriangle equilateral_triangle(20);
    printInfo(&equilateral_triangle);

    createQuad quad(33, 20, 30, 10, 80, 100, 20, 143);
    printInfo(&quad);

    createSquare square(15);
    printInfo(&square);

    createParallelogram parall(10, 20, 100, 80);
    printInfo(&parall);

    createRhomd rhomd(10, 60, 100);
    printInfo(&rhomd);

    system("pause");

}
