#include <iostream>

class createShape {
public:
    createShape(std::string name_ = "Фигура", int side_ = 0) {
        name = name_;
        side = side_;
    }
    std::string getName() { return name; }

    virtual void info() {
        std::cout << name << ": " << std::endl;
    }

private:
    std::string name;
    int side;
};

class createTriangle : public createShape {
public:
    createTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c, std::string name_ = "Треугольник") : createShape(name_, 3) {
        side_a = s_a;
        side_b = s_b;
        side_c = s_c;

        corner_a = c_a;
        corner_b = c_b;
        corner_c = c_c;
    }

    int get_side_a() { return side_a; }
    int get_side_b() { return side_b; }
    int get_side_c() { return side_c; }

    int get_corner_a() { return corner_a; }
    int get_corner_b() { return corner_b; }
    int get_corner_c() { return corner_c; }

    void info() override {
        createShape::info();
        std::cout << "Стороны: a = " << get_side_a() << ", b = " << get_side_b() << ", c = " << get_side_c() << std::endl;
        std::cout << "Углы: A = " << get_corner_a() << ", B = " << get_corner_b() << ", C = " << get_corner_c() << std::endl;
        std::cout << std::endl;
    }

private:
    int side_a;
    int side_b;
    int side_c;

    int corner_a;
    int corner_b;
    int corner_c;
};

class createRightTriangle : public createTriangle {
public:
    createRightTriangle(int s_a, int s_b, int s_c, int c_a, int c_b) : createTriangle(s_a, s_b, s_c, c_a, c_b, 90, "Прямоугольный треугольник") {
    }
};

class createIsoscelesTriangle : public createTriangle {
public:
    createIsoscelesTriangle(int s_a, int s_b, int c_a, int c_b) : createTriangle(s_a, s_b, s_b, c_a, c_b, c_b, "Равнобедренный треугольник") {
    }
};

class createEquilateralTriangle : public createTriangle {
public:
    createEquilateralTriangle(int s_a) : createTriangle(s_a, s_a, s_a, 60, 60, 60, "Равносторонний треугольник") {
    }
};

class createQuad : public createShape {
public:
    createQuad(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d, std::string name_ = "Четырехугольник") : createShape(name_, 4) {
        side_a = s_a;
        side_b = s_b;
        side_c = s_c;
        side_d = s_d;

        corner_a = c_a;
        corner_b = c_b;
        corner_c = c_c;
        corner_d = c_d;
    }

    int get_side_a() { return side_a; }
    int get_side_b() { return side_b; }
    int get_side_c() { return side_c; }
    int get_side_d() { return side_d; }

    int get_corner_a() { return corner_a; }
    int get_corner_b() { return corner_b; }
    int get_corner_c() { return corner_c; }
    int get_corner_d() { return corner_d; }

    void info() override {
        std::cout << getName() << ": " << std::endl;
        std::cout << "Стороны: a = " << get_side_a() << ", b = " << get_side_b() << ", c = " << get_side_c() << ", d = " << get_side_d() << std::endl;
        std::cout << "Углы: A = " << get_corner_a() << ", B = " << get_corner_b() << ", C = " << get_corner_c() << ", D = " << get_corner_d() << std::endl;
        std::cout << std::endl;
    }

private:
    int side_a;
    int side_b;
    int side_c;
    int side_d;

    int corner_a;
    int corner_b;
    int corner_c;
    int corner_d;
};

class createRectangle : public createQuad {
public:
    createRectangle(int s_a, int s_d) : createQuad(s_a, s_d, s_a, s_d, 90, 90, 90, 90, "Прямоугольник") {
    }
};

class createSquare : public createQuad {
public:
    createSquare(int s_a) : createQuad(s_a, s_a, s_a, s_a, 90, 90, 90, 90, "Квадрат") {
    }
};

class createParallelogram : public createQuad {
public:
    createParallelogram(int s_a, int s_d, int c_a, int c_d) : createQuad(s_a, s_d, s_a, s_d, c_a, c_d, c_a, c_d, "Параллелограмм") {
    }
};

class createRhomd : public createQuad {
public:
    createRhomd(int s_a, int c_a, int c_d) : createQuad(s_a, s_a, s_a, s_a, c_a, c_d, c_a, c_d, "Ромб") {
    }
};

void printInfo(createShape* shape) {
    shape->info();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    createTriangle triangle(5, 5, 2, 80, 30, 70);
    printInfo(&triangle);

    createRightTriangle right_triangle(5, 3, 4, 30, 60);

    createIsoscelesTriangle isosceles_triangle(10, 5, 90, 45);

    createEquilateralTriangle equal_teiangle(13);

    createQuad quad(10, 20, 40, 22, 80, 130, 70, 120);

    createRectangle rectaingle(40, 20);

    createSquare square(15);
    printInfo(&square);
    
    createParallelogram parall(10, 20, 100, 80);
    printInfo(&parall);

    createRhomd rhomd(10, 60, 100);
}
