#ifndef TRANSPORT_H
#define TRANSPORT_H

//объявление заголовочных файлов
#include <QFile>
#include <QTextStream>
#include <QString>

//пространство имён
using namespace std;

//транспортное средство
class Transport
{
private:
    //гос.номер
    QString state_number = "не задано";
    //инв.номер
    QString vin_number = "не задано";
    //год постановки на учет
    unsigned int year = 0;
    //наличие ремонта
    bool repairs = false;
    //вид ремонта
    QString type_repairs = "ремонт не проводился";
    //вид работ
    QString type_work = "работы не проводились";
public:
    Transport();
    bool set_state_number(QString s);
    bool set_vin_number(QString s);
    bool set_year(QString s);
    void set_year(unsigned int i_inp);
    void set_repairs(bool b);
    void set_type_repairs(QString s);
    void set_type_work(QString s);
    QString get_state_number();
    QString get_vin_number();
    unsigned int get_year();
    bool get_repairs();
    QString get_type_repairs();
    QString get_type_work();
    QString get_type();
    virtual QString get(QString team);
    virtual bool input(QTextStream &file);
    virtual QString get_text_output();
    virtual void output(QTextStream &file);
protected:
    QString type;
};

//трактор
class Tractor : public Transport
{
private:
    //марка
    QString brand;
    //мощность двигателя
    double engine_power = 0;
    //остаточный ресурс двигателя
    double residual_engine_life = 0;
public:
    Tractor();
    void set_brand(QString s);
    bool set_engine_power(double d);
    bool set_engine_power(QString s);
    bool set_residual_engine_life(double d);
    bool set_residual_engine_life(QString d);
    QString get_brand();
    double get_engine_power();
    double get_residual_engine_life();
    QString get(QString team);
    bool input(QTextStream &file);
    QString get_text_output();
    void output(QTextStream &file);
};

//автобус
class Bus:public Transport
{
private:
    //марка
    QString brand;
    //пассажировместимость
    unsigned int passenger_capacity = 0;
    //пробег
    double mileage = 0;
    //остаточный пробег до ремонта
    double residual_mileage = 0;
public:
    Bus();
    void set_brand(QString s);
    void set_passenger_capacity(unsigned int i_inp);
    bool set_passenger_capacity(QString s);
    bool set_mileage(double d);
    bool set_mileage(QString s);
    bool set_residual_mileage(double d);
    bool set_residual_mileage(QString s);
    QString get_brand();
    unsigned int get_passenger_capacity();
    double get_mileage();
    double get_residual_mileage();
    QString get(QString team);
    bool input(QTextStream &file);
    QString get_text_output();
    void output(QTextStream &file);
};

//грузовой автомобиль
class Truck:public Tractor
{
private:
    //марка
    QString brand;
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
    void set_brand(QString s);
    bool set_payload(double d);
    bool set_payload(QString s);
    bool set_engine_power(double d);
    bool set_engine_power(QString s);
    bool set_mileage(double d);
    bool set_mileage(QString s);
    bool set_residual_mileage(double d);
    bool set_residual_mileage(QString s);
    QString get_brand();
    double get_payload();
    double get_engine_power();
    double get_mileage();
    double get_residual_mileage();
    QString get(QString team);
    bool input(QTextStream &file);
    QString get_text_output();
    void output(QTextStream &file);
};

#endif // TRANSPORT_H
