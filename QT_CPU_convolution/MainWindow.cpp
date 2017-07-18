#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	QImage* image_in= new QImage("./resources/images/image.png");
	_orig_image_gray = image_in->convertToFormat(QImage::Format::Format_Grayscale8);
	delete image_in;

	_image_thresholded = new QImage(_orig_image_gray.width(),_orig_image_gray.height(),
		_orig_image_gray.format());

	_image_label = new QLabel(this);
	_image_label->setPixmap(QPixmap::fromImage(_orig_image_gray));
	_image_label->show();
	this->setCentralWidget(_image_label);

	SE = new StructureElement();

	_se_dock_widget = new SEDockWidget(this);
	_se_dock_widget->show();
	this->addDockWidget(Qt::RightDockWidgetArea, _se_dock_widget);

	_se_dock_widget->SetstructureElement(SE);


	connect(SE, SIGNAL(SE_changed()), this, SLOT(PrintSE()));
	this->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::PrintSE()
{
}

void MainWindow::ApplyThresholding(int threshold, bool invert, Thresholding_methods method)
{
	Apply_Thresholding::Apply_Threshold(_image_thresholded,&_orig_image_gray,threshold,method,invert);
	
	_image_label->setPixmap(QPixmap::fromImage(*_image_thresholded));
}

void MainWindow::ApplyMorph(Morhps morps)
{
	QImage* se_image = new QImage(_orig_image_gray.width(), _orig_image_gray.height(),
		_orig_image_gray.format());
	Apply_Morphological_Operations::Apply_Operation(se_image,_image_thresholded,SE, morps);
	_image_label->setPixmap(QPixmap::fromImage(*se_image));

	delete se_image;
}