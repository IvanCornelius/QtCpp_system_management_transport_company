#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    display_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_save_clicked()
{
    QString name_file = QFileDialog::getSaveFileName(this, "Сохранить файл", QDir::currentPath(),"*.transp");
    if (name_file.size() == 0) return;
    QFile qfile(name_file);
    if (!qfile.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Ошибка открытия файла", "Файл или недоступен или не существует.");
        return;
    }
    QTextStream file(&qfile);
    for (auto it = transport.begin(); it != transport.end(); it++)
        it->second->output(file);

}

void MainWindow::on_pushButton_open_clicked()
{
    QString name_file = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(),"*.transp");
    if (name_file.size() == 0) return;
    QFile qfile(name_file);
    if (!qfile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Ошибка открытия файла", "Файл или недоступен или не существует.");
        return;
    }
    transport.clear();
    transport_sort_date.clear();
    QTextStream file(&qfile);
    QString type;
    Transport *input_transport = 0;
    while (!file.atEnd())
    {
        file >> type;
        if (type == "")
        {
            display_table();
            return;
        }
        if (type == "трактор") input_transport  = new Tractor; else
        if (type == "автобус") input_transport  = new Bus; else
        if (type == "грузовой_автомобиль") input_transport  = new Truck; else
        {
            QMessageBox::warning(this, "Ошибка чтения файла", "Ошибка определения типа транспорта.");
            display_table();
            return;
        }
        if (input_transport->input(file))
        {
            transport.emplace(input_transport->get_state_number(), input_transport);
            transport_sort_date.emplace(input_transport->get_year(), input_transport);
        } else
        {
            delete input_transport;
            QMessageBox::warning(this, "Ошибка чтения файла", "При чтении файла произошла ошибка.");
            display_table();
            return;
        }
        qfile.close();
    }
    display_table();
}

void MainWindow::on_pushButton_info_prog_clicked()
{
    QMessageBox::information(this,
                             "Информация о программе",
                             "Информация: Система управления автотранспортного предприятия. \n"
                             "Разработчик: Кузнецов И.К. \n"
                             "Дата создания: 10.12.2022 \n");
}

void MainWindow::on_pushButton_exit_clicked()
{
    qApp->exit();
}

void MainWindow::on_pushButton_add_clicked()
{
    InputTransport win_input_transport;
    win_input_transport.setModal(true);
    win_input_transport.exec();
    if (win_input_transport.get_input() != 0)
    {
        transport.emplace(win_input_transport.get_input()->get_state_number(), win_input_transport.get_input());
        transport_sort_date.emplace(win_input_transport.get_input()->get_year(), win_input_transport.get_input());
        id = "";
        display_table();
    }
}

void MainWindow::on_pushButton_delete_clicked()
{
    if (transport.size() > 0)
    {
        for (auto it = transport.begin(); it != transport.end(); it++)
            if (it->second->get_state_number() == id)
            {
                for (auto it_sort = transport_sort_date.begin(); it_sort != transport_sort_date.end(); it_sort++)
                    if (it_sort->second->get_state_number() == id)
                        transport_sort_date.erase(it_sort);
                delete it->second;
                transport.erase(it);
                id = "";
                display_table();
                return;
            }
    }
}

void MainWindow::on_pushButton_info_clicked()
{
    if (id.size() > 0)
    {
        QString text_info = transport[id]->get_text_output();
        QMessageBox::information(this, "Информация о транспорте", text_info);
    }
}

void MainWindow::on_pushButton_sort_clicked()
{
    SortTransport win_sort;
    win_sort.setModal(true);
    win_sort.exec();
    if (win_sort.get_status())
    {
        sort_type = win_sort.get_sort_type();
        sort_residual = win_sort.get_sort_residual();
        id = "";
        display_table();
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    id = ui->tableWidget->item(row, 0)->text();
}

void MainWindow::display_table()
{
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Гос.номер", "Инв.номер", "Год постановки на учет"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    if (transport.size() > 0)
    {
        unsigned int i = 0;
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setRowCount(transport.size());
        ui->tableWidget->setHorizontalHeaderLabels({"Гос.номер", "Инв.номер", "Тип", "Год постановки на учет"});
        for (auto it  = transport.begin(); it != transport.end(); it++)
        {
            if ((it->second->get_type() == sort_type) || (sort_type == "все"))
            {
                if ((it->second->get("residual").toDouble() < sort_residual) || (sort_residual == 0))
                {
                    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->second->get_state_number()));
                    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->second->get_vin_number()));
                    ui->tableWidget->setItem(i, 2, new QTableWidgetItem(it->second->get_type()));
                    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(it->second->get_year())));
                    i++;
                }
            }
        }
        ui->tableWidget->setRowCount(i);
    }
}
