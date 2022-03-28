#ifndef BARLEYBREAK_H
#define BARLEYBREAK_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTimer>
#include <QFont>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui { class BarleyBreak; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pole_cellClicked(int row, int column);

//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_actionRestart_Game_triggered();

    void on_actionNew_Game_triggered();

    void TimerSlot();

private:
    Ui::BarleyBreak *ui;
    int seconds;
    int minutes;
    int hours;
    QTimer *timer;
    Ui::BarleyBreak *Ui;
    void showDesck();
    QTableWidgetItem *cell = new QTableWidgetItem;
};
#endif // BARLEYBREAK_H
