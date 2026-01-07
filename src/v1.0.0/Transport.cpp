//объявление заголовочных файлов
#include <iostream>
#include <fstream>
#include "Transport.hpp"

//пространство имён
using namespace std;

/*===========================================================================
 * Функции для класса "транспортное средство"
 *
 *
 * ===========================================================================
 */

Transport::Transport() {}

bool Transport::set_state_number(string s)
{
    if (s.size() > 0)
    {
        state_number = s;
        return true;
    } else return false;
}

bool Transport::set_vin_number(string s)
{
    if (s.size() > 0)
    {
        vin_number = s;
        return true;
    } else return false;
}

bool Transport::set_year(string s)
{
    try
    {
        if (stoi(s) >= 0)
        {
            year = stoi(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

void Transport::set_year(unsigned int i_inp)
{
    year = i_inp;
}

void Transport::set_repairs(bool b)
{
    repairs = b;
}

void Transport::set_type_repairs(string s)
{
    type_repairs = s;
}

void Transport::set_type_work(string s)
{
   type_work = s;
}

string Transport::get_state_number()
{
    return state_number;
}

string Transport::get_vin_number()
{
    return vin_number;
}

unsigned int Transport::get_year()
{
    return  year;
}

bool Transport::get_repairs()
{
    return repairs;
}

string Transport::get_type_repairs()
{
    return type_repairs;
}

string Transport::get_type_work()
{
    return  type_work;
}

string Transport::get_type()
{
    return type;
}

string Transport::get(string team)
{
    return "";
}

bool Transport::input(bool rep)
{
    string s;
    cout << "Введите гос. номер: ";
    getline(cin, s);
    if (!set_state_number(s)) return false;
    cout << "Введите инв. номер: ";
    getline(cin, s);
    if (!set_vin_number(s)) return false;
    cout << "Введите год постановки на учет: ";
    getline(cin, s);
    if (!set_year(s)) return false;
    if (rep)
    {
        set_repairs(true);
        cout << "Введите вид ремонта: ";
        getline(cin, s);
        set_type_repairs(s);
        cout << "Введите вид работ: ";
        getline(cin, s);
        set_type_work(s);
    }
    return true;
}

bool Transport::input(ifstream &file)
{
    try
    {
        string s_1, s_2, s_3;
        bool rep;
        file >> s_1 >> s_2 >> s_3 >> rep;
        if (!set_state_number(s_1)) return false; else
        if (!set_vin_number(s_2)) return false;  else
        if (!set_year(s_3)) return false; else
        if (rep)
        {
            file >> s_1 >> s_2;
            set_repairs(true);
            set_type_repairs(s_1);
            set_type_work(s_2);
        }
        return true;
    } catch (...)
    {
        return false;
    }
}

void Transport::output()
{
    cout << "Тип: " << get_type() << ".\n"
         << "Гос. номер: " << get_state_number() << ".\n"
         << "Инв. номер: " << get_vin_number() << ".\n"
         << "Год постановки на учет: " << get_year() << ".\n";
    if (get_repairs())
    {
        cout << "Вид ремонта: " << get_type_repairs() << ".\n"
             << "Вид работ: " << get_type_work() << ".\n";
    }
}

/*===========================================================================
 * Функции для класса "трактор"
 *
 *
 * ===========================================================================
 */


Tractor::Tractor()
{
    type = "трактор";
}

void Tractor::set_brand(string s)
{
    brand = s;
}

bool Tractor::set_engine_power(double d)
{
    if (d >= 0)
    {
        engine_power = d;
        return true;
    } else return false;
}

bool Tractor::set_engine_power(string s)
{
    try
    {
        if (stod(s) >= 0)
        {
            engine_power = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

bool Tractor::set_residual_engine_life(double d)
{
    if (d >= 0)
    {
        residual_engine_life = d;
        return true;
    } else return false;
}

bool Tractor::set_residual_engine_life(string s)
{
    try
    {
        if (stod(s) >= 0)
        {
            residual_engine_life = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

string Tractor::get_brand()
{
    return  brand;
}

double Tractor::get_engine_power()
{
    return engine_power;
}

double Tractor::get_residual_engine_life()
{
    return residual_engine_life;
}

string Tractor::get(string team)
{
    if (team == "brand") return get_brand();
    if (team == "engine_power") return to_string(get_engine_power());
    if (team == "residual_engine_life") return to_string(get_residual_engine_life());
    else return "";
}

bool Tractor::input(bool repair)
{
    if (!Transport::input(repair)) return false;
    string s;
    cout << "Введите марка: ";
    getline(cin, s);
    set_brand(s);
    cout << "Введите мощность двигателя: ";
    getline(cin, s);
    if (!set_engine_power(s)) return false;
    cout << "Введите остаточный ресурс двигателя: ";
    getline(cin, s);
    if (!set_residual_engine_life(s)) return false;
    return true;
}

bool Tractor::input(ifstream &file)
{
    try
    {
        if (!Transport::input(file)) return false;
        string s_1, s_2, s_3;
        file >> s_1 >> s_2 >> s_3;
        set_brand(s_1);
        if (!set_engine_power(s_2)) return false;
        if (!set_residual_engine_life(s_3)) return false;
        return true;
    } catch (...)
    {
        return false;
    }
}

void Tractor::output()
{
    Transport::output();
    cout << "Марка: " << get_brand() << ".\n"
         << "Мощность двигателя: " << get_engine_power() << ".\n"
         << "Остаточный ресурс двигателя: " << get_residual_engine_life() << ".\n";
}


/*===========================================================================
 * Функции для класса "автобус"
 *
 *
 * ===========================================================================
 */


Bus::Bus()
{
    type = "автобус";
}

void Bus::set_brand(string s)
{
    brand = s;
}

void Bus::set_passenger_capacity(unsigned int i_inp)
{
    passenger_capacity = i_inp;
}

bool Bus::set_passenger_capacity(string s)
{
    try
    {
        if (stoi(s) >= 0)
        {
            passenger_capacity = stoi(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

bool Bus::set_mileage(double d)
{
    if (d >= 0)
    {
        mileage = d;
        return true;
    } return false;
}

bool Bus::set_mileage(string s)
{
    try
    {
        if (stod(s) > 0)
        {
            mileage = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

bool Bus::set_residual_mileage(double d)
{
    if (d >= 0)
    {
        residual_mileage = d;
        return true;
    } return false;
}

bool Bus::set_residual_mileage(string s)
{

    try
    {
        if (stod(s) >= 0)
        {
            residual_mileage = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

string Bus::get_brand()
{
    return brand;
}

unsigned int Bus::get_passenger_capacity()
{
    return passenger_capacity;
}

double Bus::get_mileage()
{
    return mileage;
}

double Bus::get_residual_mileage()
{
    return residual_mileage;
}

string Bus::get(string team)
{
    if (team == "brand") return get_brand(); else
    if (team == "passenger_capacity") return to_string(get_passenger_capacity()); else
    if (team == "mileage") return to_string(get_mileage()); else
    if (team == "residual_mileage") return to_string(get_residual_mileage()); else
        return "";
}

bool Bus::input(bool rep)
{
    if (!Transport::input(rep)) return false;
    string s;
    cout << "Введите марка: ";
    getline(cin, s);
    set_brand(s);
    cout << "Введите пассажировместимость: ";
    getline(cin, s);
    if (!set_passenger_capacity(s)) return false;
    cout << "Введите пробег: ";
    getline(cin, s);
    if (!set_mileage(s)) return false;
    cout << "Введите остаточный пробег до ремонта: ";
    getline(cin, s);
    if (!set_residual_mileage(s)) return false;
    return true;
}

bool Bus::input(ifstream &file)
{
    try
    {
        if (!Transport::input(file)) return false;
        string s_1, s_2, s_3, s_4;
        file >> s_1 >> s_2 >> s_3 >> s_4;
        set_brand(s_1);
        if (!set_passenger_capacity(s_2)) return false; else
        if (!set_mileage(s_3)) return false; else
        if (!set_residual_mileage(s_4)) return false; else
            return true;
    } catch (...)
    {
        return false;
    }
}

void Bus::output()
{
    Transport::output();
    cout << "Марка: " << get_brand() << ".\n"
         << "Пассажировместимость: " << get_passenger_capacity() << ".\n"
         << "Пробег: " << get_mileage() << ".\n"
         << "Остаточный пробег до ремонта: " << get_residual_mileage() << ".\n";
}

/*===========================================================================
 * Функции для класса "грузовой автомобиль"
 *
 *
 * ===========================================================================
 */

Truck::Truck()
{
    type = "грузовой автомобиль";
}

void Truck::set_brand(string s)
{
    brand = s;
}

bool Truck::set_payload(double d)
{
    if (d >= 0)
    {
        payload = d;
        return true;
    } else return false;
}

bool Truck::set_payload(string s)
{

    try
    {
        if (stod(s) >= 0)
        {
            payload = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

bool Truck::set_engine_power(double d)
{
    if (d >= 0)
    {
        engine_power = d;
        return true;
    } else return false;
}

bool Truck::set_engine_power(string s)
{

    try
    {
        if (stod(s) >= 0)
        {
            engine_power = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

bool Truck::set_mileage(double d)
{
    if (d >= 0)
    {
        mileage = d;
        return true;
    } else return false;
}

bool Truck::set_mileage(string s)
{
    try
    {
        if (stod(s) >= 0)
        {
            mileage = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

bool Truck::set_residual_mileage(double d)
{
    if (d >= 0)
    {
        residual_mileage = d;
        return true;
    } else return false;
}

bool Truck::set_residual_mileage(string s)
{

    try
    {
        if (stod(s) >= 0)
        {
            residual_mileage = stod(s);
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

string Truck::get_brand()
{
    return brand;
}

double Truck::get_payload()
{
    return payload;
}

double Truck::get_engine_power()
{
    return engine_power;
}

double Truck::get_mileage()
{
    return mileage;
}

double Truck::get_residual_mileage()
{
    return residual_mileage;
}

string Truck::get(string team)
{
    if (team == "brand") return get_brand(); else
    if (team == "payload") return to_string(get_payload()); else
    if (team == "engine_power") return to_string(get_engine_power()); else
    if (team == "mileage") return to_string(get_mileage()); else
    if (team == "residual_mileage") return to_string(get_residual_mileage()); else
        return "";
}

bool Truck::input(bool rep)
{
    if (!Transport::input(rep)) return false;
    string s;
    cout << "Введите марка: ";
    getline(cin, s);
    set_brand(s);
    cout << "Введите грузоподъемность: ";
    getline(cin, s);
    if (!set_payload(s)) return false;
    cout << "Введите мощность двигателя: ";
    getline(cin, s);
    if (!set_engine_power(s)) return false;
    cout << "Введите пробег: ";
    getline(cin, s);
    if (!set_mileage(s)) return false;
    cout << "Введите остаточный пробег до ремонта: ";
    getline(cin, s);
    if (!set_residual_mileage(s)) return false;
    return true;
}

bool Truck::input(ifstream &file)
{
    try
    {
        if (!Transport::input(file)) return false;
        string s_1, s_2, s_3, s_4, s_5;
        file >> s_1 >> s_2 >> s_3 >> s_4 >> s_5;
        set_brand(s_1);
        if (!set_payload(s_2)) return false;
        if (!set_engine_power(s_3)) return false;
        if (!set_mileage(s_4)) return false;
        if (!set_residual_mileage(s_5)) return false;
        return true;
    } catch (...)
    {
        return false;
    }
}

void Truck::output()
{
    Transport::output();
    cout << "Марка: " << get_brand() << ".\n"
         << "Грузоподъемность: " << get_payload() << ".\n"
         << "Мощность двигателя: " << get_engine_power() << ".\n"
         << "Пробег: " << get_mileage() << ".\n"
         << "Остаточный пробег до ремонта: " << get_residual_mileage() << ".\n";
}
