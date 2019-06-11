#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include "widget.h"
#include "rt_monitor/monitorwindow.h"
#include <QPushButton>

#include <QCommandLinkButton>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    u16_dev_num = 0;
    u16_dev_row = 0;
    u16_dev_rank = 0;

    pConnDlg = new Connect_Dialog(this);
    m_pMacScanWidget = new Widget();

    connect(pConnDlg, SIGNAL(new_dev_connected(QString)), this, SLOT(on_btn_conn_clicked(QString)) );
    connect(m_pMacScanWidget, SIGNAL(add_new_dev(QString)), this, SLOT(on_btn_conn_clicked(QString)) );


//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(ui->groupBox, 0, 0, 1, 2);
//    setLayout(layout);

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(ui->groupBox);
//    layout->setSpacing(50);
//    layout->setContentsMargins(0, 0, 50, 100);
//    setLayout(layout);

//    ui->Btn_SetNetInterface->setIcon(QIcon("../ge_monitor/res/ico/net_interface.png"));

    // 新建一个扫描按钮
//    QPushButton *btn_net_scan = new QPushButton(this);
//    btn_net_scan->move(10, 15);
//    btn_net_scan->resize(80, 30);
//    btn_net_scan->setText(QObject::tr("网络扫描"));
//    btn_net_scan->setIcon(QIcon("../ge_monitor/res/ico/net_interface.png"));
//    btn_net_scan->show();
//    connect( btn_net_scan, &QPushButton::clicked, this, &MainWindow::on_btn_net_scan_clicked );

//    connect( ui->MainWindow::btn_net_scan, &QPushButton::clicked, this, &MainWindow::on_btn_net_scan_clicked );

    ui->MainWindow::btn_net_scan->setIcon(QIcon("../ge_monitor/res/ico/net_interface.png"));

    // 新建一个添加设备按钮
//    QPushButton *btn = new QPushButton(this);
//    btn->move(100, 15);
//    btn->resize(80, 30);
//    btn->setText(QObject::tr("添加设备"));
//    btn->setIcon(QIcon("../ge_monitor/res/ico/add.png"));
//    btn->show();

//    connect( btn, &QPushButton::clicked, this, &MainWindow::on_btn_add_new_dev );

    ui->MainWindow::btn_add_new_dev->setIcon(QIcon("../ge_monitor/res/ico/add.png"));


//    // 新建一个添加设备按钮
//    QPushButton *btn = new QPushButton(this);
//    btn->move(20, 80);
//    btn->resize(120, 120);
//    btn->setIcon(QIcon("../ge_monitor/res/ico/add.png"));
//    btn->show();
//    connect( btn, &QPushButton::clicked, this, &MainWindow::on_Btn_Add_Dev_clicked );
}

MainWindow::~MainWindow()
{
    delete ui;
}

#define    WIDTH    ((quint16)120)
#define    HEIGHT   ((quint16)120)

void MainWindow::DispAllDev()
{
    int x,y,w,h;
    int gpbox_x, gpbox_y, gpbox_w, gpbox_h;
    quint16 num_of_each_row;

    QRect rect = ui->groupBox->geometry();

    gpbox_x = ui->groupBox->x();
    gpbox_y = ui->groupBox->y();
    gpbox_w = ui->groupBox->width();
    gpbox_h = ui->groupBox->height();

    num_of_each_row = (quint16)gpbox_w / WIDTH;

qDebug() << "gpbox, x, y, w, h " << gpbox_x << gpbox_y << gpbox_w << gpbox_h;
qDebug() << "qrect, w: " << ui->groupBox->geometry().size().width();
qDebug() << "qrect, h: " << ui->groupBox->geometry().size().height();
qDebug() << "mainwindow, w: " << this->width();


    for( quint16 i = 0; i < mo_dev_list.size(); i++  )
    {
        x = gpbox_x + 10 + u16_dev_num * WIDTH + u16_dev_num * 10;
        y = gpbox_y + 30;
        w = WIDTH;
        h = WIDTH;

        if( x >= gpbox_w )
        {
            u16_dev_row ++;
            x = u16_dev_num - num_of_each_row * u16_dev_row;
            x = gpbox_x + 10 + x * WIDTH + x * 10;
            y = gpbox_y + 30 + u16_dev_row * HEIGHT + u16_dev_row * 10;
        }

        mo_dev_list[i]->move(x, y);
        mo_dev_list[i]->resize(w, h);
        mo_dev_list[i]->setIcon(QIcon("../ge_monitor/res/ico/add.png"));
        mo_dev_list[i]->show();

        qDebug() << "i: " << i;
    }
}


void MainWindow::on_btn_conn_clicked(const QString &ip)
{
    qDebug() << "ip: " << ip;

    // 创建一个设备，添加到设备列表里
    QPushButton *pBtn = new QPushButton(this);
    mo_dev_list.append(pBtn);
    connect( pBtn, SIGNAL(clicked()), this, SLOT(on_btn_enter_monitor()) );

    // 然后依次显示所有
    DispAllDev();

    u16_dev_num ++;
    qDebug() << "num: " << u16_dev_num;

    // 新建一个添加设备按钮
//    QPushButton *btn = new QPushButton(this);
//    btn->move(20, 80);
//    btn->resize(120, 120);
//    btn->setIcon(QIcon("../ge_monitor/res/ico/add.png"));
//    btn->show();
//    connect( btn, &QPushButton::clicked, this, &MainWindow::on_Btn_Add_Dev_clicked );


//    QCommandLinkButton *clbtn = new QCommandLinkButton(this);

//    clbtn->move(20, 80);
//    clbtn->resize(120, 120);
//    clbtn->setText(QObject::tr("设备一"));
    //    clbtn->show();
}


void MainWindow::on_btn_net_scan_clicked()
{
//    Widget *pw = new Widget();
//    pw->setWindowModality(Qt::ApplicationModal);
//    pw->show();
    m_pMacScanWidget->setWindowModality(Qt::ApplicationModal);
    m_pMacScanWidget->show();
}

void MainWindow::on_btn_enter_monitor()
{
//   QPushButton *btn = new QPushButton(this);
//   btn->move(150, 80);
//   btn->resize(120, 120);
//   btn->setIcon(QIcon("../ge_monitor/res/ico/add.png"));
//   btn->show();
//   connect( btn, &QPushButton::clicked, this, &MainWindow::on_Btn_Add_Dev_clicked );

//    Connect_Dialog *pmvw = new Connect_Dialog(this);
//    pmvw->move(100, 15);
//    pmvw->resize(120, 120);
//    pmvw->show();

//    pConnDlg->show();

    MonitorWindow *pDetailMonitor = new MonitorWindow();
    pDetailMonitor->show();

//    MonitorWindow *pMonitorWindow = new MonitorWindow();
    //    pMonitorWindow->show();
}

void MainWindow::on_btn_add_new_dev_clicked()
{
   pConnDlg->show();
}
