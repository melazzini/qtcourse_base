#include <QtWidgets>
#include <vector>
#include <QObject>
#include "CalculatorView.hpp"
#include "Calculator.hpp"

int main(int argc, char *argv[])
{
	QApplication a{argc, argv};

	auto osList{QStringList() << "Android"
							  << "Linux"
							  << "Windows"
							  << "MacOSX"};
	QStandardItemModel model{osList.size(), 1};
	for (auto row = 0; row < model.rowCount(); row++)
	{
		auto index = model.index(row, 0);
		model.setData(index, QIcon("../ch_12/images/" + osList[row] + ".jpg"), Qt::DecorationRole);
		model.setData(index, osList[row], Qt::DisplayRole);
		model.setData(index, "tooltip for " + osList[row], Qt::ToolTipRole);
	}

	QListView listView;
	listView.setViewMode(QListView::IconMode);
	listView.setModel(&model);
	listView.show();
	listView.setFixedSize(QSize(216, 60));
	return a.exec();
}
