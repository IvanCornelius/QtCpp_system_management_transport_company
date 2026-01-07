#ifndef INPUTTRANSPORT_H
#define INPUTTRANSPORT_H

#include <QDialog>
#include "Transport.h"

namespace Ui {
class InputTransport;
}

class InputTransport : public QDialog
{
    Q_OBJECT

public:
    explicit InputTransport(QWidget *parent = nullptr);
    ~InputTransport();
    Transport *get_input();
private slots:
    void on_radioButton_repairs_false_clicked();
    void on_radioButton_repairs_true_clicked();
    void on_radioButton_tractor_clicked();
    void on_radioButton_bus_clicked();
    void on_radioButton_truck_clicked();
    void on_pushButton_save_clicked();
private:
    Ui::InputTransport *ui;
    Transport *inp_transport = 0;
};

#endif // INPUTTRANSPORT_H
