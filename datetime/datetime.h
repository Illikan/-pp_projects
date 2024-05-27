#pragma once

#include <iostream>
#include <string>
#include <exception>

class Date
{
public:
	Date(int day, int month, int year);
	Date(std::string date);
	Date(int day, std::string month, int year);
	~Date();

	double DateToJulian(int date, int month, int year);
	void JulianToDate(double JulianDate);
	std::string weekDay();
	void calculateEasterDate();

	double operator-(const Date &other);

	friend std::ostream &operator<<(std::ostream &os, const Date &date);

private:
	int curYear = 1912;
	double JulianDate = 0;

	void checkDate(int day, int month, int year);
};

class DateException : public std::exception
{
public:
	DateException(const char *message) : m_message(message) {}

	const char *what() const noexcept override
	{
		return m_message;
	}

private:
	const char *m_message;
};