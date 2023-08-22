#include "error.h"

std::string shapeError180::what()  { return "Ошибка создания фигуры. Причина: сумма углов должна быть равна 180 градусов\n"; }

std::string shapeError90::what() { return "Ошибка создания фигуры. Причина: угол С должен быть 90 градусов\n"; }

std::string shapeErrorNotIsosceles::what() { return "Ошибка создания фигуры. Причина: стороны a и c и углы A и C должны быть равны\n"; }

std::string shapeErrorNotEqual::what() { return "Ошибка создания фигуры. Причина: все стороны должны быть равны, все углы должны быть 60 градусов\n"; }

std::string shapeErrorQuad::what() { return "Ошибка создания фигуры. Причина: сумма углов должна быть равна 360 градусов\n"; }

std::string shapeErrorRect::what() { return "Ошибка создания фигуры. Причина: стороны a,c и b,d должны быть попарно равны, все углы должны быть 90 градусов\n"; }

std::string shapeErrorSquare::what() { return "Ошибка создания фигуры. Причина: все стороны должны быть равны, все углы должны быть 90 градусов\n"; }

std::string shapeErrorParall::what() { return "Ошибка создания фигуры. Причина: стороны a, c и b, d должны быть попарно равны, углы A, C и B, D должны быть попарно равны\n"; }

std::string shapeErrorRhomb::what() { return "Ошибка создания фигуры. Причина: все стороны должны быть равны, углы A, C и B, D должны быть попарно равны\n"; }

