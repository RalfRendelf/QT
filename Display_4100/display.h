#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QUdpSocket>

#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Display;
}
QT_END_NAMESPACE

class Display : public QMainWindow
{
    Q_OBJECT

public:
    Display(QWidget *parent = nullptr);
    ~Display();

public slots:

    void ReadingData();                    // Считывание данных

private slots:
    void SendingAnswer(QByteArray data);   //Ответное сообщение клиенту
    void on_pushButton_clicked();         //очистка консоли.

private:
    Ui::Display *ui;
    QUdpSocket *socket;

    QHostAddress sender = QHostAddress::LocalHost;
    quint16 senderPort = 12122;

private:
      void ClearingDisplay(QByteArray);     // очистка таблицы
      void AppendingDisplay(QByteArray); // заполнение значения ячейки
      void CellRead(QByteArray); // Считывание значения ячейки
      void DecodingDatagram(QByteArray); // расшифровка сообщения

};
#endif // DISPLAY_H
