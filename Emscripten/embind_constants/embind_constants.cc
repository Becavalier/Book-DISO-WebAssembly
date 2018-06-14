#include <emscripten/bind.h>
#include <string>
#include <vector>

using namespace emscripten;

bool val_bool = true;
char val_char = 'c';

signed char val_s_char = 'c';
unsigned char val_u_char = 'c';

short val_short = 100;
signed short val_s_short = -100;
unsigned short val_u_short = 100;

int val_int = 100;
signed int val_s_int = 100;
unsigned int val_u_int = 100;

long val_long = 100;
signed long val_s_long = -100;
unsigned long val_u_long = 100;

float val_float = 1.5;
double val_double = 1.5;

std::string val_string = "YHSPY";
std::wstring val_wstring = L"于航";


EMSCRIPTEN_BINDINGS(module) {
  constant("val_bool", val_bool);
  constant("val_char", val_char);
  constant("val_s_char", val_s_char);
  constant("val_u_char", val_u_char);
  constant("val_short", val_short);
  constant("val_s_short", val_s_short);
  constant("val_u_short", val_u_short);
  constant("val_int", val_int);
  constant("val_s_int", val_s_int);
  constant("val_u_int", val_u_int);
  constant("val_long", val_long);
  constant("val_s_long", val_s_long);
  constant("val_u_long", val_u_long);
  constant("val_float", val_float);
  constant("val_double", val_double);
  constant("val_string", val_string);
  constant("val_wstring", val_wstring);
}