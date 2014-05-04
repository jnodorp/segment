/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * lib.cc
 * Copyright (C) 2014 Julian Schlichtholz <julian.schlichtholz@uni-jena.de>
 * Copyright (C) 2013 Christoffer Holmstedt <christoffer.holmstedt@gmail.com>
 * Copyright (C) 2010 Salik Syed <ssyed@cs.stanford.edu>
 * Copyright (C) 2006 Pedro Felipe Felzenszwalb <pff@brown.edu>
 * 
 * segment is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * segment is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdio>
#include <cstdlib>

#include <image.hpp>
#include <segment.hpp>
#include <segment-image.hpp>

#include <opencv2/core/core.hpp>

using namespace cv;

image<rgb>* convertMatToNativeImage(Mat *input){
    int w = input->cols;
    int h = input->rows;
    image<rgb> *im = new image<rgb>(w,h);

    for(int i=0; i<input->rows; i++)
    {
        for(int j=0; j<input->cols; j++)
        {
            rgb curr;
            Vec3b intensity = input->at<Vec3b>(i,j);
            curr.b = intensity.val[0];
            curr.g = intensity.val[1];
            curr.r = intensity.val[2];
            im->data[i+j*w] = curr;
        }
    }
    return im;
}

Mat convertNativeToMat(image<rgb>* input){
    int w = input->width();
    int h = input->height();
    Mat output(Size(w,h),CV_8UC3);

    for(int i =0; i<w; i++){
        for(int j=0; j<h; j++){
            rgb curr = input->data[i+j*w];
            output.at<Vec3b>(i,j)[0] = curr.b;
            output.at<Vec3b>(i,j)[1] = curr.g;
            output.at<Vec3b>(i,j)[2] = curr.r;
        }
    }

    return output;
}

Mat segment(Mat *input, float sigma, float k, int min_size, int *num_ccs) {
    int w = input->cols;
    int h = input->rows;
    Mat output(Size(w,h),CV_8UC3);

    // 1. Convert to native format
    image<rgb> *nativeImage = convertMatToNativeImage(input);
    // 2. Run egbis algoritm
    image<rgb> *segmentetImage = segment_image(nativeImage, sigma, k, min_size, num_ccs);
    // 3. Convert back to Mat format
    output = convertNativeToMat(segmentetImage);

    return output;
}