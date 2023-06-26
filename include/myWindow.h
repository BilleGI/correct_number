#include <QWidget>

class QLineEdit;
class QLabel;

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    MyWindow(QWidget* parent = nullptr);
    ~MyWindow();
private slots:
    void inspectNumber(QString currentText);
private:
    QLineEdit* number;
    QLabel* checkNumber;
};
