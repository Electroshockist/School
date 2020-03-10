#include "Sample.h"
#include "Network.h"

int main(){
	Network n = Network();
	Sample s = Sample();
	s.A = 32;
	s.B = 24;

	n.Connect();
	n.Send(s);

	return 0;
}