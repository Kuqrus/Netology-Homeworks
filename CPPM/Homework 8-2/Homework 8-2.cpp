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

    //try
    //{
    //    createTriangle triangle(5, 5, 2, 80, 30, 70);
    //    printInfo(&triangle);
    //}
    //catch (shapeError180 e)
    //{
    //    std::cout << e.what() << std::endl;
    //}
    //
    //try
    //{
    //    createTriangle triangleWrong(5, 5, 2, 800, 30, 70);
    //    printInfo(&triangleWrong);
    //}
    //catch (shapeError180 e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    //try
    //{
    //    createRightTriangle right_triangle(5, 3, 4, 30, 60, 90);
    //    printInfo(&right_triangle);
    //}
    //catch (shapeError180 e)
    //{
    //    std::cout << e.what() << std::endl;
    //}
    //catch (shapeError90 e)
    //{
    //    std::cout << e.what() << std::endl;
    //}
 
    //try
    //{
    //    createIsoscelesTriangle isosceles_triangle(10, 30, 10, 50, 80, 50);
    //    printInfo(&isosceles_triangle);
    //}
    //catch (shapeError180 e)
    //{
    //    std::cout << e.what() << std::endl;
    //}
    //catch (shapeErrorNotIsosceles e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    //try
    //{
    //    createEquilateralTriangle equilateral_triangle(20, 20, 21, 60, 60, 60);
    //    printInfo(&equilateral_triangle);
    //}
    //catch (shapeError180 e)
    //{
    //    std::cout << e.what() << std::endl;
    //}
    //catch (shapeErrorNotEqual e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    //try
    //{
    //    createQuad quad(33, 20, 30, 10, 80, 100, 60, 120);
    //    printInfo(&quad);
    //}
    //catch (shapeErrorQuad e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    //try
    //{
    //    createRectangle rect(10, 15, 10, 15, 90, 90, 90, 90);
    //    printInfo(&rect);
    //}
    //catch (shapeErrorQuad e)
    //{
    //    std::cout << e.what() << std::endl;
    //}
    //catch (shapeErrorRect e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    //try
    //{
    //    createSquare square(15, 15, 15, 15, 90, 90, 90, 90);
    //    printInfo(&square);
    //}
    //catch (shapeErrorQuad a)
    //{
    //    std::cout << a.what() << std::endl;
    //}
    //catch (shapeErrorSquare e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    //try
    //{
    //    createParallelogram parall(10, 20, 10, 20, 80, 100, 80, 100);
    //    printInfo(&parall);
    //}
    //catch (shapeErrorQuad a)
    //{
    //    std::cout << a.what() << std::endl;
    //}
    //catch (shapeErrorParall e)
    //{
    //    std::cout << e.what() << std::endl;
    //}

    try
    {
        createRhomd rhomd(10, 10, 10, 10, 80, 100, 80, 100);
        printInfo(&rhomd);
    }
    catch (shapeErrorQuad a)
    {
        std::cout << a.what() << std::endl;
    }
    catch (shapeErrorRhomb e)
    {
        std::cout << e.what() << std::endl;
    }

}
