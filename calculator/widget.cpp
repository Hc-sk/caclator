#include "widget.h"
#include "ui_widget.h"
#include "calculate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("计算机");

    QIcon con("D:\\qtfiles\\calculator\\delete.png");
    ui->deleteButton->setIcon(con);

    ui->equalButton->setStyleSheet("background:lightblue");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_oneButton_clicked()
{
    expression += "1";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_twoButton_clicked()
{
    expression += "2";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression += "3";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_fourButton_clicked()
{
    expression += "4";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_fiveButton_clicked()
{
    expression += "5";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_sixButton_clicked()
{
    expression += "6";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_seveButton_clicked()
{
    expression += "7";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_eightButton_clicked()
{
    expression += "8";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_nineButton_clicked()
{
    expression += "9";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_zeroButton_clicked()
{
    expression += "0";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_addButton_clicked()
{
    expression += "+";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_subButton_clicked()
{
    expression += "-";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_mulButton_clicked()
{
    expression += "*";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_divButton_clicked()
{
    expression += "/";
    ui->mainlineEdit->setText(expression);
}


void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainlineEdit->clear();

}


void Widget::on_deleteButton_clicked()
{
    expression.chop(1);
    ui->mainlineEdit->setText(expression);
}

void Widget::on_equalButton_clicked()
{


    QString res = Calculator::calculate(expression);
    ui->mainlineEdit->setText(res);
    expression = res;


}

