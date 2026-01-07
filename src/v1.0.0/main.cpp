//объявление заголовочных файлов
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "Transport.hpp"

//пространство имён
using namespace std;

//глобальные переменные
vector <Transport*> transport;

//окно для вывода ошибки
void win_error(string text_error)
{
    system("cls");
    system("color 4F");
    cout << "\a";
    cout << "        ОШИБКА ПРОГРАММЫ! \n"
         << "===========================================================================\n"
         << "  " << text_error << "\n"
         << "===========================================================================\n";
    system("pause");
    system("color F0");
    return;
}

//окно для ввода данных о новом транспортном средстве (1)
void win_input_transport()
{
    system("cls");
    cout << "        1. ВВОД ДАННЫХ О НОВОМ ТРАНСПОРТНОМ СРЕДСТВЕ \n"
         << "===========================================================================\n";
    string type;
    Transport *input_transport = 0;
    cout << "Введите тип транспорта: ";
    getline(cin, type);
    if (type == "трактор") input_transport = new Tractor; else
    if (type == "автобус") input_transport = new Bus; else
    if (type == "грузовой автомобиль") input_transport = new Truck; else
    {
        win_error("Введен недопустимый тип транспорта. \n  Попробуйте ввести: трактор, автобус или грузовой автомобиль.");
        return;
    }
    if (!input_transport->input())
    {
        win_error("При вводе произошла ошибка.");
        delete input_transport;
        return;
    } else transport.emplace_back(input_transport);
    cout << "===========================================================================\n";
    system("pause");
    return;
}

//окно для ввода в состав транспортного средства после ремонта (2)
void win_input_renovated()
{
    system("cls");
    cout << "        2. ВВОД В СОСТАВ ТРАНСПОРТНОГО СРЕДСТВА ПОСЛЕ РЕМОНТА  \n"
         << "===========================================================================\n";
    string type;
    Transport *input_transport = 0;
    cout << "Введите тип транспорта: ";
    getline(cin, type);
    if (type == "трактор") input_transport = new Tractor; else
    if (type == "автобус") input_transport = new Bus; else
    if (type == "грузовой автомобиль") input_transport = new Truck; else
    {
        win_error("Введен недопустимый тип транспорта. \n  Попробуйте ввести: трактор, автобус или грузовой автомобиль.");
        return;
    }
    if (!input_transport->input(true))
    {
        win_error("При вводе произошла ошибка.");
        delete input_transport;
        return;
    } else transport.emplace_back(input_transport);
    cout << "===========================================================================\n";
    system("pause");
    return;
}

//окно для исключение информации о списываемых транспортных средствах (3)
void win_delete()
{
    if (transport.size() > 0)
    {
        system("cls");
        cout << "        3. ИСКЛЮЧЕНИЕ ИНФОРМАЦИИ О СПИСЫВАЕМЫХ ТРАНСПОРТНЫХ СРЕДСТВАХ  \n"
             << "===========================================================================\n";
        cout << "Введите гос. номер транспорта: ";
        string number;
        getline(cin, number);
        for (unsigned int i = 0; i < transport.size(); i++)
            if (transport[i]->get_state_number() == number)
            {

                transport[i]->output();
                delete transport[i];
                transport.erase(transport.begin() + i);
                cout << "Удаление транспортного средства прошло успешно. \n";
                cout << "===========================================================================\n";
                system("pause");
                return;
            }
        win_error("Не удалось найти транспортное средство.");
        return;
    } else win_error("База данных пустая.");
}

//окно для вывода полного списка транспортных средств (4)
void win_output_all_transport()
{
    if (transport.size() > 0)
    {
        system("cls");
        cout << "        4. ВЫВОД ПОЛНОГО СПИСКА ТРАНСПОРТНЫХ СРЕДСТВ \n"
             << "===========================================================================\n";
        for (unsigned int i = 0; i < transport.size(); i++)
        {
            transport[i]->output();
            cout << "===========================================================================\n";
        }
        system("pause");
        return;
    } else win_error("База данных пустая.");
}

//окно для вывода полного списка транспортных средств (5)
void win_output_resource()
{
    if (transport.size() > 0)
    {
        system("cls");
        cout << "    5. ВЫВОД СПИСКА ТРАНСПОРТНЫХ СРЕДСТВ С ОСТАТОЧНЫМ РЕСУРСОМ МЕНЕЕ ЗАДАННОГО  \n"
             << "===========================================================================\n";
        string s;
        double residual;
        cout << "Введите остаточный ресурс: ";
        getline(cin, s);
        try
        {
            residual = stod(s);
        } catch (...) {
            win_error("Введено недопустимое значение.");
        }
        for (unsigned int i = 0; i < transport.size(); i++)
            if (transport[i]->get_type() == "трактор")
            {
                if (stod(transport[i]->get("residual_engine_life")) < residual)
                {
                    transport[i]->output();
                    cout << "===========================================================================\n";
                }
            } else
            if ((transport[i]->get_type() == "автобус") || (transport[i]->get_type() == "грузовой автомобиль"))
                if (stod(transport[i]->get("residual_mileage")) < residual)
                {
                    transport[i]->output();
                    cout << "===========================================================================\n";
                }
        system("pause");
        return;
    } else win_error("База данных пустая.");
}

//окно для вывода списка транспортных средств заданного типа (6)
void win_outpyt_transport()
{
    if (transport.size() > 0)
    {
        system("cls");
        cout << "        6. ВЫВОД СПИСКА ТРАНСПОРТНЫХ СРЕДСТВ ЗАДАННОГО ТИПА  \n"
             << "===========================================================================\n";
        cout << "Введите тип транспорта: ";
        string type;
        bool search = false;
        getline(cin, type);
        if ((type != "трактор") && (type != "автобус") && (type != "грузовой автомобиль"))
        {
            win_error("Введен недопустимый тип транспорта. \n  Попробуйте ввести: трактор, автобус или грузовой автомобиль.");
            return;
        }
        for (unsigned int i = 0; i < transport.size(); i++)
            if (transport[i]->get_type() == type)
            {
                transport[i]->output();
                search = true;
                cout << "===========================================================================\n";
            }
        if (!search)
        {
            cout << "В базе данных нет сведений о транспорте данного типа. \n";
            cout << "===========================================================================\n";
        }
        system("pause");
        return;
    } else win_error("База данных пустая.");
}

//Ввод данных из файла. (7)
void win_read_file()
{
    system("cls");
    cout << "        7. ВВОД ДАННЫХ ИЗ ФАЙЛА  \n"
         << "===========================================================================\n";
    ifstream file("transport.txt");
    string type;
    Transport *input_transport = 0;
    if (file)
    {
        while (!file.eof())
        {
            file >> type;
            if (type == "трактор") input_transport  = new Tractor; else
            if (type == "автобус") input_transport  = new Bus; else
            if (type == "грузовой_автомобиль") input_transport  = new Truck; else
            {
                win_error("Ошибка определения типа транспорта.");
                return;
            }
            if (input_transport ->input(file))
            {
                transport.emplace_back(input_transport);
            } else
            {
                win_error("При чтении файла произошла ошибка.");
                delete input_transport;
                return;
            }
        }
        cout << "Чтение файла прошло успешно. \n";
        cout << "===========================================================================\n";
        system("pause");
        return;
    } else
    {
        win_error("Программа не смогла обнаружить файл базы данных.");
        return;
    }
}

//окно для открытия помощи (8)
void win_info()
{
    system("cls");
    cout << "        ИНФОРМАЦИЯ О ПРОГРАММЕ\n"
         << "===========================================================================\n"
         << "  Информация: Система управления автотранспортного предприятия. \n"
         << "  Разработчик: Кузнецов И.К. \n"
         << "  Дата создания: 21.05.2022 \n"
         << "===========================================================================\n";
    system("pause");
    return;
}

//главная программа
int main()
{
    //настройка программы
    system("color F0");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {80, 1000};
    SetConsoleScreenBufferSize(hWnd, bufferSize);
    //переменная для вариант ответа
    string s;
    //бесконечный цикл для работы меню
    while (true)
    {
        system("cls");
        cout << "        МЕНЮ \n"
             << "===========================================================================\n"
             << "  (1) Ввод данных о новом транспортном средстве. \n"
             << "  (2) Ввод в состав транспортного средства после ремонта. \n"
             << "  (3) Исключение информации о списываемых транспортных средствах. \n"
             << "  (4) Вывод полного списка транспортных средств. \n"
             << "  (5) Вывод списка  транспортных средств с остаточным ресурсом менее заданного.\n"
             << "  (6) Вывод списка транспортных средств заданного типа. \n"
             << "  (7) Ввод данных из файла. \n"
             << "  (8) Информация о программе. \n"
             << "  (0) Выход из программы. \n"
             << "===========================================================================\n";
        //обработка ответа
        getline(cin, s);
        if (s == "1") win_input_transport(); else
        if (s == "2") win_input_renovated(); else
        if (s == "3") win_delete(); else
        if (s == "4") win_output_all_transport(); else
        if (s == "5") win_output_resource(); else
        if (s == "6") win_outpyt_transport(); else
        if (s == "7") win_read_file(); else
        if (s == "8") win_info(); else
        if (s == "0") return 0; else win_error("Ошибка! Неправильно введена команда.");
    }
}
