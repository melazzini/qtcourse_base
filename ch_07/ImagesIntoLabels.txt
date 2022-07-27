#include <QtWidgets>
#include <vector>
#include <QObject>
#include "CalculatorView.hpp"
#include "Calculator.hpp"

int main(int argc, char *argv[])
{
	QApplication a{argc, argv};

	QPixmap pxmap;
	pxmap.load("../ch_07/images/gibsonsg.jpg");

	QLabel lbl;

	lbl.setPixmap(pxmap);

	lbl.resize(pxmap.size());

	lbl.show();

	return a.exec();
}
