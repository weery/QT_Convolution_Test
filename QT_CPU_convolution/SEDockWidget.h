#pragma once

#include <QDockWidget>
#include "SEWidget.h"
#include "StructureElement.h"

class SEDockWidget : public QDockWidget
{
public: 
	SEDockWidget(QWidget* parent = 0);

	void SetstructureElement(StructureElement* SE);

private:
	SEWidget* _se_widget;
};