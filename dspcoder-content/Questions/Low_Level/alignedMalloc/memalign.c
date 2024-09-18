#include <stdio.h>
#include <stdlib.h>

void *aligned_memory(size_t required, size_t alignment){
	void *p1;
	void **p2;

	p1 = malloc(alignment - 1 + sizeof(void *) + required);
	uint64_t new_addr = (((size_t)p1 + alignment - 1 + sizeof(void *)) & ~(alignment - 1)); 
	int size_of_new_Addr = sizeof(new_addr); 
	p2 = (void **)new_addr;

	p2[-1] = p1;
	return p2;
}

void free_aligned(void *p) {
	free(((void **)p)[-1]);
}

int main (int argc, char *argv[]) {
	
	int required = 10;
	int alignment = 5;

	void *aligned_p = aligned_memory(required, alignment);

	printf("%p\n", aligned_p);

	return 0;
}
