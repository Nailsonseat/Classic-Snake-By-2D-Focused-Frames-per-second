#ifndef Nailsonseat
#define Nailsonseat

//template <class T>
void MoveWindow(int, int);
void SetConsoleWindowSize(short int, short int);
double round_upto(double, short int);
template <class V>
V comnfactor(V, V);
void mode_u16();
void mode_ascii();
void fontsize(int, int);
void maskcursor(bool);
//template <class U>
void getxy(short int&, short int&);
//template <class X,class Y>
void gotoxy(int, int);
int str_allint(char*);
template <class A>
void clrline(A, A);
void go_up();
void go_down();
void go_left();
void go_right();
void navscr();
char* calmanip(char const*, int);
#endif