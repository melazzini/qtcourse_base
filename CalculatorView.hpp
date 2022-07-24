#ifndef _CALCULATORVIEW_HPP_
#define _CALCULATORVIEW_HPP_

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QResizeEvent>
#include <QSizePolicy>
#include <optional>

class CalculatorView : public QWidget
{
private:
    Q_OBJECT
public:
    enum class OperatorCode
    {
        PLUS,
        MINUS,
        TIMES,
        DIV
    };

    CalculatorView(QWidget *parent = nullptr) : QWidget(parent)
    {
        setButtonsInGridLayout(m_gridLayout);
        setLCDInGridLayout(m_gridLayout);
        setLayout(&m_gridLayout);
        setFixedSize(sizeHint());
        setWindowTitle("Calculator");
    }
    ~CalculatorView() {}

    QSize sizeHint() const override { return QSize(240, 330); }

signals:
    void newDigit(qint32 d);

    void newOperator(OperatorCode c);

    void equals();

    void dot();

    void ce();

private:
    QGridLayout m_gridLayout;

private:
    std::optional<qint32> tryToGetNumber(QString text) const
    {
        bool ok = false;
        auto value = text.toInt(&ok);
        if (ok)
        {
            return value;
        }
        else
        {
            return std::nullopt;
        }
    }

    std::optional<OperatorCode> tryToGetOperator(QString text) const
    {
        bool ok = false;

        if (text == "+")
        {
            return OperatorCode::PLUS;
        }
        else if (text == "-")
        {
            return OperatorCode::MINUS;
        }
        else if (text == "*")
        {
            return OperatorCode::TIMES;
        }
        else if (text == "/")
        {
            return OperatorCode::DIV;
        }
        else
        {
            return std::nullopt;
        }
    }

    bool isEqualSymbol(QString text) const
    {
        return text == "=";
    }

    bool isDot(QString text) const
    {
        return text == ".";
    }

    bool isCE(QString text) const
    {
        return text == "CE";
    }

    void btnClicked(QString text)
    {
        if (auto digit = tryToGetNumber(text))
        {
            emit newDigit(digit.value());
        }
        else if (auto op = tryToGetOperator(text))
        {
            emit newOperator(op.value());
        }
        else if (isEqualSymbol(text))
        {
            emit equals();
        }
        else if (isDot(text))
        {
            emit dot();
        }
        else if (isCE(text))
        {
            emit ce();
        }
    }

    void addButtonToGridLayout(QGridLayout &layout, QString text, int i, int j, int w, int h)
    {
        auto btn = new QPushButton(text);

        connect(btn, &QPushButton::clicked, ([btn, this]()
                                             { this->btnClicked(btn->text()); }));

        btn->setFixedSize(w, h);
        layout.addWidget(btn, i, j);
    }

    void setButtonsInGridLayout(QGridLayout &layout)
    {
        for (auto i = 5; i >= 3; i--)
        {
            for (auto j = 1; j <= 3; j++)
            {
                addButtonToGridLayout(layout, QString::number(j + 3 * (3 - (i - 2))), i, j - 1, 50, 50);
            }
        }
        addButtonToGridLayout(layout, "0", 6, 0, 50, 50);
        addButtonToGridLayout(layout, ".", 6, 1, 50, 50);
        addButtonToGridLayout(layout, "=", 6, 2, 50, 50);

        addButtonToGridLayout(layout, "/", 3, 3, 50, 37);
        addButtonToGridLayout(layout, "*", 4, 3, 50, 37);
        addButtonToGridLayout(layout, "-", 5, 3, 50, 37);
        addButtonToGridLayout(layout, "+", 6, 3, 50, 37);
        addButtonToGridLayout(layout, "CE", 1, 3, 50, 37);
    }

    void setLCDInGridLayout(QGridLayout &layout)
    {
        layout.addWidget(([]() -> QLCDNumber *
                          { 
                            auto lcd {new QLCDNumber(10)};
                            lcd->setMode(QLCDNumber::Mode::Dec);
                            lcd->display(177930.2);
                            return lcd; })(),
                         0, 0, 1, 4);
    }
};

#endif // _CALCULATORVIEW_HPP_