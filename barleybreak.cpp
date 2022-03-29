#include "barleybreak.h"
#include "core.h"
#include "./ui_barleybreak.h"
#include <QMessageBox>
#include <Qt>

BarleyBreak BB;
bool endGame = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BarleyBreak) {

    ui->setupUi(this);
    QFont font("Times", 15, 3,false);
    QFont font2("Times", 30, QFont::Bold, false);
    ui->label->setFont(font);
    ui->timelabel->setFont(font);
    ui->pole->setFont(font2);

    seconds = 0;
    minutes = 0;
    hours = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    timer->start(1000);
    showDesck();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showDesck() {
    ui->label->setText("moves: " + QString::number(BB.GetMoves()));
    for (int i = 0; i < 4; i++) {
        for (int  j = 0; j < 4; j++) {
            if (BB.GetValue(i,j) == 0) {
                cell->setText(" ");
            }
            else
                cell->setText(QString::number(BB.GetValue(i,j)));
            cell->setTextAlignment(Qt::AlignCenter);
            cell->setBackground(QColor(100,150,120,255));
            ui->pole->setItem(i,j,new QTableWidgetItem(*cell));
        }
    }
}



void MainWindow::on_pole_cellClicked(int row, int column) {
    BB.ClickReact(row,column);
    showDesck();
    if (BB.IsFinished()) {
        if(QMessageBox::question(this,"Game over","Victiry! Retry?",
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            QApplication::quit();
        else {
            BB.StartGame();
            showDesck();
        }
    }
}

void MainWindow::on_actionRestart_Game_triggered() {
    BB.RestartGame();
    showDesck();
}


void MainWindow::on_actionNew_Game_triggered() {
    BB.StartGame();
    showDesck();
}

void MainWindow::TimerSlot() {
    if (BB.IsFinished())
        endGame = true;
    if (!endGame)
        seconds++;
    if (seconds == 60) {
        minutes++;
        seconds = 0;
    }
    if (minutes == 60) {
        hours++;
        minutes = 0;
        seconds = 0;
    }
    ui->timelabel->setText("Timer: " + QString::number(hours) + ":" + QString::number(minutes) + ":" + QString::number(seconds));

}


