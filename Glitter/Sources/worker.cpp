#include "worker.h"
#include "helper.h"
#include <iostream>


int Job::foo(int x){
	print_C("Starting job thread id=");
	std::cout << std::this_thread::get_id() << "\n";
	
	print("done\n");
	return 0;
}
