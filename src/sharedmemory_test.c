/*
 ============================================================================
 Name        : sharedmemory_test.c
 Author      : LI YUE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incr1(int*, int, const char*);
void incr2(int, const char*, const char*);
void incr_anonymous(int, const char*);
void incr_dev_zero(int, const char*);

int count = 0;
const char* sem_name = "mysem";
const char* pathname = "/home/ly/incr2";

int main(void) {
	incr1(&count,10,sem_name);
	incr2(10,pathname,sem_name);
	incr_anonymous(10,sem_name);
	incr_dev_zero(10, sem_name);
	return EXIT_SUCCESS;
}

