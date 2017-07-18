#pragma once

#include <QWidget>
#include <QBoxlayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include "StructureElement.h"
#include <QObject>
#include "Apply_Morphological_Operations.h"
#include "Apply_Thresholding.h"
#include <QSlider>
#include <QSpinBox>

class SEWidget : public QWidget
{
	Q_OBJECT
public:
	SEWidget(QWidget* parent = 0);

	void Initialize(StructureElement* SE);

private:
	void InitializeLayouts();
	void AddSEButtons(int width, int height, int centerx, int centery);
	void AddMorphsButtons();
	void AddThresholds();

	QBoxLayout* _main_layout;
	QBoxLayout* _select_morhp_operation;
	QBoxLayout* _select_threshold;
	QGridLayout* _se_selction_layout;
	StructureElement* _SE;

	Morhps current_morph;
	int slider_value;
	bool invert;
	Thresholding_methods current_threshold_method;

signals:
	void SEDone(Morhps);
	void ThresholdDone(int value, bool invert, Thresholding_methods method);

	public slots:
	void UpdateSE(bool toggled);
	void ApplySE(bool toggled);
	void ChangeInversion(bool toggled);
	void ChangeThreshold(int value);
	void ChangeThresholdMethod(bool toggled);

};