#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <winsock2.h>
#include <iphlpapi.h>
#include <iostream>
#include <QDebug>
#include "arpsendthread.h"
#include "arpacceptthread.h"
#include "updatemacthread.h"
#include <QMenu>
#include <QAction>

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void getAllAdapterInfo();
    void fillAdapterInfo();
signals:
    void stopScan();
    void add_new_dev(const QString &ip);

private slots:
    void on_scanButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

//    void on_updateButton_clicked();

    void on_macList_customContextMenuRequested(const QPoint &pos);
    void addAction();

private:
    Ui::Widget *ui;
    WSADATA mWasData;
    // 网卡信息列表
    QList<QMap<QString,QString>> mAdapterList;
    // 网卡名称，IP->设备名称
    QMap<QString,QString> mAdapterName;
    // ARP发送线程
    ArpSendThread* mArpSendThread;
    // ARP接受线程
    ArpAcceptThread* mArpAcceptThread;
    // 厂商Mac地址处理
    UpdateMacThread* mUpdateMacThread;

    // 下来厂商Mac文件
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;
    bool httpRequestAborted;

    // 记录扫描到的网卡数量
    int mMacNum = 0;

    // 右键菜单
    QMenu *m_pMacListContexMenu = nullptr;
    QAction *m_pAddAction;
    QString m_CurIp;
};

#endif // WIDGET_H
