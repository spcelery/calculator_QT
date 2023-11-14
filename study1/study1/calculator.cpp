#include "calculator.h"
#include "ui_calculator.h"
#include <QRegularExpression>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_10, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_11, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_12, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_13, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_14, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_15, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_16, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_17, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_18, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(ui->pushButton_19, SIGNAL(clicked()), SLOT(slotButtonClicked()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::calculate()
{
    float   operand2    = stk.pop().toFloat();
    QString strOperation = stk.pop();
    float  operand1    = stk.pop().toFloat();
    float   result      = 0;

    if (strOperation == "+") {
        result = operand1 + operand2;
    }
    else if (strOperation == "-") {
        result = operand1 - operand2;
    }
    else if (strOperation == "/") {
        result = operand1 / operand2;
    }
    else if (strOperation == "*") {
        result = operand1 * operand2;
    }
    else if (strOperation == "pow") {
        result = pow(operand1, operand2);
    }
    ui->lcdNumber->display(result);
}



void Calculator::slotButtonClicked()
{
     QString str = ((QPushButton*)sender())->text();

     if (str == "CE") {
         stk.clear();
         strDisplay = "";
         ui->lcdNumber->display("0");
         return;
     }
     if (str.contains(QRegularExpression("[0-9]")))
     {
         strDisplay+=str;
         ui->lcdNumber->display(strDisplay.toFloat());
     }
     else if (str == ".")
     {
         strDisplay+=str;
         ui->lcdNumber->display(strDisplay.toFloat());
     }
     else if (str == "sqrt")
     {
        stk.push(QString().setNum(ui->lcdNumber->value()));
        ui->lcdNumber->display(sqrt(stk.pop().toFloat()));
        stk.clear();
        stk.push(QString().setNum(ui->lcdNumber->value()));
     }
     else
     {
         if (stk.count()>=2)
         {
             stk.push(QString().setNum(ui->lcdNumber->value()));
             calculate();
             stk.clear();
             stk.push(QString().setNum(ui->lcdNumber->value()));
             if (str != "=") {
                 stk.push(str);
             }

         }
         else
         {
             stk.push(QString().setNum(ui->lcdNumber->value()));
             stk.push(str);
             strDisplay = "";
         }
     }
}

