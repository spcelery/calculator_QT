#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    void calculate();
    void calculate(QString operation);

private:
    Ui::Calculator *ui;

    QStack<QString> stk; // 45+21=
    QString strDisplay; // 66

public slots:
    void slotButtonClicked();
};
#endif // CALCULATOR_H
