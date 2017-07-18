// Program for test applying convolutions on images 
// Gui created using Qt_5_9_0

#include <QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow* mainWindow = new MainWindow();
	mainWindow->show();

	return a.exec();
}