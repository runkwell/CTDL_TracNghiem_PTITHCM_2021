/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/

#include <winbgim.h> 
#include "run.h"

//void ham1(){
//	
//	}
int main(int argc, char *argv[])
{
	initwindow(1400, 800);			// init window graphics
	setbkcolor(15);					// set background
   	cleardevice();
	setcolor(0);
	run();
	
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
