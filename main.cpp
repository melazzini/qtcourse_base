#include <QtWidgets>
#include <vector>
#include <QObject>
#include "CalculatorView.hpp"
#include "Calculator.hpp"

int main(int argc, char *argv[])
{
	QApplication a{argc, argv};

	CalculatorView calView;

	Calculator calculator;

	QObject::connect(&calView, &CalculatorView::newDigit, &calculator, &Calculator::newDigit);

	calView.show();
	return a.exec();
}
