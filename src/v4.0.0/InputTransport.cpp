#include "InputTransport.h"
#include "ui_InputTransport.h"

InputTransport::InputTransport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputTransport)
{
    ui->setupUi(this);
    //выключение ввода ремонта
    ui->lineEdit_type_repairs->setEnabled(false);
    ui->lineEdit_type_work->setEnabled(false);
    //выключение ввода автобуса
    ui->lineEdit_bus_brand->setEnabled(false);
    ui->doubleSpinBox_bus_mileage->setEnabled(false);
    ui->spinBox_bus_passenger_capacity->setEnabled(false);
    ui->doubleSpinBox_bus_residual_mileage->setEnabled(false);
    //выключение ввода грузовика
    ui->lineEdit_truck_brand->setEnabled(false);
    ui->doubleSpinBox_truck_mileage->setEnabled(false);
    ui->doubleSpinBox_truck_payload->setEnabled(false);
    ui->doubleSpinBox_truck_engine_power->setEnabled(false);
    ui->doubleSpinBox_truck_residual_mileage->setEnabled(false);
}

InputTransport::~InputTransport()
{
    delete ui;
}

void InputTransport::on_radioButton_repairs_false_clicked()
{
    ui->radioButton_repairs_true->setChecked(false);
    ui->lineEdit_type_repairs->setEnabled(false);
    ui->lineEdit_type_work->setEnabled(false);
}

void InputTransport::on_radioButton_repairs_true_clicked()
{
    ui->radioButton_repairs_false->setChecked(false);
    ui->lineEdit_type_repairs->setEnabled(true);
    ui->lineEdit_type_work->setEnabled(true);
}

void InputTransport::on_radioButton_tractor_clicked()
{
    //включение ввода трактора
    ui->lineEdit_tractor_brand->setEnabled(true);
    ui->doubleSpinBox_tractor_engine_power->setEnabled(true);
    ui->doubleSpinBox_tractor_residual_engine_life->setEnabled(true);
    //выключение ввода автобуса
    ui->radioButton_bus->setChecked(false);
    ui->lineEdit_bus_brand->setEnabled(false);
    ui->doubleSpinBox_bus_mileage->setEnabled(false);
    ui->spinBox_bus_passenger_capacity->setEnabled(false);
    ui->doubleSpinBox_bus_residual_mileage->setEnabled(false);
    //выключение ввода грузовика
    ui->radioButton_truck->setChecked(false);
    ui->lineEdit_truck_brand->setEnabled(false);
    ui->doubleSpinBox_truck_mileage->setEnabled(false);
    ui->doubleSpinBox_truck_payload->setEnabled(false);
    ui->doubleSpinBox_truck_engine_power->setEnabled(false);
    ui->doubleSpinBox_truck_residual_mileage->setEnabled(false);
}

void InputTransport::on_radioButton_bus_clicked()
{
    //выключение ввода трактора
    ui->radioButton_tractor->setChecked(false);
    ui->lineEdit_tractor_brand->setEnabled(false);
    ui->doubleSpinBox_tractor_engine_power->setEnabled(false);
    ui->doubleSpinBox_tractor_residual_engine_life->setEnabled(false);
    //включение ввода автобуса
    ui->lineEdit_bus_brand->setEnabled(true);
    ui->doubleSpinBox_bus_mileage->setEnabled(true);
    ui->spinBox_bus_passenger_capacity->setEnabled(true);
    ui->doubleSpinBox_bus_residual_mileage->setEnabled(true);
    //выключение ввода грузовика
    ui->radioButton_truck->setChecked(false);
    ui->lineEdit_truck_brand->setEnabled(false);
    ui->doubleSpinBox_truck_mileage->setEnabled(false);
    ui->doubleSpinBox_truck_payload->setEnabled(false);
    ui->doubleSpinBox_truck_engine_power->setEnabled(false);
    ui->doubleSpinBox_truck_residual_mileage->setEnabled(false);
}

void InputTransport::on_radioButton_truck_clicked()
{
    //выключение ввода трактора
    ui->radioButton_tractor->setChecked(false);
    ui->lineEdit_tractor_brand->setEnabled(false);
    ui->doubleSpinBox_tractor_engine_power->setEnabled(false);
    ui->doubleSpinBox_tractor_residual_engine_life->setEnabled(false);
    //выключение ввода автобуса
    ui->radioButton_bus->setChecked(false);
    ui->lineEdit_bus_brand->setEnabled(false);
    ui->doubleSpinBox_bus_mileage->setEnabled(false);
    ui->spinBox_bus_passenger_capacity->setEnabled(false);
    ui->doubleSpinBox_bus_residual_mileage->setEnabled(false);
    //включение ввода грузовика
    ui->lineEdit_truck_brand->setEnabled(true);
    ui->doubleSpinBox_truck_mileage->setEnabled(true);
    ui->doubleSpinBox_truck_payload->setEnabled(true);
    ui->doubleSpinBox_truck_engine_power->setEnabled(true);
    ui->doubleSpinBox_truck_residual_mileage->setEnabled(true);
}

void InputTransport::on_pushButton_save_clicked()
{
    if (inp_transport != 0) delete inp_transport;
    if (ui->radioButton_tractor->isChecked())
    {
        Tractor *inp_tractor  = new Tractor;
        inp_tractor->set_brand(ui->lineEdit_tractor_brand->text());
        inp_tractor->set_engine_power(ui->doubleSpinBox_tractor_engine_power->value());
        inp_tractor->set_residual_engine_life(ui->doubleSpinBox_tractor_residual_engine_life->value());
        inp_transport = inp_tractor;
    } else
    if (ui->radioButton_bus->isChecked())
    {
        Bus *inp_bus = new Bus;
        inp_bus->set_brand(ui->lineEdit_bus_brand->text());
        inp_bus->set_mileage(ui->doubleSpinBox_bus_mileage->value());
        inp_bus->set_residual_mileage(ui->doubleSpinBox_bus_mileage->value());
        inp_bus->set_passenger_capacity(ui->spinBox_bus_passenger_capacity->value());
        inp_transport = inp_bus;
    } else
    if (ui->radioButton_truck->isChecked())
    {
        Truck *inp_truck = new Truck;
        inp_truck->set_brand(ui->lineEdit_truck_brand->text());
        inp_truck->set_mileage(ui->doubleSpinBox_truck_mileage->value());
        inp_truck->set_payload(ui->doubleSpinBox_truck_payload->value());
        inp_truck->set_engine_power(ui->doubleSpinBox_truck_engine_power->value());
        inp_truck->set_residual_mileage(ui->doubleSpinBox_truck_residual_mileage->value());
        inp_transport = inp_truck;
    } else return;
    inp_transport->set_state_number(ui->lineEdit_state_number->text());
    inp_transport->set_vin_number(ui->lineEdit_vin_number->text());
    inp_transport->set_year(ui->spinBox_year->value());
    if (ui->radioButton_repairs_true->isChecked())
    {
        inp_transport->set_repairs(true);
        inp_transport->set_type_work(ui->lineEdit_type_work->text());
        inp_transport->set_type_repairs(ui->lineEdit_type_repairs->text());
    }
    this->hide();
}

Transport *InputTransport::get_input()
{
    return inp_transport;
}
