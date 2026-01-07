#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP

//объявление заголовочных файлов
#include <fstream>

//пространство имён
using namespace std;

//транспортное средство
class Transport
{
private:
    //гос.номер
    string state_number = "не задано";
    //инв.номер
    string vin_number = "не задано";
    //год постановки на учет
    unsigned int year = 0;
    //наличие ремонта
    bool repairs = false;
    //вид ремонта
    string type_repairs = "ремонт не проводился";
    //вид работ
    string type_work = "работы не проводились";
public:
    Transport();
    bool set_state_number(string s);
    bool set_vin_number(string s);
    bool set_year(string s);
    void set_year(unsigned int i_inp);
    void set_repairs(bool b);
    void set_type_repairs(string s);
    void set_type_work(string s);
    string get_state_number();
    string get_vin_number();
    unsigned int get_year();
    bool get_repairs();
    string get_type_repairs();
    string get_type_work();
    string get_type();
    virtual string get(string team);
    virtual bool input(bool repair = false);
    virtual bool input(ifstream &file);
    virtual void output();
protected:
    string type;
};

//трактор
class Tractor : public Transport
{
private:
    //марка
    string brand;
    //мощность двигателя
    double engine_power = 0;
    //остаточный ресурс двигателя
    double residual_engine_life = 0;
public:
    Tractor();
    void set_brand(string s);
    bool set_engine_power(double d);
    bool set_engine_power(string s);
    bool set_residual_engine_life(double d);
    bool set_residual_engine_life(string d);
    string get_brand();
    double get_engine_power();
    double get_residual_engine_life();
    string get(string team);
    bool input(bool repair = false);
    bool input(ifstream &file);
    void output();
};

//автобус
class Bus:public Transport
{
private:
    //марка
    string brand;
    //пассажировместимость
    unsigned int passenger_capacity = 0;
    //пробег
    double mileage = 0;
    //остаточный пробег до ремонта
    double residual_mileage = 0;
public:
    Bus();
    void set_brand(string s);
    void set_passenger_capacity(unsigned int i_inp);
    bool set_passenger_capacity(string s);
    bool set_mileage(double d);
    bool set_mileage(string s);
    bool set_residual_mileage(double d);
    bool set_residual_mileage(string s);
    string get_brand();
    unsigned int get_passenger_capacity();
    double get_mileage();
    double get_residual_mileage();
    string get(string team);
    bool input(bool repair = false);
    bool input(ifstream &file);
    void output();
};

//грузовой автомобиль
class Truck:public Tractor
{
private:
    //марка
    string brand;
    //грузоподъемность
    double payload;
    //мощность двигателя
    double engine_power = 0;
    //пробег
    double mileage = 0;
    //остаточный пробег до ремонта
    double residual_mileage = 0;
public:
    Truck();
    void set_brand(string s);
    bool set_payload(double d);
    bool set_payload(string s);
    bool set_engine_power(double d);
    bool set_engine_power(string s);
    bool set_mileage(double d);
    bool set_mileage(string s);
    bool set_residual_mileage(double d);
    bool set_residual_mileage(string s);
    string get_brand();
    double get_payload();
    double get_engine_power();
    double get_mileage();
    double get_residual_mileage();
    string get(string team);
    bool input(bool repair = false);
    bool input(ifstream &file);
    void output();
};

#endif // TRANSPORT_HPP
