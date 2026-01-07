#ifndef PLOT_H
#define PLOT_H

#include <QDialog>
#include <map>
#include "Transport.h"
#include "QCustomPlot.h"

namespace Ui {
class Plot;
}

class Plot : public QDialog
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = nullptr);
    ~Plot();
    void set_data(map <QString, Transport*> *);
    void display_plot();
private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::Plot *ui;
    map <QString, Transport*> * transport = 0;
};

#endif // PLOT_H
