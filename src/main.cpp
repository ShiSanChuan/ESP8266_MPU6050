#include <iostream>
#include <opencv2/opencv.hpp>
#include "scv_file.h"
#include "TCP_Client.h"
#include "cvplot.h"

using namespace std;
//cmake edit(C++11 ,file,head file) 
//model class is must in h
int main(int argc, const char** argv)
{
	//open csv and put data into image 
    sFILE<double>  file("/home/ssc/C++work/MYfirstProject/data.csv");
    sFILE<double> _1txt("/home/ssc/C++work/MYfirstProject/1.txt");
    sFILE<double> _2txt("/home/ssc/C++work/MYfirstProject/2.txt");
    sFILE<double> _3txt("/home/ssc/C++work/MYfirstProject/3.txt");
    sFILE<double> _4txt("/home/ssc/C++work/MYfirstProject/4.txt");
    sFILE<double> _5txt("/home/ssc/C++work/MYfirstProject/5.txt");
    sFILE<double> _6txt("/home/ssc/C++work/MYfirstProject/6.txt");


	std::vector<float> data;
	{
		auto name="1";
		cvplot::setWindowTitle(name, "up hand");
	    cvplot::moveWindow(name, 0, 0);
	    cvplot::resizeWindow(name, 600, 180);
		auto &figure=cvplot::figure(name);
		data.clear();
		for(int i=0;i<_1txt.GetRowSize();i++)
			data.push_back(_1txt[i][0]);
		figure.series("1angle")
					.setValue(data)
	  				.color(cvplot::Green);
	  	data.clear();
	  	for (int i = 0; i < _2txt.GetRowSize(); ++i)
	  		data.push_back(_2txt[i][0]);
	  	figure.series("2angle")
	  				.setValue(data)
	  				.color(cvplot::Red);
	  	figure.show(false);
  	}

  	{
  		auto name="2";
	  	cvplot::setWindowTitle(name, "walk");
	    cvplot::moveWindow(name, 0, 180);
	    cvplot::resizeWindow(name, 600, 180);
		auto &figure=cvplot::figure(name);
		data.clear();
		for(int i=0;i<_3txt.GetRowSize();i++)
			data.push_back(_3txt[i][0]);
		figure.series("3angle")
					.setValue(data)
	  				.color(cvplot::Green);
	  	data.clear();
	  	for (int i = 0; i < _4txt.GetRowSize(); ++i)
	  		data.push_back(_4txt[i][0]);
	  	figure.series("4angle")
	  				.setValue(data)
	  				.color(cvplot::Red);
	  	figure.show(false);
  	}

  	{
  		auto name="3";
		cvplot::setWindowTitle(name, "climb");
	    cvplot::moveWindow(name, 0, 360);
	    cvplot::resizeWindow(name, 600, 180);
		auto &figure=cvplot::figure(name);
		data.clear();
		for(int i=0;i<_5txt.GetRowSize();i++)
			data.push_back(_5txt[i][0]);
		figure.series("5angle")
					.setValue(data)
	  				.color(cvplot::Green);
	  	data.clear();
	  	for (int i = 0; i < _6txt.GetRowSize(); ++i)
	  		data.push_back(_6txt[i][0]);
	  	figure.series("6angle")
	  				.setValue(data)
	  				.color(cvplot::Red);
	 	figure.show(false);
	}

	{
		auto name="4";
		cvplot::setWindowTitle(name, "dynamic plotting");
		cvplot::moveWindow(name, 0, 520);
		cvplot::resizeWindow(name, 600, 0);
		auto &view = cvplot::Window::current().view(name);
		view.finish();
		view.flush();
	}
//?????????
  	cv::waitKey(0);
    return 0;
}


