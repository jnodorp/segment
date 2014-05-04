segment
=======

Library of an opencv wrapper around the efficient graph based superpixel segmentation algorithm described by Pedro F. Felzenszwalb and Daniel P. Huttenlocher.

Basically this library consists of the C++ implementation by Pedro F. Felzenszwalb (http://cs.brown.edu/~pff/segment/) and the opencv wrapper by Christoffer Holmstedt (https://github.com/christofferholmstedt/opencv-wrapper-egbis).

installation
------------
For instructions view the INSTALL file.

(example) usage
---------------
```C++
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <segment.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	Mat img = imread("image.jpg", CV_LOAD_IMAGE_COLOR);

	if (!img.data)
	{
		cout << "Could not open or find the image." << endl;
		return -1;
	}

	int num_ccs;
	Mat egbisImage = segment(&img, 0.5, 500, 200, &num_ccs);

	namedWindow(imageName, CV_WINDOW_AUTOSIZE);
	imshow(imageName, img);

	namedWindow("EGBIS", CV_WINDOW_AUTOSIZE);
	imshow("EGBIS", egbisImage);

	waitKey(0);
	return 0;
}
```


original readme
---------------

Implementation of the segmentation algorithm described in:

Efficient Graph-Based Image Segmentation
Pedro F. Felzenszwalb and Daniel P. Huttenlocher
International Journal of Computer Vision, 59(2) September 2004.

The program takes a color image (PPM format) and produces a segmentation
with a random color assigned to each region.

1) Type "make" to compile "segment".

2) Run "segment sigma k min input output".

The parameters are: (see the paper for details)

sigma: Used to smooth the input image before segmenting it.
k: Value for the threshold function.
min: Minimum component size enforced by post-processing.
input: Input image.
output: Output image.

Typical parameters are sigma = 0.5, k = 500, min = 20.
Larger values for k result in larger components in the result.
