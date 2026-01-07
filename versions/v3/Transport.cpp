//объявление заголовочных файлов
#include <iostream>
#include <fstream>
#include "Transport.h"

//пространство имён
using namespace std;

/*===========================================================================
 * Функции для класса "транспортное средство"
 *
 *
 * ===========================================================================
 */

Transport::Transport() {}

bool Transport::set_state_number(QString s)
{
    if (s.size() > 0)
    {
        state_number = s;
        return true;
    } else return false;
}

bool Transport::set_vin_number(QString s)
{
    if (s.size() > 0)
    {
        vin_number = s;
        return true;
    } else return false;
}

bool Transport::set_year(QString s)
{
    try
    {
        if (s.toUInt() >= 0)
        {
            year = s.toUInt();
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

void Transport::set_type_repairs(QString s)
{
    type_repairs = s;
}

void Transport::set_type_work(QString s)
{
   type_work = s;
}

QString Transport::get_state_number()
{
    return state_number;
}

QString Transport::get_vin_number()
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

QString Transport::get_type_repairs()
{
    return type_repairs;
}

QString Transport::get_type_work()
{
    return  type_work;
}

QString Transport::get_type()
{
    return type;
}

QString Transport::get(QString team)
{
    return "";
}

bool Transport::input(QTextStream &file)
{
    try
    {
        QString s_1, s_2, s_3;
        int rep;
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

QString Transport::get_text_output()
{
    QString text;
    text += "Тип: " + get_type() + ".\n";
    text += "Гос. номер: " + get_state_number() + ".\n";
    text += "Инв. номер: " + get_vin_number() + ".\n";
    text += "Год постановки на учет: " + QString::number(get_year()) + ".\n";
    if (get_repairs())
    {
        text += "Вид ремонта: " + get_type_repairs() + ".\n";
        text += "Вид работ: " + get_type_work() + ".\n";
    }
    return text;
}

void Transport::output(QTextStream &file)
{
    file << get_type() << " " << get_state_number() << " " << get_vin_number() << " " << get_year() << " " << get_repairs() << " ";
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

void Tractor::set_brand(QString s)
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

bool Tractor::set_engine_power(QString s)
{
    try
    {
        if (s.toDouble() >= 0)
        {
            engine_power = s.toDouble();
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

bool Tractor::set_residual_engine_life(QString s)
{
    try
    {
        if (s.toDouble() >= 0)
        {
            residual_engine_life = s.toDouble();
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

QString Tractor::get_brand()
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

QString Tractor::get(QString team)
{
    if (team == "brand") return get_brand();
    if (team == "engine_power") return QString::number(get_engine_power());
    if ((team == "residual_engine_life") || (team == "residual")) return QString::number(get_residual_engine_life());
    else return "";
}

bool Tractor::input(QTextStream &file)
{
    try
    {
        if (!Transport::input(file)) return false;
        QString s_1, s_2, s_3;
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

QString Tractor::get_text_output()
{
    QString text = Transport::get_text_output();
    text += "Марка: " + get_brand() + ".\n";
    text += "Мощность двигателя: " + QString::number(get_engine_power()) + ".\n";
    text += "Остаточный ресурс двигателя: " + QString::number(get_residual_engine_life()) + ".\n";
    return text;
}

void Tractor::output(QTextStream &file)
{
     Transport::output(file);
     file << get_brand() << " " << get_engine_power() << " " << get_residual_engine_life() << "\n";
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

void Bus::set_brand(QString s)
{
    brand = s;
}

void Bus::set_passenger_capacity(unsigned int i_inp)
{
    passenger_capacity = i_inp;
}

bool Bus::set_passenger_capacity(QString s)
{
    try
    {
        if (s.toUInt() >= 0)
        {
            passenger_capacity = s.toUInt();
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

bool Bus::set_mileage(QString s)
{
    try
    {
        if (s.toDouble() > 0)
        {
            mileage = s.toDouble();
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

bool Bus::set_residual_mileage(QString s)
{

    try
    {
        if (s.toDouble() >= 0)
        {
            residual_mileage = s.toDouble();
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

QString Bus::get_brand()
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

QString Bus::get(QString team)
{
    if (team == "brand") return get_brand(); else
    if (team == "passenger_capacity") return QString::number(get_passenger_capacity()); else
    if (team == "mileage") return QString::number(get_mileage()); else
    if ((team == "residual_mileage")  || (team == "residual")) return QString::number(get_residual_mileage()); else
        return "";
}

bool Bus::input(QTextStream &file)
{
    try
    {
        if (!Transport::input(file)) return false;
        QString s_1, s_2, s_3, s_4;
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

QString Bus::get_text_output()
{
    QString text = Transport::get_text_output();
    text += "Марка: " + get_brand() + ".\n";
    text += "Пассажировместимость: " + QString::number(get_passenger_capacity()) + ".\n";
    text += "Пробег: " + QString::number(get_mileage()) + ".\n";
    text += "Остаточный пробег до ремонта: " + QString::number(get_residual_mileage()) + ".\n";
    return text;
}

void Bus::output(QTextStream &file)
{
     Transport::output(file);
     file << get_brand() << " " << get_passenger_capacity() << " " << get_mileage() << " " << get_residual_mileage() << "\n";
}

/*===========================================================================
 * Функции для класса "грузовой автомобиль"
 *
 *
 * ===========================================================================
 */

Truck::Truck()
{
    type = "грузовой_автомобиль";
}

void Truck::set_brand(QString s)
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

bool Truck::set_payload(QString s)
{

    try
    {
        if (s.toDouble() >= 0)
        {
            payload = s.toDouble();
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

bool Truck::set_engine_power(QString s)
{

    try
    {
        if (s.toDouble() >= 0)
        {
            engine_power = s.toDouble();
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

bool Truck::set_mileage(QString s)
{
    try
    {
        if (s.toDouble() >= 0)
        {
            mileage = s.toDouble();
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

bool Truck::set_residual_mileage(QString s)
{

    try
    {
        if (s.toDouble() >= 0)
        {
            residual_mileage = s.toDouble();
            return true;
        } else return false;
    } catch (...)
    {
        return false;
    }
}

QString Truck::get_brand()
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

QString Truck::get(QString team)
{
    if (team == "brand") return get_brand(); else
    if (team == "payload") return QString::number(get_payload()); else
    if (team == "engine_power") return QString::number(get_engine_power()); else
    if (team == "mileage") return QString::number(get_mileage()); else
    if ((team == "residual_mileage") || (team == "residual")) return QString::number(get_residual_mileage()); else
        return "";
}

bool Truck::input(QTextStream &file)
{
    try
    {
        if (!Transport::input(file)) return false;
        QString s_1, s_2, s_3, s_4, s_5;
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
QString Truck::get_text_output()
{
    QString text = Transport::get_text_output();
    text += "Марка: " + get_brand() + ".\n";
    text += "Грузоподъемность: " + QString::number(get_payload()) + ".\n";
    text += "Мощность двигателя: " + QString::number(get_engine_power()) + ".\n";
    text += "Пробег: " + QString::number(get_mileage()) + ".\n";
    text += "Остаточный пробег до ремонта: " + QString::number(get_residual_mileage()) + ".\n";
    return text;
}

void Truck::output(QTextStream &file)
{
    Transport::output(file);
    file << get_brand() << " " << get_payload() << " " << get_engine_power() << " " << get_mileage() << " " << get_residual_mileage() << "\n";
}
