#include <iostream>
#include <opencv2/opencv.hpp>
#include "scv_file.h"
#include "TCP_Client.h"
#include "cvplot.h"
#include <string>
using namespace std;

//cmake edit(C++11 ,file,head file) 
//model class is must in h

void drawdata(void){
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
  	cv::waitKey(0);
}
void drawTCP(void){
	TCP_Client Client("192.168.0.100",80);
	auto name = "dynamic recevier";
	cvplot::setWindowTitle(name, "dynamic plotting");
	cvplot::moveWindow(name, 0, 0);
	cvplot::resizeWindow(name, 600, 600);
	auto &view = cvplot::Window::current().view(name);
	auto &figure = cvplot::figure(name);
	figure.square(true);
	float data[4]={0};
    clock_t time = 0;
    if(Client.CreatConnect()){
	    for (int i = 0;char(cv::waitKey(1)!='q'); i++) {
	      auto fps = CLOCKS_PER_SEC / (float)(clock() - time);
	      time = clock();
	      {
	      	string _data;
	      	_data<<Client;
	      	std::cout<<_data<<std::endl;
	      	std::istringstream sin(_data);
	      	string m;
	      	int i=0;
	      	while(getline(sin,m,',')){
	      		std::istringstream srr(m);
	      		srr>>data[i++];
	      		// std::cout<<data[i-1]<<",";
	      	}
	      	// std::cout<<std::endl;
	      }
	      figure.series("X").add(i,data[0]);
	      figure.series("Y").add(i,data[2]);
	      figure.show(false);
	      auto string = std::to_string(fps).substr(0, 4) + " fps  " +
	                    std::to_string(i / 10.f).substr(0, 4) + "%";
	      view.drawText(string, {480, 277}, cvplot::Gray);
	      view.finish();
	      view.flush();
	    }
	}else std::cout<<"false to connect"<<Client.GetAddr()<<std::endl;
	cv::waitKey(0);
}


int main(int argc, const char** argv)
{
	drawdata();
	// drawTCP();
    return 0;
}


