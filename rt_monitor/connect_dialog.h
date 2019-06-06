#ifndef CONNECT_DIALOG_H
#define CONNECT_DIALOG_H

#include <QDialog>

namespace Ui {
class Connect_Dialog;
}

class Connect_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Connect_Dialog(QWidget *parent = nullptr);
    ~Connect_Dialog();

signals:
    void new_dev_connected();

private slots:
    void on_button_TcpClient_clicked();

private:
    Ui::Connect_Dialog *ui;
};

#endif // CONNECT_DIALOG_H
