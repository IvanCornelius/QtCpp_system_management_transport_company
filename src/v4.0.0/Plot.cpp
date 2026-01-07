#include "Plot.h"
#include "ui_Plot.h"

Plot::Plot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plot)
{
    ui->setupUi(this);
}

Plot::~Plot()
{
    delete ui;
}

void Plot::set_data(map <QString, Transport *> * inp_transport)
{
    transport = inp_transport;
}

void Plot::display_plot()
{
    ui->widget_plot->clearGraphs();
    if ((*transport).size() > 0)
    {
        int i = 0;
        QVector <QString> number;
        QVector <double> residual, key;
        double max_residual, min_residual;
        max_residual  = (*transport).begin()->second->get_year();
        min_residual  = (*transport).begin()->second->get_year();
        for (auto it = (*transport).begin(); it != (*transport).end(); it++)
        {
            key.push_back(i++);
            number.push_back(it->second->get_state_number());
            residual.push_back(it->second->get("residual").toDouble());
            if (residual.back() >= max_residual) max_residual = residual.back();
            if (residual.back() <= min_residual) min_residual = residual.back();
        }
        max_residual += 1;
        min_residual -= 1;
        QCPBars *plot = new QCPBars(ui->widget_plot->xAxis, ui->widget_plot->yAxis);
        plot->setData(key, residual);
        ui->widget_plot->xAxis->setAutoTickLabels(false);
        ui->widget_plot->xAxis->setTickVectorLabels(number);
        ui->widget_plot->xAxis->setLabel("Гос. номер");
        ui->widget_plot->yAxis->setLabel("Остаточный пробег");
        ui->widget_plot->xAxis->setRange(0, (*transport).size());
        ui->widget_plot->yAxis->setRange(min_residual, max_residual);
        ui->widget_plot->xAxis->setAutoTickStep(false);
        ui->widget_plot->xAxis->setTickStep(1);
        ui->widget_plot->replot();
    }
}




void Plot::on_pushButton_exit_clicked()
{
    this->hide();
}
