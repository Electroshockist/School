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
	Sample *s = new Sample();
	n.Recieve<Sample*>(s);
	//n.Send<Sample>(s);

	return 0;
}