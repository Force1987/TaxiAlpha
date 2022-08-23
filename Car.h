#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Driver;
class Car
{
	string model;
	string color;
	int num;
	Driver* driver = NULL;
	bool status = false;
	Car() {}
public:
	Car(string model, string color, int num) :model(model), color(color), num(num) {}
	~Car() {
		driver = NULL;
	}
	bool getStatus() {
		return status;
	}
	void print() {
		cout << "Model: " << model << ", Color: " << color << ", Num: " << num << endl;
	}
	void release(Driver* drv) {
		if (drv == this->driver)
		{
			status = false;
			driver = NULL;
		}
	}
	void getIn(Driver* driver) {
		this->driver = driver;
		status = true;
	}
};

