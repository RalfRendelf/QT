#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ClientPort 777
#define SendingPort 8888

#define From_A_to_Z (65<=arg1[0]&&arg1[0]<=90)
#define From_a_to_z (97<=arg1[0]&&arg1[0]<=122)
#define From_0_to_semicolon (48<=arg1[0]&&arg1[0]<=59)
#define Dot_Comma_minus (44<=arg1[0]&&arg1[0]<=46)
#define Space (20==arg1[0])

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    socket -> bind(QHostAddress::LocalHost, ClientPort);
    connect(socket,SIGNAL(readyRead()),this,SLOT(ReadingData()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/////////////////////////////////////////UDP////////////////////////////////////////////////////////////////
void MainWindow::ReadingData(){
    QHostAddress sender;
    quint16 senderPort;
    while(socket->hasPendingDatagrams())
    {
        QByteArray data;
        data.resize(socket->pendingDatagramSize());
        socket->readDatagram(data.data(),data.size(),&sender,&senderPort);

     /*  QString testPoint;
        for(int i = 0; i< data.size(); i++)
            testPoint += QString::number(data[i])+' ';    //для просмотра сообщения
        ui->textBrowser->append(testPoint);
*/

        QString Answer = "";

        if(data[0] == 1)
        {
            Answer += "Ошибка";
            if(ui->Selection_mode_box->currentText() == "Чтение")
            {
                Answer += " чтения ячейки по адрессу " + QString::number(ui->Row_box->currentIndex())+" "+QString::number(ui->Column_box->currentIndex());
            }
            else if(ui->Selection_mode_box->currentText() == "Запись")
            {
                Answer += " записи ячейки по адрессу " + QString::number(ui->Row_box->currentIndex()+1)+" "+QString::number(ui->Column_box->currentIndex()+1);
            }
            else if(ui->Selection_mode_box->currentText() == "Очистка дисплея")
            {
                Answer += " очистки дисплея";

        }

        }
        else if(data[0] == 0)
        {
            Answer += "Результат";
            std::string ans;
            if(ui->Selection_mode_box->currentText() == "Чтение")
            {
                ans = data[1];
                Answer +=" чтения ячейки по адрессу " + QString::number(ui->Row_box->currentIndex()+1)
                          +" "+QString::number(ui->Column_box->currentIndex()+1)+": " + QString::fromStdString(ans);
            }
            else if(ui->Selection_mode_box->currentText() == "Запись")
            {
                ans = data[1];
                Answer +=" записи ячейки по адрессу " + QString::number(ui->Row_box->currentIndex()+1)
                          +" "+QString::number(ui->Column_box->currentIndex()+1)+": "+ QString::fromStdString(ans);
            }
            else if(ui->Selection_mode_box->currentText() == "Очистка дисплея")
            {
                Answer +=" очистки дисплея положительный";

        }




        }
        ui->textBrowser->append(Answer);
    }


}

void MainWindow::SendingMessage(QByteArray arg1)
{
    socket->writeDatagram(arg1,QHostAddress::LocalHost,SendingPort);
    ui->lineEdit->clear();
}
//////////////////////////////////////////////SLOTS///////////////////////////////////////////////////////
void MainWindow::on_pushButton_clicked()
{
    QByteArray data;

    if(ui->Selection_mode_box->currentText()=="Чтение")
    {
        data.resize(3);
        data[0] = 0;
        data[1] = ui->Row_box->currentIndex();
        data[2] = ui->Column_box->currentIndex();


    }
    else if (ui->Selection_mode_box->currentText()=="Запись")
    {

        data.resize(3+ui->lineEdit->text().toStdString().size());
        data[0] = 1;
        data[1] = ui->Row_box->currentIndex();
        data[2] = ui->Column_box->currentIndex();
        std::string value = ui->lineEdit->text().toStdString();
        int i = 0;
        for(auto a:value)
        {
            data[3+i] = a;
            i++;
        }


    }
    else
    {
        data.resize(1);
        data[0] = 2;

    }

        SendingMessage(data);

}


void MainWindow::on_Selection_mode_box_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Очистка дисплея")
    {
        ui->Column_box->hide();
        ui->Row_box->hide();
        ui->Columnlabel->hide();
        ui->Rowlabel->hide();
        ui->MessageLabel->hide();
        ui->lineEdit->hide();
    }
    else
    {
        ui->Column_box->show();
        ui->Row_box->show();
        ui->Columnlabel->show();
        ui->Rowlabel->show();
        ui->MessageLabel->show();
        ui->lineEdit->show();
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg)
{
    std::string arg1 = arg.toStdString();
    if(arg1.size()>1 && ui->checkBox->checkState() &&
        (From_A_to_Z||From_a_to_z||From_0_to_semicolon||Space||Dot_Comma_minus))
        ui->lineEdit->setText(arg[0]);



}


void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

