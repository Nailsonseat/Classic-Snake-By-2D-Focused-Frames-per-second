#include "../Headers/Nailsonseat.h"
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <sstream>
#include <string>
#include <fcntl.h>
#include <io.h>

//template <class T>
void MoveWindow(int posx = -1, int posy = -1)
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	if (posx == -1 && posy == -1)
	{
		posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2; posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	}
	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}
void SetConsoleWindowSize(short int x, short int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (h == INVALID_HANDLE_VALUE)
		throw std::runtime_error("Unable to get stdout handle.");

	// If either dimension is greater than the largest console window we can have,
	// there is no point in attempting the change.
	{
		COORD largestSize = GetLargestConsoleWindowSize(h);
		if (x > largestSize.X)
			throw std::invalid_argument("The x dimension is too large.");
		if (y > largestSize.Y)
			throw std::invalid_argument("The y dimension is too large.");
	}


	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
		throw std::runtime_error("Unable to retrieve screen buffer info.");

	SMALL_RECT& winInfo = bufferInfo.srWindow;
	COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

	if (windowSize.X > x || windowSize.Y > y)
	{
		// window size needs to be adjusted before the buffer size can be reduced.
		SMALL_RECT info =
		{
			0,
			0,
			x < windowSize.X ? x - 1 : windowSize.X - 1,
			y < windowSize.Y ? y - 1 : windowSize.Y - 1
		};

		if (!SetConsoleWindowInfo(h, TRUE, &info))
			throw std::runtime_error("Unable to resize window before resizing buffer.");
	}

	COORD size = { x, y };
	if (!SetConsoleScreenBufferSize(h, size))
		throw std::runtime_error("Unable to resize screen buffer.");


	SMALL_RECT info = { 0, 0, x - 1, y - 1 };
	if (!SetConsoleWindowInfo(h, TRUE, &info))
		throw std::runtime_error("Unable to resize window after resizing buffer.");
}
double round_upto(double num, short int limit)
{
	double temp(0), ten(10);
	short int count(0);
	bool endpoint(false);
	while (!endpoint)
	{
		temp = num;
		temp *= ten;
		if (fmod(temp, 10) != 0) { count++; ten *= 10; }
		else { endpoint = true; }
	}
	if (count > limit)
	{
		ten = 10;
		ten = pow(ten, count);
		num *= ten;
		ten = 10;
		ten = pow(ten, count - limit);
		num /= ten;
		ten = 10;
		ten = pow(ten, limit);
		num = roundl(num) / ten;
	}
	return num;
}
template <class V>
V comnfactor(V a, V b)
{
	if (!a || !b) return 0;
	if (a == b) return a;
	if (a > b) return comnfactor(a - b, b);
	else if (a < b) return comnfactor(a, b - a);
	return -1;
}
void mode_u16()
{
	int temp = _setmode(_fileno(stdout), _O_U16TEXT);
	return;
}
void mode_ascii()
{
	int temp = _setmode(_fileno(stdout), _O_TEXT);
	return;
}
void fontsize(int a = 12, int b = 12)
{
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx((GetStdHandle(STD_OUTPUT_HANDLE)), 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx((GetStdHandle(STD_OUTPUT_HANDLE)), 0, lpConsoleCurrentFontEx);
	return;
}
void maskcursor(bool ans)
{
	ans = !ans;
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo((GetStdHandle(STD_OUTPUT_HANDLE)), &info);
	info.bVisible = ans;
	SetConsoleCursorInfo((GetStdHandle(STD_OUTPUT_HANDLE)), &info);
	return;
}
//template <class U>
void getxy(short int& a, short int& b)
{                                     //gets current console pos x and y
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	a = info.dwCursorPosition.X;
	b = info.dwCursorPosition.Y;
	return;
}
//template <class X, class Y>
void gotoxy(int x, int y)             //goes to pos x and y on console
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return;
}
int str_allint(char* arr = NULL)       //check all characters of string are made of integers
{
	char* _ptr = NULL;
	long _tmp;
	_tmp = strtol(arr, &_ptr, 10);
	if (*_ptr) return 0;
	if (!(*_ptr)) return 1;
	return -1;
}
template <class A>
void clrline(A strt, A end)
{
	COORD current({ 0,0 });
	getxy(current.X, current.Y);
	gotoxy(0, current.Y);
	for (int i = strt; i < end; i++) putch(' ');
	gotoxy(0, current.Y);
}
void go_up()
{
	short int pos_x(0), pos_y(0);
	getxy(pos_x, pos_y);
	gotoxy(pos_x, pos_y - 1);
}
void go_down()
{
	short int pos_x(0), pos_y(0);
	getxy(pos_x, pos_y);
	gotoxy(pos_x, pos_y + 1);
}
void go_left()
{
	short int pos_x(0), pos_y(0);
	getxy(pos_x, pos_y);
	gotoxy(pos_x - 1, pos_y);
}
void go_right()
{
	short int pos_x(0), pos_y(0);
	getxy(pos_x, pos_y);
	gotoxy(pos_x + 1, pos_y);
}
void navscr()
{
	int _check(0), x(0), y(0);
	while (!(_check == 13))
	{
		_check = 0;
		switch ((_check = _getch()))
		{
		case 119:
		case 72:
			go_up();
			break;
		case 115:
		case 80:
			go_down();
			break;
		case 97:
		case 75:
			go_left();
			break;
		case 100:
		case 77:
			go_right();
			break;
		}
	}
}
char _string_container_for_telltime_[100];
char* calmanip(char const* _check, int _custom_ = 0)
{
	for (int i = 0; i < 100; i++)
		_string_container_for_telltime_[i] = ' ';
	strcpy(_string_container_for_telltime_, "");
	char _custom_str_[50] = { "" };
	std::string _tmp_carrier_;
	std::ostringstream _str_convrtr_;
	time_t _curr_time_time_t;
	struct tm _curr_time_tm;
	char _weekday_inject_[7][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	char _month_inject_[12][10] = { "Janurary","Feburary","March","April","May","June","July","August","September","October","November","December" };
	char _day_inject_[3][10][10] = { {"Fir","Seco","Thi","Four","Fif","Six","Seven","Eigh","Nin","Ten"},
									{"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"},
									{"Twentie","Thirtie","Fourtie","Fiftie","Siztie","Seventie","Eightie","Ninetie" } };
	char _year_inject_[10][6] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten" };
	char _ordinal_suffix_[3][5] = { "st","nd","rd" };
	time(&_curr_time_time_t);
	localtime_s(&_curr_time_tm, &_curr_time_time_t);
	if (!(strcmp(_check, "wday")))
	{
		if (!_custom_)
		{
			strcpy(_string_container_for_telltime_, _weekday_inject_[_curr_time_tm.tm_wday]);
			return _string_container_for_telltime_;
		}
		else if (_custom_ <= 7)
		{
			strcpy(_string_container_for_telltime_, _weekday_inject_[_custom_ - 1]);
			return _string_container_for_telltime_;
		}
	}
	if (!(strcmp(_check, "wday_s")))
	{
		if (!_custom_) { _custom_ = _curr_time_tm.tm_wday + 1; }
		if (_custom_ <= 7)
		{
			_str_convrtr_ << _custom_;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_custom_str_, _tmp_carrier_.c_str());
			if (strlen(_custom_str_) == 1)
			{
				strcat(_custom_str_, "0");
				_strrev(_custom_str_);
			}
			switch (_custom_str_[0])
			{
			case '0':if (_custom_str_[1] == '1' || _custom_str_[1] == '2' || _custom_str_[1] == '3')
			{
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][_custom_ - 1]);
				strcat(_string_container_for_telltime_, _ordinal_suffix_[_custom_ - 1]);
				return _string_container_for_telltime_;
			}
					else
			{
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][_custom_ - 1]);
				strcat(_string_container_for_telltime_, "th");
				return _string_container_for_telltime_;
			}
			}
		}
	}
	if (!(strcmp(_check, "day")))
	{
		if (!_custom_)
		{
			_str_convrtr_ << _curr_time_tm.tm_mday;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_string_container_for_telltime_, _tmp_carrier_.c_str());
			return _string_container_for_telltime_;
		}
		if (_custom_ <= 31)
		{
			_str_convrtr_ << _custom_;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_string_container_for_telltime_, _tmp_carrier_.c_str());
			return _string_container_for_telltime_;

		}
	}
	if (!(strcmp(_check, "day_s")))
	{
		if (!_custom_) { _custom_ = _curr_time_tm.tm_mday; }
		if (_custom_ <= 31)
		{
			_str_convrtr_ << _custom_;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_custom_str_, _tmp_carrier_.c_str());
			if (strlen(_custom_str_) == 1)
			{
				strcat(_custom_str_, "0");
				_strrev(_custom_str_);
			}
			switch (_custom_str_[0])
			{
			case '0':if (_custom_str_[1] == '1' || _custom_str_[1] == '2' || _custom_str_[1] == '3')
			{
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][_custom_ - 1]);
				strcat(_string_container_for_telltime_, _ordinal_suffix_[_custom_ - 1]);
				return _string_container_for_telltime_;
			}
					else
			{
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][_custom_ - 1]);
				strcat(_string_container_for_telltime_, "th");
				return _string_container_for_telltime_;
			}
			case '1':
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][(int)_custom_str_[1] - 49]);
				strcat(_string_container_for_telltime_, "th");
				return _string_container_for_telltime_;
			case '2':
				if (_custom_str_[0] == '2') strcpy(_string_container_for_telltime_, "Twenty-");
			case '3':
				if (_custom_str_[0] == '3') strcpy(_string_container_for_telltime_, "Thrity-");
				if (_custom_str_[1] == '0')
				{
					strcpy(_string_container_for_telltime_, _day_inject_[2][(int)_custom_str_[0] - 50]);
					strcat(_string_container_for_telltime_, "th");
					return  _string_container_for_telltime_;
				}
				else if (_custom_str_[1] == '1' || _custom_str_[1] == '2' || _custom_str_[1] == '3')
				{
					strcat(_string_container_for_telltime_, _day_inject_[0][(int)_custom_str_[1] - 49]);
					strcat(_string_container_for_telltime_, _ordinal_suffix_[_custom_str_[1] - 49]);
					return  _string_container_for_telltime_;
				}
				else
				{
					strcat(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 50][(int)_custom_str_[1] - 49]);
					strcat(_string_container_for_telltime_, "th");
					return  _string_container_for_telltime_;
				}
			}
		}
	}
	if (!(strcmp(_check, "mon")))
	{
		if (!_custom_)
		{
			strcpy(_string_container_for_telltime_, _month_inject_[_curr_time_tm.tm_mon]);
			return _string_container_for_telltime_;
		}
		else if (_custom_ <= 12)
		{
			strcpy(_string_container_for_telltime_, _month_inject_[_custom_ - 1]);
			return _string_container_for_telltime_;
		}
	}
	if (!(strcmp(_check, "mon_s")))
	{
		if (!_custom_) { _custom_ = _curr_time_tm.tm_mon + 1; }
		if (_custom_ <= 12)
		{
			_str_convrtr_ << _custom_;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_custom_str_, _tmp_carrier_.c_str());
			if (strlen(_custom_str_) == 1)
			{
				strcat(_custom_str_, "0");
				_strrev(_custom_str_);
			}
			switch (_custom_str_[0])
			{
			case '0':if (_custom_str_[1] == '1' || _custom_str_[1] == '2' || _custom_str_[1] == '3')
			{
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][_custom_ - 1]);
				strcat(_string_container_for_telltime_, _ordinal_suffix_[_custom_ - 1]);
				return _string_container_for_telltime_;
			}
					else
			{
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][_custom_ - 1]);
				strcat(_string_container_for_telltime_, "th");
				return _string_container_for_telltime_;
			}
			case '1':
				strcpy(_string_container_for_telltime_, _day_inject_[(int)_custom_str_[0] - 48][(int)_custom_str_[1] - 49]);
				strcat(_string_container_for_telltime_, "th");
				return _string_container_for_telltime_;
			}
		}
	}
	if (!(strcmp(_check, "year")))
	{
		if (!_custom_)
		{
			_str_convrtr_ << _curr_time_tm.tm_year + 1900;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_string_container_for_telltime_, _tmp_carrier_.c_str());
			return _string_container_for_telltime_;
		}
		if (_custom_)
		{
			_str_convrtr_ << _custom_;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_string_container_for_telltime_, _tmp_carrier_.c_str());
			return _string_container_for_telltime_;
		}
		strcpy(_string_container_for_telltime_, "");
	}
	if (!(strcmp(_check, "year_s")))
	{
		if (!_custom_) { _custom_ = _curr_time_tm.tm_year + 1900; }
		if (_custom_ <= 9999)
		{
			_str_convrtr_ << _custom_;
			_tmp_carrier_ = _str_convrtr_.str();
			strcpy(_custom_str_, _tmp_carrier_.c_str());
			if (strlen(_custom_str_) == 1)
			{
				strcpy(_string_container_for_telltime_, _year_inject_[(int)_custom_str_[0] - 49]);
				return _string_container_for_telltime_;
			}
			if (strlen(_custom_str_) == 4)
			{
				strcpy(_string_container_for_telltime_, _year_inject_[(int)_custom_str_[0] - 49]);
				strcat(_string_container_for_telltime_, " thousand ");
				if (_custom_str_[1] != '0')
				{
					strcat(_string_container_for_telltime_, _year_inject_[(int)_custom_str_[1] - 49]);
					_string_container_for_telltime_[strlen(_string_container_for_telltime_) - strlen(_year_inject_[(int)_custom_str_[1] - 49])] += 32;
					strcat(_string_container_for_telltime_, " hundred ");
				}
				_custom_str_[0] = _custom_str_[2];
				_custom_str_[1] = _custom_str_[3];
			}
			if (strlen(_custom_str_) == 3)
			{
				strcpy(_string_container_for_telltime_, _year_inject_[(int)_custom_str_[0] - 49]);
				strcat(_string_container_for_telltime_, " hundred ");
				_custom_str_[0] = _custom_str_[1];
				_custom_str_[1] = _custom_str_[2];
			}
			if (strlen(_custom_str_) >= 2)
			{
				switch (_custom_str_[0])
				{
				case '0':
					if (strlen(_custom_str_) == 2) strcpy(_string_container_for_telltime_, _year_inject_[(int)_custom_str_[strlen(_custom_str_) - 1] - 49]);
					if (strlen(_custom_str_) > 2)
					{
						if (_custom_str_[1] != '0')
						{
							strcat_s(_string_container_for_telltime_, _year_inject_[(int)_custom_str_[strlen(_custom_str_) - 1] - 49]);
							_string_container_for_telltime_[strlen(_string_container_for_telltime_) - strlen(_year_inject_[(int)_custom_str_[strlen(_custom_str_) - 1] - 49])] += 32;
						}
					}
					return _string_container_for_telltime_;
				case '1':
					if (strlen(_custom_str_) == 2) strcpy(_string_container_for_telltime_, _day_inject_[1][(int)_custom_str_[1] - 49]);
					if (strlen(_custom_str_) > 2)
					{
						strcat(_string_container_for_telltime_, _day_inject_[1][(int)_custom_str_[1] - 49]);
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - strlen(_day_inject_[1][(int)_custom_str_[1] - 49])] += 32;
					}
					return _string_container_for_telltime_;
				default:
					if (strlen(_custom_str_) == 2)
					{
						strcpy(_string_container_for_telltime_, _day_inject_[2][(int)_custom_str_[0] - 50]);
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - 1] -= 69;
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - 2] += 16;
					}
					if (strlen(_custom_str_) > 2)
					{
						strcat_s(_string_container_for_telltime_, _day_inject_[2][(int)_custom_str_[0] - 50]);
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - 1] -= 69;
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - 2] += 16;
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - strlen(_day_inject_[2][(int)_custom_str_[0] - 50])] += 32;
					}
					if (_custom_str_[strlen(_custom_str_) - 1] != '0')
					{
						strcat_s(_string_container_for_telltime_, _year_inject_[_custom_str_[strlen(_custom_str_) - 1] - 49]);
						_string_container_for_telltime_[strlen(_string_container_for_telltime_) - strlen(_year_inject_[_custom_str_[strlen(_custom_str_) - 1] - 49])] += 32;
					}
					return _string_container_for_telltime_;
				}
			}
		}
	}
	return _string_container_for_telltime_;
}