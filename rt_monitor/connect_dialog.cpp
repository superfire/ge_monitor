#include "connect_dialog.h"
#include "ui_connect_dialog.h"
#include "mainwindow.h"
#include <QTextEdit>
#include <QMdiSubWindow>

Connect_Dialog::Connect_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connect_Dialog)
{
    ui->setupUi(this);

    m_NewIp = "192.168.1.1";  // for test

//    QPushButton *edit = new QPushButton(this);
//    edit->setText(tr("dev_1"));
//    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
////    child->setWindowTitle(tr("多文档编辑器子窗口"));
//    child->show();
//    child->showMaximized();
//    edit->resize(child->width(), child->height());
}

Connect_Dialog::~Connect_Dialog()
{
    delete ui;
}

void Connect_Dialog::on_button_TcpClient_clicked()
{
    close();

    emit new_dev_connected(m_NewIp);
}
