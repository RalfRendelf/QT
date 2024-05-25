#include "display.h"
#include "ui_display.h"

#define ClientPort 8888

#define Number_of_colums 16
#define Number_of_rows 2
#define Pixel_size 45

#define From_A_to_Z ((64<data[3])&&(data[3]<91))
#define From_a_to_z ((96<data[3])&&(data[3]<123))
#define From_0_to_semicolon ((47<data[3])&& (data[3]<60))
#define Dot_Comma_minus ((43<data[3]) && (data[3]<47))
#define Space (20==(data[3]))


Display::Display(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Display)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(Number_of_colums);
    ui->tableWidget->setRowCount(Number_of_rows);
    for(int i = 0; i < Number_of_colums; i++){
        ui->tableWidget->setColumnWidth(i,Pixel_size);
        for(int j = 0; j < Number_of_rows; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->tableWidget->setItem(j,i,newItem);

        }
    }


    socket = new QUdpSocket(this);
    socket -> bind(QHostAddress::LocalHost, ClientPort);
    connect(socket,SIGNAL(readyRead()),this,SLOT(ReadingData()));


}

Display::~Display()
{
    delete ui;
}
//////////////////////////////////////UDP///////////////////////////////////////////////////////////////////////////////////////
void Display::ReadingData(){

    while(socket->hasPendingDatagrams())
    {
        QByteArray data;
        data.resize(socket->pendingDatagramSize());
        socket->readDatagram(data.data(),data.size(),&sender,&senderPort);

       DecodingDatagram(data);

        switch(data[0])
        {   case 0:

                CellRead(data);
                break;

            case 1:
                AppendingDisplay(data);
                break;

            case 2:
                ClearingDisplay(data);
                break;
            default:
                QByteArray message;
                message.resize(1);
                message[0] = 1;
                SendingAnswer(message);


    }

}
}
void Display::SendingAnswer (QByteArray data)
{  socket->writeDatagram(data,sender,senderPort);
    QString ans = "ответ:";
    for(auto a: data)
        ans+=" "+QString::number(a);
    ui->textBrowser->append(ans+"\n");

}


//////////////////////////////////////////////Работа с таблицей//////////////////////////////////////////////////////////////
void Display::ClearingDisplay(QByteArray data)
{
    QByteArray message;
    message.resize(1);
    ui->tableWidget->clear();
    if(data.size()==1)
    {
   for(int i = 0; i < Number_of_colums; i++){
        ui->tableWidget->setColumnWidth(i,Pixel_size);
        for(int j = 0; j < Number_of_rows; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->tableWidget->setItem(j,i,newItem);
        }}

    message[0]=0;
   ui->textBrowser->append("Дисплей очищен");}
    else
    {
        message[0] = 1;
        ui->textBrowser->append("Ошибка: Неверный размер сообщения!");
    }
    SendingAnswer(message);


}

void Display::AppendingDisplay(QByteArray data)
{
    QByteArray message;
    if(data.size() == 4 && data[1]<Number_of_rows && data[2] < Number_of_colums &&
       (From_A_to_Z||From_a_to_z||From_0_to_semicolon||Space||Dot_Comma_minus))
     {
        message.resize(2);
        message[0] = 0;
        message[1] = data[3];
        delete ui->tableWidget->takeItem(data[1],data[2]);
        std::string mess;
        mess.push_back(data[3]);
        QTableWidgetItem *letter= new QTableWidgetItem(QString::fromStdString(mess));
        ui->tableWidget->setItem(data[1],data[2],letter);
        ui->textBrowser->append("Ячейка заполнена!");
}
    else
    {
        message.resize(1);
        message[0] = 1;
        if(data.size()!=4) ui->textBrowser->append("Ошибка: Неверный размер сообщения!");
        else if(data[1]>=Number_of_rows) ui->textBrowser->append("Ошибка: Превышение количества строк!");
        else if(data[2]>=Number_of_colums) ui->textBrowser->append("Ошибка: Превышение количества столбцов!");
        else if(!(From_A_to_Z||From_a_to_z||From_0_to_semicolon||Space||Dot_Comma_minus)) ui->textBrowser->append("Ошибка: Неверный символ!");

    }
    SendingAnswer(message);

}

void Display::CellRead(QByteArray data)
{
    QByteArray message;

    QTableWidgetItem *it = ui->tableWidget->item(data[1],data[2]);

    if(data.size() == 3 && data[1]<Number_of_rows && data[2] < Number_of_colums && !it->text().isEmpty())
    {
        message.resize(2);
        message[0] = 0;
        message[1] = it->text().toLocal8Bit()[0];

    }
    else
    {
        message.resize(1);
        message[0] = 1;
        if(data.size()!=3) ui->textBrowser->append("Ошибка: Неверный размер сообщения!");
        else if(data[1]>=Number_of_rows) ui->textBrowser->append("Ошибка: Превышение количества строк!");
        else if(data[2]>=Number_of_colums) ui->textBrowser->append("Ошибка: Превышение количества столбцов!");
        else if(ui->tableWidget->itemAt(data[1],data[2])->text().isEmpty()) ui->textBrowser->append("Ошибка: Ячейка пустая!");
    }

    SendingAnswer(message);
}

void Display::DecodingDatagram(QByteArray ans)
{
    QByteArray data = ans;
    QString testPoint = "Сообщение: ";
    for(int i = 0; i< data.size(); i++)
        testPoint += QString::number(data[i])+' ';
    ui->textBrowser->append(testPoint);
    testPoint = "Расшифровка сообщения:\nОперация: ";
    switch(data[0])
    {
    case 0:
        testPoint +="чтения ячейки по адресу: "+QString::number(data[1])+' '+ QString::number(data[2]);
        break;
    case 1:
        testPoint +="записи ячейки по адресу: "+QString::number(data[1])+' '+ QString::number(data[2]);
        data.remove(0,3);
        testPoint += "\nПереданные символы: " + QString::fromLocal8Bit(data);
        break;
    case 2:
        testPoint +="очистки дисплея";
        break;
    default:
        testPoint="Ошибка передачи данных, неизвестное сообщение";
        break;
    }

    ui->textBrowser->append(testPoint);
}

////////////////////////////////////////////Очистка консоли///////////////////////////////////////////////////////////////////////////////
void Display::on_pushButton_clicked()
{
    ui->textBrowser->clear();
}

