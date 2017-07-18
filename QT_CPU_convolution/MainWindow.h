#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include "SEDockWidget.h"
#include "StructureElement.h"
#include <QObject>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);

private:
	QImage _orig_image_gray;
	QImage* _image_thresholded;
	QLabel* _image_label;
	SEDockWidget* _se_dock_widget;
	StructureElement* SE;

	public slots:
	void PrintSE();
	void ApplyThresholding(int threshold, bool invert, Thresholding_methods method);
	void ApplyMorph(Morhps morph);
};