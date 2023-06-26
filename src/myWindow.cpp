#include "myWindow.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpression>
#include <regex>

MyWindow::MyWindow(QWidget *parent) : QWidget(parent), number(new QLineEdit)
    ,checkNumber(new QLabel)
{
    number->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    checkNumber->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    checkNumber->setAlignment(Qt::AlignCenter);
    setMinimumSize(400,300);
    auto* vbox = new QVBoxLayout;
    vbox->addWidget(number);
    vbox->addWidget(checkNumber);
    setLayout(vbox);

    connect(number, &QLineEdit::textEdited, this, &MyWindow::inspectNumber);
}

MyWindow::~MyWindow()
{
    delete number;
    delete checkNumber;
}

void MyWindow::inspectNumber(QString currentText)
{
//    QRegularExpression exp("^\\+[7][9][0-9]{9}$");
    std::regex regular("^\\+"
                       "[7]"
                       "[9]"
                       "\\d{9}");
//    if(exp.match(currentText).hasMatch())
//    {
//        checkNumber->setText("Correct number");
//        checkNumber->setStyleSheet("color: green; background-color: white");
//    }
//    else
//    {
//        checkNumber->setText("Invalid Number");
//        checkNumber->setStyleSheet("color: red; background-color: yellow");
//    }
    if(std::regex_match(currentText.toStdString().c_str(), regular))
    {
        checkNumber->setText("Correct number");
        checkNumber->setStyleSheet("color: green; background-color: white");
    }
    else
    {
        checkNumber->setText("Invalid number");
        checkNumber->setStyleSheet("color: red; background-color: yellow");
    }
}
