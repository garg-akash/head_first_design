#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Observer
{
public:
	int id;	//without id how to remove an observer?
	virtual void update(float temp, float humidity, float pressure) = 0;
};
class DisplayElement
{
public:
	virtual void display() = 0;
};
class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	void removeObserver(Observer* o) {}
	virtual void notifyObservers() = 0;
};

bool operator==(const Observer& left, Observer* right)
{
	return left.id == (*right).id;
}
class WeatherData : public Subject
{
	// unordered_set<Observer> observers;
	vector<Observer*>* observers;
	float temperature;
	float humidity;
	float pressure;
public:
	WeatherData()
	{
		observers = new vector<Observer*>();
	}
	// ~WeatherData();
	void registerObserver(Observer* o)
	{
		// this->observers.insert(o);
		(*observers).push_back(o);
	}	
	void removeObserver(Observer* o)
	{
		// if(observers.find(o) != observers.end())
		// 	this->observers.erase(o);
		auto it = std::find ((*observers).begin(), (*observers).end(), o);
		(*observers).erase(it);
	}
	void notifyObservers()
	{
		// cout << "Called " << (*observers).size() << "\n";
		for(auto observer : *observers)
			(*observer).update(temperature,humidity,pressure);
	}
	void measurementsChanged()
	{
		notifyObservers();
	}
	void setMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		measurementsChanged();
	}
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
	float temperature;
	float humidity;
	// float pressure;
	Subject* weatherData;
public:
	CurrentConditionsDisplay(Subject* weatherData)
	{
		this->weatherData = weatherData;
		this->weatherData->registerObserver(this); //IMPORTANT TO UNDERSTAND
	}
	void update(float temperature, float humidity, float pressure)
	{
		// cout << "Called overridden update\n";
		this->temperature = temperature;
		this->humidity = humidity;
		display();
	}
	void display()
	{
		cout << "Current conditions: " << temperature << " F degrees and " << humidity << " humidity\n";
	}
};

class HeatIndexDisplay : public Observer, public DisplayElement
{
	float t;
	float rh;
	float heatIndex;
	Subject* weatherData;
public:
	HeatIndexDisplay(Subject* weatherData)
	{
		this->weatherData = weatherData;
		this->weatherData->registerObserver(this); //IMPORTANT TO UNDERSTAND
	}
	void update(float temperature, float humidity, float pressure)
	{
		// cout << "Called overridden update\n";
		this->t = temperature;
		this->rh = humidity;
		this->heatIndex = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +
            (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +
            (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
            (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 *  
            (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
            (0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +     
            0.000000000843296 * (t * t * rh * rh * rh)) -
            (0.0000000000481975 * (t * t * t * rh * rh * rh)));
		display();
	}
	void display()
	{
		cout << "Heat index is " << heatIndex << "\n";
	}
};

int main(int argc, char const *argv[])
{
	WeatherData weatherData;// = new WeatherData();
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(&weatherData);
	HeatIndexDisplay* heatIndexDisplay = new HeatIndexDisplay(&weatherData);
	weatherData.setMeasurements(80,65,30.4);
	weatherData.setMeasurements(90,72,31.5);
	return 0;
}