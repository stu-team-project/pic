#include "OriginPicture.h"


//OriginPicture::OriginPicture(QSize imgSize, QWidget* parent = Q_NULLPTR)
//	: QWidget(parent)
//{
//	if (imgSize != QSize(0, 0)) {
//		img = new QImage(imgSize, QImage::Format_ARGB32);
//		img->fill(Qt::white);
//		resizeWidget(img->size());
//		setPainter();
//		setDataPtr();
//
//	}
//}

//OriginPicture::OriginPicture()
//{
//}

OriginPicture::~OriginPicture()
{
}



//void OriginPicture::drawPicture(T_Picture& Pic)
//{
//	int width = Pic.getWidth();
//	int height = Pic.getHeight();
//
//}

bool OriginPicture::openImage(const QString& fileName)
{
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	QSize newSize = loadedImage.size().expandedTo(size());
	resizeImage(&loadedImage, newSize);
	image = loadedImage;
	modified = false;
	update();
	return true;
}

void OriginPicture::drawSomethink()
{
	QColor tmp;
	int red = 0;
	int green = 0;
	int blue = 0;
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++) {

			if (red >255)
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			tmp.setRed(red);
			tmp.setGreen(green);
			tmp.setBlue(blue);

			this->setPixel(i, j, tmp);

			red++;
			green++;
			blue++;
		}
	}
}

void OriginPicture::resizeImage(QImage* image, const QSize& newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}
