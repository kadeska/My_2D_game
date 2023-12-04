#pragma once
#include "worker.h"
#include <iostream>

struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << ":Timer took: ";
		std::cout << ms << "ms\n";
	}
};

//printf() without color or custom
void print(const char* text);
//printf() with RED color
void print_R(const char* text);
//printf() with GREEN color
void print_G(const char* text);
//printf() with YELLOW color
void print_Y(const char* text);
//printf() with BLUE color
void print_B(const char* text);
//printf() with MAGENTA color
void print_M(const char* text);
//printf() with CYAN color
void print_C(const char* text);

int startThreadedJob(Job j);
