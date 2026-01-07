#include "SortTransport.h"
#include "ui_SortTransport.h"

SortTransport::SortTransport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortTransport)
{
    ui->setupUi(this);
}

SortTransport::~SortTransport()
{
    delete ui;
}

QString SortTransport::get_sort_type()
{
    return sort_type;
}

double SortTransport::get_sort_residual()
{
    return sort_residual;
}

bool SortTransport::get_status()
{
    return status;
}

void SortTransport::on_pushButton_clicked()
{
    if (ui->comboBox_sort_type->currentIndex() == 0)
    {
        sort_type = "все";
    } else
    if (ui->comboBox_sort_type->currentIndex() == 1)
    {
        sort_type = "трактор";
    } else
    if (ui->comboBox_sort_type->currentIndex() == 2)
    {
        sort_type = "автобус";
    } else
    if (ui->comboBox_sort_type->currentIndex() == 3)
    {
        sort_type = "грузовой_автомобиль";
    }
    sort_residual = ui->doubleSpinBox_max->value();
    status = true;
    this->hide();
}
