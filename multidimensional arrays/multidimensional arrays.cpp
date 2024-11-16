// 
// Задание 1. Напишите программу, которая 
// создает двухмерный массив и заполняет его по следующему
// принципу: пользователь вводит число (например, 3)
// первый элемент массивва принимает значение это числап, 
// последующий элемент массива принимает значение этого 
// числа умноженного на 2 (т.е. 6 для нашего примера), 
// третий элемент массива предыдущий элемент умноженный на
// 2 (т.е. 6*2-12 для нашего примера). Созданный массив вывести на экран
// 
//
/*
#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    //создаем двухмерный массив
    const int col{ 3 };
    const int row{ 3 };
    int arr[col][row];
    
    int x{ 2 }; //степень

    std::cout << "Добро пожаловать в программу создания двухмерного массива!\n";
    //просим пользователя ввести число
    std::cout << "Введите число: ";
    int number { 0 };
    std::cin >> number;

    //заполняем его по следующему принципу:
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (i == 0 && j == 0)
            {
                arr[i][j] = number;
            }
            else
            {
                int digit = (number*2) * pow(x, (i + j - 1) + i * 2);
                arr[i][j] = digit;
            }
        }
    }
    //выводим массив на экран
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << '\n';
    }
    return 0;
}
*/

// Задание 2. Напишите программу, которая создает 
// двухмерный массив и заполняет его по следующему
// принципу: пользователь вводит число (например 3) 
// первый элемент массива принмает значение этого 
// числа +1 (т.е. 4 для нашего примера), третий элемент
// массива предыдущий элемент +1 (т.е. 5 для нашего примера). 
// Созданный массив вывести на экран.
// 
// 
/*
#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    //создаем двухмерный массив
    const int col{ 3 };
    const int row{ 3 };
    int arr[col][row];
    //создаем счетчик
    int counter{ 0 };
    std::cout << "Добро пожаловать в программу создания двухмерного массива!\n";
    
    //просим пользователя ввести число
    std::cout << "Введите число: ";
    int number{ 0 };
    std::cin >> number;

    //заполняеv его по следующему принципу:
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (i == 0 && j == 0)
            {
                arr[i][j] = number; // заполняем [0][0] элемент массива 
            }
            else
            {
                ++counter; // увеличиваем счетчик на единицу
                arr[i][j] = number + counter; // заполняем остальные элементы массива
            }
        }
    }
    //выводим массив на экран
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << '\n';
    }
    return 0;
}
*/

// Задание 3. Сщздайте двухмерный массив. Заполните его
// случайными числами и покажите на экрвн. Пользователь
// выбирает количество сдвигов и положение (влево, вправо,
// вверх, вниз). Выполнить сдвиг массива и показать на
// экран полученный результат. Сдвиг циклический.
// 
// 
#include <iostream>
#include <random>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    //создаем двухмерный массив
    const int col{ 4 };
    const int row{ 4 };
    int arr[col][row];
    //создаем счетчик
    int counter{ 0 };
    std::cout << "Добро пожаловать в программу создания двухмерного массива!\n";

    //просим пользователя ввести число
    //std::cout << "Введите число: ";
    //int number{ 0 };
    //std::cin >> number;

    //заполняем его по следующему принципу:
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            //создаем генератор случайных чисел
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 19); //ограничение генератора от 10 до 99)
            //создаем временную переменную и передаем ей значение генератора случайых чисел
            int tmp_1 = dist(gen);
            //заполняем массив значениями из временной переменной
            arr[i][j] = tmp_1;
        }
    }
    //выводим массив на экран
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    int actions{ 0 };
    do
    {
        std::cout << "Выберите одно из действий:\n1 - сдвиг массива влево\n2 - сдвиг массива вправо\n3 - сдвиг массива вверх\n4 - сдвиг массива вниз\n";
        std::cin >> actions;
    } while (actions == 0 || actions >= 5);

    std::cout << "Укажите колличество сдвигов: ";
    int N{ 0 };
    std::cin >> N;

    if (actions == 1) {
        for (int k = 0; k < N; ++k) // цикл количества повторений действий
        {
            //сдвиг массива влево
            for (int i = 0; i < col; ++i)
            {
                int tmp{};
                for (int j = 0; j < std::size(arr[0]); ++j)
                {
                    if (j == 0)
                    {
                        tmp = arr[i][j];
                    }
                    if (j != std::size(arr[i]) - 1)
                    {
                        arr[i][j] = arr[i][j + 1];
                    }
                    if (j == std::size(arr[i]) - 1)
                    {
                        arr[i][j] = tmp;
                    }
                }
            }
        }
        //выводим массив на экран
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    else if (actions == 2)
    {
        //сдвиг массива вправо
        for (int k = 0; k < N; ++k) // цикл количества повторений действий
        {
            for (int i = 0; i < col; ++i)
            {
                int tmp{};
                for (int j = std::size(arr[i]) - 1; j > 0; --j)
                {
                    // сохраняем последний столбец
                    if (j == std::size(arr[i]) - 1)
                    {
                        tmp = arr[i][j];
                    }

                    // перемещаем столбцы

                    if (j > 0)
                    {
                        arr[i][j] = arr[i][j - 1];
                    }
                    //переносим последний столбец в начало
                    if (j == 0)
                    {
                        arr[i][j] = tmp;
                    }
                }
            }
        }

        //выводим массив на экран
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << '\n';
        }
        std::cout << '\n';


    }
    else if (actions == 3)
    {
        //сдвиг массива вверх
        for (int k = 0; k < N; ++k) // цикл количества повторений действий
        {
            for (int j = 0; j < col; ++j)
            {
                int tmp{};
                for (int i = 0; i < std::size(arr[0]); ++i)
                {
                    if (i == 0)
                    {
                        tmp = arr[i][j];
                    }
                    if (i != std::size(arr[j]) - 1)
                    {
                        arr[i][j] = arr[i + 1][j];
                    }
                    if (i == std::size(arr[j]) - 1)
                    {
                        arr[i][j] = tmp;
                    }
                }
            }
        }
        //выводим массив на экран
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    else if (actions == 4)
    {
        //сдвиг массива вниз
        for (int k = 0; k < N; ++k) // цикл количества повторений действий
        {
            for (int j = 0; j < col; ++j)
            {

                for (int i = std::size(arr[0]) - 1; i > 0; --i)
                {
                    int tmp{};
                    if (i == std::size(arr[0]) - 1)
                    {
                        tmp = arr[i][j];
                    }
                    if (i != 0)
                    {
                        arr[i][j] = arr[i - 1][j];
                    }
                    if (i == 0)
                    {
                        arr[i][j] = tmp;
                    }
                }
            }
        }
        //выводим массив на экран
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}

