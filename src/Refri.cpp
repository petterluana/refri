#include "Refri.h"
#include <string.h>
#include <iostream>
using namespace std;

Refri::Refri(){
	valor=0;
}

Refri::Refri(string name, float value){
	nome=name;
	valor=value;
}
