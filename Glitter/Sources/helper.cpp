#include <iostream>
#include <chrono>
#include "helper.h"

#define ANSI_COLOR_RED  "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print(const char *text) {
	printf(text);
}
void print_R(const char* text) {
	printf(ANSI_COLOR_RED);
	printf(text);
	printf(ANSI_COLOR_RESET);
}
void print_G(const char* text) {
	printf(ANSI_COLOR_GREEN);
	printf(text);
	printf(ANSI_COLOR_RESET);
}
void print_Y(const char* text) {
	printf(ANSI_COLOR_YELLOW);
	printf(text);
	printf(ANSI_COLOR_RESET);
}
void print_B(const char* text) {
	printf(ANSI_COLOR_BLUE);
	printf(text);
	printf(ANSI_COLOR_RESET);
}
void print_M(const char* text) {
	printf(ANSI_COLOR_MAGENTA);
	printf(text);
	printf(ANSI_COLOR_RESET);
}
void print_C(const char* text) {
	printf(ANSI_COLOR_CYAN);
	printf(text);
	printf(ANSI_COLOR_RESET);
}

int startThreadedJob(Job j) {
	std::thread threaded_obj(&Job::foo, &j, 1);
	threaded_obj.detach();
	
	return 0;
}
