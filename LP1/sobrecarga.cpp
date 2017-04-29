/* --Classe data-- 
 * dd mm aa
 * Data d1, d2;
 * Data d3 = d3 (+ -) 20;
 * d++, d--, d1>d2, d1<d2
 * comparar duas datas
 * cout para data
 */
#include <iostream>

class Date 
{
	using day_type = unsigned short;
	using month_type = unsigned short;
	using year_type = size_t;
	
	private:	
	day_type m_day;
	month_type m_month;
	year_type m_year;

											//J   F   M   A   M   J   J   A   S   O   N   D
	static constexpr day_type month_len[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	public:

	Date( day_type d=1, month_type m = 1, year_type y = 1990 )
		: m_day( d )
		, m_month ( m )
		, m_year (y)
	{	}

	Date ( const Date & clone )
	{
		m_day = clone.m_day;
		m_month = clone.m_month;
		m_year = clone.m_year;
	}

	Date & operator=( const Date & rhs )
	{
		if ( this != & rhs )
		{
			m_day = rhs.m_day;
			m_month = rhs.m_month;
			m_year = rhs.m_year;
		}
		return *this;
	}

	void set_day(day_type new_day)
	{
		m_day = new_day;
	}

	void set_month(month_type new_month)
	{
		m_month = new_month;
	}

	void set_year(year_type new_year)
	{
		m_year = new_year;
	}

	day_type get_day( void )
	{
		return m_day;	
	}

	month_type get_month( void )
	{
		return m_month;	
	}

	year_type get_year( void )
	{
		return m_year;	
	}

	friend std::ostream & operator<<( std::ostream & os , const Date & d )
	{
		os << "[ " << d.m_day << " / " << d.m_month << " / " << d.m_year << " ]";
		return os;
	}

	//d1 > d2?
	// 20170425
	bool operator> ( const Date & rhs )
	{
		auto this_date = m_year*10000 + m_month*100 + m_day;
		auto rhs_date = rhs.m_year*10000 + rhs.m_month*100 + rhs.m_day;
		return this_date > rhs_date;
	}


};

// std::ostream & operator<<( std::ostream & os , const Date & d )
// {
// 	os << "[" << d.get_day() << "/" << d.get_month() << "/" << d.get_year() << "]";
// 	return os;
// }

//fazer os dois
Date operator+ ( const Date & d, size_t days )
{
	return Date();
}

Date operator+ ( size_t days, const Date & d)
{
	return Date();
}

int main () 
{
	Date d( 27, 4, 2017 );
	Date d1; // 1/1/1990

	std::cout << ">>>Data d = " << d << "\n";
	std::cout << ">>>Data d1 = " << d1 << "\n";

	Date d2;
	d2.set_day(25);
	d2.set_month( 4 );
	d2.set_year( 2017 );
	std::cout << ">>>Data d2 = " << d2 << "\n";

	d1=d2;
	std::cout << ">>>Depois " << d1 << "\n";

//fazer
	{
		Date d1(26, 4, 2017);
		Date d2 = d1 + 120;
		Date d3 = 120 + d1;
	}

	// if ( d2 == d1 )
	// {

	// }

	// if ( d2 != d1 )
	// {

	// }

	// std::cout << d1 << std::endl;

	// auto days = d2 - d1;
	// Date d3 = d2 + 4; // 4 dias a frente da data especifica;

	return EXIT_SUCCESS;
}