#pragma once
#include <thread>
class Job {
public:
	//this is a function to be run by a new thread
	int foo(int x);
};