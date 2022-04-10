/*
 * Date.h
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#ifndef DATE_H_
#define DATE_H_

class Date
{
private:
	int m_day, m_month, m_year;

public:
	Date();
	bool isEqual(Date dd);

	int getDay();
	int getMonth();
	int getYear();

//	void serDay(int d);
//	void serMonth(int m);
//	void serYear(int y);

	int compare(Date d2);
	void compareDate(int flg);
	void printDate();
};

#endif /* DATE_H_ */
