#include <stdio.h>
#include <stdatomic.h>

_Atomic int storage = 0;


void worker(){

	atomic_store(&storage, 10);
}

int main(){

}