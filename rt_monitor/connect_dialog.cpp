#include "connect_dialog.h"
#include "ui_connect_dialog.h"
#include "mainwindow.h"

Connect_Dialog::Connect_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connect_Dialog)
{
    ui->setupUi(this);
}

Connect_Dialog::~Connect_Dialog()
{
    delete ui;
}

void Connect_Dialog::on_button_TcpClient_clicked()
{
    close();

    emit new_dev_connected();
}
