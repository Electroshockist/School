#include "Sample.h"
#include "Network.h"

int main(){
	Network n = Network();
	Sample s = Sample();
	s.A = 32;
	s.B = 24;

	if(n.Connect() != EXIT_SUCCESS){
		return EXIT_FAILURE;
	}
	if(n.Recieve(s) != EXIT_SUCCESS){
		return EXIT_FAILURE;
	}
	//n.Send<Sample>(s);

	return 0;
}