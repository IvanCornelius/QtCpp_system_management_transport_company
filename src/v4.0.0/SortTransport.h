#ifndef SORTTRANSPORT_H
#define SORTTRANSPORT_H

#include <QDialog>

namespace Ui {
class SortTransport;
}

class SortTransport : public QDialog
{
    Q_OBJECT

public:
    explicit SortTransport(QWidget *parent = nullptr);
    ~SortTransport();
    QString get_sort_type();
    double get_sort_residual();
    bool get_status();
private slots:
    void on_pushButton_clicked();
private:
    Ui::SortTransport *ui;
    QString sort_type = "все";
    double sort_residual = 0;
    bool status = false;
};

#endif // SORTTRANSPORT_H
