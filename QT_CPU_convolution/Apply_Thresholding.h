#pragma once

#include <QImage>

enum Thresholding_methods
{
	manual,
	adaptive,
	otsu,
	number_of_methods,
};

static char* Threshold_method_names[] =
{
	"Manual Threshold",
	"Adaptive Threshold",
	"Otsu Threshold",
	"End of methods",
};

struct Apply_Thresholding
{
	const static unsigned int abs_delta_max = 1;
	static void Apply_Threshold(QImage* image_out, QImage* image_in, int start_threshold, Thresholding_methods method, bool invert)
	{
		switch (method)
		{
		case manual:
			Apply_Manual_Threshold(image_out, image_in, start_threshold, invert);
			break;
		case adaptive:
			Apply_Adaptive_Threshold(image_out,image_in,start_threshold,invert);
			break;
		case otsu:
			break;
		default:
			break;
		};
	}
	private:
	static void Apply_Manual_Threshold(QImage* image_out, QImage* image_in, int threshold, bool invert)
	{
		int width = image_in->width();
		int height = image_in->height();
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{
				int above_val = 255;
				int below_val = 0;
				if (invert)
				{
					above_val = 0;
					below_val = 255;

				}
				if (image_in->pixelColor(i, j).value() > threshold)
					image_out->setPixel(i, j, qRgb(above_val, above_val, above_val));
				else
					image_out->setPixel(i, j, qRgb(below_val, below_val, below_val));
			}
	}

	static void Apply_Adaptive_Threshold(QImage* image_out, QImage* image_in, int threshold, bool invert)
	{
		int width = image_in->width();
		int height = image_in->height();
		int image_size = width * height;
		int delta_threshold = 256;
		while (delta_threshold > abs_delta_max)
		{
			int above_counter = 0;
			
			int intensity_above = 0;
			int intensity_below = 0;
			for (int i = 0; i < width; i++)
				for (int j = 0; j < height; j++)
				{
					int val = image_in->pixelColor(i, j).value();
					if (val > threshold)
					{
						above_counter++;
						intensity_above += val;
					}
					else
						intensity_below += val;
				}
			double mean_above = (double)intensity_above / above_counter;
			double mean_below = (double)intensity_below / (image_size - above_counter);

			int threshold_new = (int)((mean_above + mean_below) / 2);
			delta_threshold = threshold_new - threshold;
			if (delta_threshold < 0)
				delta_threshold = -delta_threshold;
			threshold = threshold_new;
		}

		Apply_Manual_Threshold(image_out,image_in,threshold,invert);
	}


};