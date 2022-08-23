#pragma once
#include <iostream>
#include <Windows.h>
#include "Car.h"
using std::string;
using std::cout;
using std::endl;

class Driver
{
private:

	class Order
	{
		friend Driver;
		static int counter;
		int number;
		double cost;
		double margin;
		double distance;
		Order() {}
	public:
		Order(double& distance):distance(distance) {
			this->number = ++counter;
			int rate;
			SYSTEMTIME st;
			GetLocalTime(&st);
			if (st.wHour >= 17 && st.wHour < 20) rate = 30;
			else if (st.wHour > 7 && st.wHour < 10 || st.wHour == 7 && st.wMinute >= 30) rate = 30;
			else rate = 25;
			cost = distance * rate;
			if (cost < 52) cost = 52;
			margin = cost * 0.15;
		}
	};
	

	int number;
	string name;
	string phone;
	Car* car = NULL;
	bool employed = false;
	int ordersCount=0;
	Order** orders = NULL;
	double income=0.0;
	Driver() {}

public:
	Driver(int number, string name, string phone) {
		this->name = name;
		this->phone = phone;
		this->number = number;
	}
	~Driver() {
		if (orders != NULL) {
			for (unsigned int i = 0; i < _msize(orders) / sizeof(orders[0]); i++)
				delete orders[i];
			delete[] orders;
		}
		car = NULL;
	}
	string getName() {
		return this->name;
	}

	bool isOnline() {
		if (this->car == NULL)
			return false;
		else return true;
	}

	bool isEmployed() {
		return employed;
	}
	
	void OrderStatus() {
		cout << "Order #: " << orders[ordersCount - 1]->number << endl <<
			"Distance: " << orders[ordersCount - 1]->distance << endl <<
			"Cost: "<< orders[ordersCount - 1]->cost<<endl<<
			"Driver: " << this->name << endl <<
			"Phone: " << this->phone << endl;
	}

	void assignAnOrder(double& distance) {
		if (car == NULL) {
			cout << "You can't accept an order without a car\n";
			return;
		}
		Order** buf = new Order* [++ordersCount];
		for (int i = 0; i < ordersCount - 1; i++)
			buf[i] = orders[i];
		buf[ordersCount - 1] = new Order(distance);
		delete[]orders;
		orders = buf;
		employed = true;
		cout << "Order # "<< orders[ordersCount - 1]->number <<" assigned to "<<name<<endl;
	}

	void orderComplete() {
		income += orders[ordersCount - 1]->cost * 0.85;
		employed = false;
		cout << this->name << " has "; 
		cout.setf(std::ios::fixed, std::ios::floatfield); 
		cout.precision(2); 
		cout << income << " rubles on his account\n";
	}

	void orderÑancellation() {
		cout << "Order # "<<orders[ordersCount-1]->number<<" cancelled\n";
		Order** buf = new Order * [--ordersCount];
		for (int i = 0; i < ordersCount; i++)
			buf[i] = orders[i];
		delete[]orders;
		orders = buf;
		employed = false;
	}

	void getInTheCar(Car* car) {
		if (car != NULL) {
			this->car = car;
			car->getIn(this);
			cout << this->name << " is in the ";
			car->print();
		}
		else
			cout << "Couldn't find a free car\n";
	}

	void releaseTheCar() {
		this->car->release(this);
		car = NULL;
		cout << this->name << " left the car\n";
	}

	void print() {
		cout.width(3);
		cout << "Num: " << number << ", Name :  " << name << ", Phone : " << phone << endl;
	}
};


