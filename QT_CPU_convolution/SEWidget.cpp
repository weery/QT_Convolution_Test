#include "SEWidget.h"

SEWidget::SEWidget(QWidget* parent)
	:QWidget(parent)
{
}

void SEWidget::Initialize(StructureElement* SE)
{
	InitializeLayouts();
	_SE = SE;
	AddSEButtons(5, 5, 2, 2);
	AddMorphsButtons();
	AddThresholds();
}

void SEWidget::InitializeLayouts()
{
	_main_layout = new QVBoxLayout(this);
	_main_layout->addStretch(1);

	_select_threshold = new QVBoxLayout();
	QGroupBox* threhsold_groupbox = new QGroupBox("Select threhsold");
	_main_layout->addWidget(threhsold_groupbox);
	threhsold_groupbox->setLayout(_select_threshold);

	_select_morhp_operation = new QVBoxLayout();
	QGroupBox* select_morphological_groupbox = new QGroupBox("Morphological Operation");
	_main_layout->addWidget(select_morphological_groupbox);
	select_morphological_groupbox->setLayout(_select_morhp_operation);

	_se_selction_layout = new QGridLayout();
	QGroupBox* se_selection_groupbox = new QGroupBox("Structure Element Creator");
	_main_layout->addWidget(se_selection_groupbox);
	se_selection_groupbox->setLayout(_se_selction_layout);

	this->setLayout(_main_layout);
}

void SEWidget::AddThresholds()
{
	QCheckBox* invert_background = new QCheckBox("invert background");
	_select_threshold->addWidget(invert_background);

	for (int i = 0; i < Thresholding_methods::number_of_methods; i++)
	{
		QRadioButton* threshold_button = new QRadioButton(Threshold_method_names[i]);
		_select_threshold->addWidget(threshold_button);
		connect(threshold_button, SIGNAL(toggled(bool)), this, SLOT(ChangeThresholdMethod(bool)));
	}

	QSlider* slider = new QSlider(Qt::Orientation::Horizontal);
	slider->setMaximum(255);
	_select_threshold->addWidget(slider);

	QSpinBox* spinBox = new QSpinBox();
	spinBox->setMaximum(255);
	connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
	connect(this, SIGNAL(ThresholdDone(int, bool, Thresholding_methods)), this->parent()->parent(), SLOT(ApplyThresholding(int, bool, Thresholding_methods)));
	connect(slider, SIGNAL(valueChanged(int)), this, SLOT(ChangeThreshold(int)));
	connect(invert_background, SIGNAL(toggled(bool)), this, SLOT(ChangeInversion(bool)));
	slider->setValue(100);
	_select_threshold->addWidget(spinBox);
}

void SEWidget::ChangeThresholdMethod(bool toggled)
{
	if (toggled)
	{
		QRadioButton* sender_button = (QRadioButton*)sender();

		std::string text = sender_button->text().toStdString();
		Thresholding_methods method;
		for (int i = 0; i < Thresholding_methods::number_of_methods; i++)
		{
			if (text == Threshold_method_names[i])
			{
				current_threshold_method = (Thresholding_methods)i;
				break;
			}
		}

		emit ThresholdDone(slider_value, invert, current_threshold_method);
	}
}

void SEWidget::AddSEButtons(int width, int height, int centerx, int centery)
{
	_SE->InitializeSE(width,height,centerx,centery);
	char* text = (char*)malloc(sizeof(char)*6);
	text[0] = '(';
	text[2] = ',';
	text[4] = ')';
	text[5] = '\0';
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			text[1] = j + '0';
			text[3] = i + '0';
			QCheckBox* button = new QCheckBox(text);
			_se_selction_layout->addWidget(button,i,j);
			button->show();
			if (i == centerx && j == centery)
			{
				button->setChecked(true);
				button->setEnabled(false);
			}
			QObject::connect(button,SIGNAL(toggled(bool)),this, SLOT(UpdateSE(bool)));
		}

	delete text;

	
}

void SEWidget::AddMorphsButtons()
{
	for (int i = 0; i < Morhps::number_of_operations; i++)
	{
		QString name(Morph_names[i]);
		QRadioButton* radioButton = new QRadioButton(name);
		_select_morhp_operation->addWidget(radioButton);
		radioButton->show();
		connect(radioButton,SIGNAL(toggled(bool)), this,SLOT(ApplySE(bool)));
	}

	connect(this,SIGNAL(SEDone(Morhps)), this->parent()->parent(),SLOT(ApplyMorph(Morhps)));
}

void SEWidget::UpdateSE(bool toggled)
{
	QCheckBox* sender_button = (QCheckBox*)sender();

	std::string text = sender_button->text().toStdString();
	int width = (int)text[1]-'0';
	int height = (int)text[3] - '0';

	_SE->toggleSE(width, height);

	emit SEDone(current_morph);
}

void SEWidget::ApplySE(bool toggled)
{
	if (toggled)
	{
		QRadioButton* sender_button = (QRadioButton*)sender();

		std::string text = sender_button->text().toStdString();
		for (int i = 0; i < Morhps::number_of_operations; i++)
		{
			if (text == Morph_names[i])
			{
				current_morph = (Morhps)i;
				break;
			}
		}

		emit SEDone(current_morph);
	}
}

void SEWidget::ChangeThreshold(int val)
{
	if (slider_value != val)
	{
		slider_value = val;
		emit ThresholdDone(slider_value, invert, current_threshold_method);
	}
}

void SEWidget::ChangeInversion(bool toggled)
{
	invert = toggled;
	emit ThresholdDone(slider_value, invert, current_threshold_method);
}