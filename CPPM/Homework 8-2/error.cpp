#include "error.h"

std::string shapeError180::what()  { return "������ �������� ������. �������: ����� ����� ������ ���� ����� 180 ��������\n"; }

std::string shapeError90::what() { return "������ �������� ������. �������: ���� � ������ ���� 90 ��������\n"; }

std::string shapeErrorNotIsosceles::what() { return "������ �������� ������. �������: ������� a � c � ���� A � C ������ ���� �����\n"; }

std::string shapeErrorNotEqual::what() { return "������ �������� ������. �������: ��� ������� ������ ���� �����, ��� ���� ������ ���� 60 ��������\n"; }

std::string shapeErrorQuad::what() { return "������ �������� ������. �������: ����� ����� ������ ���� ����� 360 ��������\n"; }

std::string shapeErrorRect::what() { return "������ �������� ������. �������: ������� a,c � b,d ������ ���� ������� �����, ��� ���� ������ ���� 90 ��������\n"; }

std::string shapeErrorSquare::what() { return "������ �������� ������. �������: ��� ������� ������ ���� �����, ��� ���� ������ ���� 90 ��������\n"; }

std::string shapeErrorParall::what() { return "������ �������� ������. �������: ������� a, c � b, d ������ ���� ������� �����, ���� A, C � B, D ������ ���� ������� �����\n"; }

std::string shapeErrorRhomb::what() { return "������ �������� ������. �������: ��� ������� ������ ���� �����, ���� A, C � B, D ������ ���� ������� �����\n"; }

