#include <iostream>
#include <fstream>
#include <stack>
#include <queue>


int** create_array(int &size) {
    std::ifstream file("in.txt");
    if (!(file.is_open())) {
        std::cout << "File did not opened!" << std::endl;
        return 0;
    }

    file >> size;

    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> arr[i][j];
        }
    }

    file.close();

    return arr;
}

void printGraph(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void dfs(int size, int** arr) {
    system("cls");
    int count = 0;
    bool* vertexes = new bool[size] {false};
    std::stack<int> stack;
    stack.push(0);

    std::cout << "Порядок обхода вершин: ";
    while (!(stack.empty())) {
        int top = stack.top();
        stack.pop();

        if (vertexes[top]) {
            continue;
        }
        vertexes[top] = true;

        for (int i = size - 1; i >= 0; i--) {
            if (arr[top][i] == 1 && !vertexes[i]) {
                stack.push(i);
            }
        }
        std::cout << ++top << " ";
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    delete[] vertexes;
}

void bfs(int size, int** arr) {
    system("cls");
    int userInput = 0;
    std::cout << "В графе 7 вершин. Введите номер вершины, с которой начнётся обход: ";
    do
    {        
        std::cin >> userInput;
        if (std::cin.fail() || userInput < 1 || userInput > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            system("cls");
            std::cout << "Некорректный ввод! Введите число от 1 до 7: ";
            continue;
        }
        else break;
    } while (true);
    

    int count = 0;
    bool* vertexes = new bool[size] {false};
    std::queue<int> queue;
    queue.push(userInput - 1);

    std::cout << "Порядок обхода вершин: ";
    while (!queue.empty()) {
        int top = queue.front();
        queue.pop();

        vertexes[top] = true;

        for (int i = 0; i < size; i++) {
            if (arr[top][i] == 1 && !vertexes[i]) {
                queue.push(i);
                vertexes[i] = true;
            }
        }
        if (count < size) {
            std::cout << ++top << " ";
        }        
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    delete[] vertexes;
    
}

void isCyclyc(int size, int** arr) {
    system("cls");
    bool* vertexes = new bool[size] {false};
    std::stack<int> stack;
    stack.push(0);

    int cycl = 0;

    while (!(stack.empty())) {
        int top = stack.top();
        stack.pop();

        if (vertexes[top]) {
            cycl = 1;
        }
        vertexes[top] = true;

        for (int i = size - 1; i >= 0; i--) {
            if (arr[top][i] == 1 && !vertexes[i]) {
                stack.push(i);
            }
        }
    }

    printGraph(arr, size);

    if (cycl) {
        std::cout << "В графе есть цикл!";
    }
    else { 
        std::cout << "В графе нет циклов!";
    }

    std::cout << std::endl;
    system("pause");
    system("cls");

    delete[] vertexes;
}


int main()
{
    setlocale(LC_ALL, "rus");

    int size = 0;
    int** arr = create_array(size);
    int userAct = 0;    

    do
    {        
        std::cout << "1. Обход графа в глубину" << std::endl;
        std::cout << "2. Обход графа в ширину" << std::endl;
        std::cout << "3. Поиск цикла" << std::endl;
        std::cout << "0. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> userAct;
    
        switch (userAct)
        {
        case 1:
            dfs(size, arr);
            break;
        case 2:
            bfs(size, arr);
            break;
        case 3:            
            isCyclyc(size, arr);
            break;
        default:
            break;
        }
    } while (userAct != 0); 

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}