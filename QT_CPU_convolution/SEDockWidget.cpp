#include "SEDockWidget.h"


SEDockWidget::SEDockWidget(QWidget* parent)
	:QDockWidget(parent)
{
	
	_se_widget = new SEWidget(this);
	_se_widget->showMaximized();
	this->setWidget(_se_widget);
}

void SEDockWidget::SetstructureElement(StructureElement* SE)
{
	_se_widget->Initialize(SE);
}