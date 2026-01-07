#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//объявление заголовочных файлов
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include "QCustomPlot.h"
#include "InputTransport.h"
#include "Transport.h"
#include "SortTransport.h"
#include "Plot.h"

//пространство имён
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//класс графического интерфейса
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_save_clicked();
    void on_pushButton_open_clicked();
    void on_pushButton_plot_clicked();
    void on_pushButton_info_prog_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_info_clicked();
    void on_pushButton_sort_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void display_table();

private:
    QString id;
    Ui::MainWindow *ui;
    map <QString, Transport*> transport;
    multimap <unsigned int, Transport*> transport_sort_date;
    QString sort_type = "все";
    double sort_residual = 0;
};

#endif // MAINWINDOW_H
