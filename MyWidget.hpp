#include <QLabel>
#include <QObject>
#include <QDebug>
#include <QKeyEvent>
#include <QCoreApplication>

class MyWidget : public QLabel
{
	Q_OBJECT

public:
	MyWidget() : QLabel{"heyyy!", nullptr} {}

protected:
	void keyPressEvent(QKeyEvent *keyEvent) override
	{
		if (keyEvent->key() == Qt::Key_Q && keyEvent->modifiers() == Qt::CTRL)
		{
			QCoreApplication::quit();
		}
		else
		{
			QWidget::keyPressEvent(keyEvent);
		}
	}
};
