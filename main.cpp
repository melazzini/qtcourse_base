#include <QtWidgets>
#include <vector>
#include <QObject>
#include "CalculatorView.hpp"
#include "Calculator.hpp"

int main(int argc, char *argv[])
{
	QApplication a{argc, argv};

	QWidget w;
	QHBoxLayout layout;

	QProgressBar bar;
	bar.setMaximum(100);
	bar.setMinimum(0);
	bar.setValue(0);
	bar.setOrientation(Qt::Vertical);
	layout.addWidget(&bar, 2);
	bar.setMinimumWidth(250);

	QPushButton step{"Step"}, reset{"Reset"};

	QObject::connect(&step, &QPushButton::clicked, [&bar]()
					 { bar.setValue(bar.value() + 10); });

	QObject::connect(&reset, &QPushButton::clicked, [&bar]()
					 { bar.reset(); bar.setValue(0); });

	layout.addWidget(&step, 1);
	layout.addWidget(&reset, 1);

	w.setLayout(&layout);
	w.show();
	return a.exec();
}
