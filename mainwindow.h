#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "rt_monitor/connect_dialog.h"
#include <QList>
#include "widget.h"


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

private slots:
    void on_btn_net_scan_clicked();
    void on_btn_enter_monitor();
    void on_btn_add_new_dev_clicked();
    void on_btn_conn_clicked(const QString &ip);

private:
    Ui::MainWindow *ui;
    quint16 u16_dev_num;
    quint16 u16_dev_row, u16_dev_rank;
    QList<QPushButton*> mo_dev_list;

    Connect_Dialog *pConnDlg = nullptr;
    Widget *m_pMacScanWidget = nullptr;
};

#endif // MAINWINDOW_H
