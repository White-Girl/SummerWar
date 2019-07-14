#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_1,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_2,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_3,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_4,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_5,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_6,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_7,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_8,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_9,SIGNAL(cliked()),this,SLOT(digits_num()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_oper()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_oper()));
    connect(ui->pushButton_umn,SIGNAL(clicked()),this,SLOT(math_oper()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_oper()));

    ui->pushButton_min->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_umn->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::digits_num()
{
  QPushButton *button = (QPushButton *)sender();

  double all_num;
  QString new_label;
  all_num = (ui->rez->text() + button->text()).toDouble();
  new_label = QString::number(all_num, 'g',15);

  ui->rez->setText(new_label);

}

void MainWindow::math_oper()
{
    QPushButton *button = (QPushButton *)sender();
    num_first = ui->rez->text().toDouble();
    ui->rez->setText("");
    button->setChecked(true);

}

void MainWindow::on_pushButton_ravno_clicked()
{
    double labelNumber,num_second;
    QString new_label;

    num_second=ui->rez->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
      labelNumber=num_first+num_second;
      new_label = QString::number(labelNumber);
      ui->rez->setText(new_label);
      ui->pushButton_plus->setChecked(false);
    } else if (ui->pushButton_min->isChecked()){
        labelNumber=num_first-num_second;
        new_label = QString::number(labelNumber);
        ui->rez->setText(new_label);
        ui->pushButton_min->setChecked(false);
    } else if (ui->pushButton_umn->isChecked()){
        labelNumber=num_first*num_second;
        new_label = QString::number(labelNumber);
        ui->rez->setText(new_label);
        ui->pushButton_umn->setChecked(false);
    } else if (ui->pushButton_del->isChecked()){
        if (num_second==0){
            ui->rez->setText("0");
        } else {
        labelNumber=num_first/num_second;
        new_label = QString::number(labelNumber);
        ui->rez->setText(new_label);
        }
        ui->pushButton_del->setChecked(false);
    }
}
