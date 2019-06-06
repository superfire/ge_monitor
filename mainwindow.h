#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "rt_monitor/connect_dialog.h"
#include <QList>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void DispAllDev();

public slots:
    void on_btn_conn_clicked();

private slots:
    void on_btn_net_scan_clicked();
    void on_btn_enter_monitor();
    void on_btn_add_new_dev();

private:
    Ui::MainWindow *ui;
    quint16 u16_dev_num;
    quint16 u16_dev_row, u16_dev_rank;
    QList<QPushButton*> mo_dev_list;

    Connect_Dialog *pConnDlg = nullptr;
};

#endif // MAINWINDOW_H