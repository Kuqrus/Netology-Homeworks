#include <iostream>

class createShape {
public:
    createShape(std::string name_ = "Фигура", int side_ = 0) {
        name = name_;
        side = side_;
    }
    std::string getName() { return name; }
    int getSide() { return side; }

    virtual bool check() {
        if (side == 0) {
            return true;
        }
        else return false;
    }

    virtual void printInfo() {
        std::cout << name << ": " << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << side << std::endl;
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

    bool check() override {
        int corner_check = corner_a + corner_b + corner_c;
        if (getSide() == 3 && corner_check == 180) {
            return true;
        }
        else return false;
    }

    void printInfo() override {
        createShape::printInfo();
        std::cout << "Стороны: a = " << side_a << ", b = " << side_b << ", c = " << side_c << std::endl;
        std::cout << "Углы: A = " << corner_a << ", B = " << corner_b << ", C = " << corner_c << std::endl;
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

    bool check() override {
        if (createTriangle::check()) {
            if (get_corner_a() == 90 || get_corner_b() == 90 || get_corner_c() == 90) {
                return true;
            }
            else return false;
        }
        else return false;
    }

};

class createIsoscelesTriangle : public createTriangle {
public:
    createIsoscelesTriangle(int s_a, int s_b, int c_a, int c_b) : createTriangle(s_a, s_b, s_b, c_a, c_b, c_b, "Равнобедренный треугольник") {
    }

    bool check() override {
        if (createTriangle::check()) {
            if (get_corner_a() == get_corner_c() && get_side_a() == get_side_c()) {
                return true;
            }
            else if (get_corner_b() == get_corner_c() && get_side_b() == get_side_c()) {
                return true;
            }
            else if (get_corner_a() == get_corner_b() && get_side_a() == get_side_b()) {
                return true;
            }
            else return false;
        }        
        else return false;
    }

};

class createEquilateralTriangle : public createTriangle {
public:
    createEquilateralTriangle(int s_a) : createTriangle(s_a, s_a, s_a, 60, 60, 60, "Равносторонний треугольник") {
    }
    bool check() override {
        if (createTriangle::check()) {
            if (get_corner_a() == 60 && get_corner_b() == 60 && get_corner_c() == 60 && get_side_a() == get_side_b() && get_side_b() == get_side_c()) {
                return true;
            }
            else return false;
        }
        else return false;        
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

    bool check() override {
        int corner_check = corner_a + corner_b + corner_c + corner_d;
        if (getSide() == 4 && corner_check == 360) {
            return true;
        }
        else return false;
    }

    void printInfo() override {
        createShape::printInfo();
        std::cout << "Стороны: a = " << side_a << ", b = " << side_b << ", c = " << side_c << ", d = " << side_d << std::endl;
        std::cout << "Углы: A = " << corner_a << ", B = " << corner_b << ", C = " << corner_c << ", D = " << corner_d << std::endl;
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
    createRectangle(int s_a, int s_d) : createQuad(s_a, s_d, s_a, s_d, 90, 90, 90, 90, "Прямоуголник") {
    }

    bool check() override {
        if (createQuad::check()) {
            if (get_corner_a() == 90 && get_corner_b() == 90 && get_corner_c() == 90 && get_corner_d() == 90) {
                if (get_side_a() == get_side_c() && get_side_b() == get_side_d()) {
                    return true;
                }
                else if (get_side_a() == get_side_b() && get_side_c() == get_side_d()) {
                    return true;
                }
                else if (get_side_a() == get_side_d() && get_side_c() == get_side_b()) {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
        
    }
};

class createSquare : public createQuad {
public:
    createSquare(int s_a) : createQuad(s_a, s_a, s_a, s_a, 90, 90, 90, 90, "Квадрат") {
    }

    bool check() override {
        if (createQuad::check()) {
            if (get_corner_a() == 90 && get_corner_b() == 90 && get_corner_c() == 90 && get_corner_d() == 90) {
                if (get_side_a() == get_side_b() && get_side_b() == get_side_c() && get_side_c() == get_side_d() && get_side_d() == get_side_a()) {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
};

class createParallelogram : public createQuad {
public:
    createParallelogram(int s_a, int s_d, int c_a, int c_d) : createQuad(s_a, s_d, s_a, s_d, c_a, c_d, c_a, c_d, "Параллелограмм") {
    }
    bool check() override {
        if (createQuad::check()) {
            if (get_corner_a() == get_corner_c() || get_corner_b() == get_corner_d()) {
                if (get_side_a() == get_side_c() || get_side_b() == get_side_d()) {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
};

class createRhomd : public createQuad {
public:
    createRhomd(int s_a, int c_a, int c_d) : createQuad(s_a, s_a, s_a, s_a, c_a, c_d, c_a, c_d, "Ромб") {
    }
    bool check() override {
        if (createQuad::check()) {
            if (get_corner_a() == get_corner_c() && get_corner_b() == get_corner_d()) {
                if (get_side_a() == get_side_b() && get_side_b() == get_side_c() && get_side_c() == get_side_d() && get_side_d() == get_side_a()) {
                    return true;
                }
                else return false;
            }
        }
        else return false;
    }
};

void printInfoFunc(createShape* shape) {
    shape->printInfo();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    createTriangle triangle(5, 5, 2, 80, 30, 70);
    printInfoFunc(&triangle);

    createRightTriangle right_triangle(5, 3, 4, 40, 60);

    createIsoscelesTriangle isosceles_triangle(10, 5, 90, 45);

    createEquilateralTriangle equal_triangle(13);

    createQuad quad(10, 20, 40, 22, 80, 130, 70, 120);

    createRectangle rectaingle(40, 20);

    createSquare square(30);

    createParallelogram parall(10, 20, 100, 80);
    printInfoFunc(&parall);

    createRhomd rhomd(10, 60, 100);

}