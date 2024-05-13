/*
 * filename:	syscalls.c
 * date:	05.12.24
 * author:	Lucas Merritt/merrittlj
 * description:	implementation for common syscalls
 */

#include <sys/stat.h>
#include <stddef.h>

#include "syscalls.h"
#include "hal.h"


int _write(int fd, char *ptr, int len)
{
	(void)fd, (void)ptr, (void)len;
	if (fd == 1) uart_write_buf(USART1, ptr, (size_t)len);
	return -1;
}

int _fstat(int fd, struct stat *st)
{
	(void)fd, (void)st;
	return -1;
}

void *_sbrk(int incr)
{
	extern char _end;
	static unsigned char *heap = NULL;
	unsigned char *prev_heap;
	if (heap == NULL) heap = (unsigned char *)&_end;
	prev_heap = heap;
	heap += incr;
	return prev_heap;
}

int _close(int fd)
{
	(void)fd;
	return -1;
}

int _isatty(int fd)
{
	(void)fd;
	return 1;
}

int _read(int fd, char *ptr, int len)
{
	(void)fd, (void)ptr, (void)len;
	return -1;
}

int _lseek(int fd, int ptr, int dir)
{
	(void)fd, (void)ptr, (void)dir;
	return 0;
}
