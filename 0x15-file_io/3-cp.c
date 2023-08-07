#include "main.h"
#include "stdio.h"
#include "stdlib.h"

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for a buffer
 * @file: name of the file the buffer is storing chars for
 * Description:
 *   - allocates 1024 bytes for the buffer
 *   - initializes the buffer to all zeros
 * Return:
 *   - pointer to the newly-allocated buffer
 *   - NULL if the buffer could not be allocated
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes file descriptors
 * @fd: file descriptor to be closed
 * Description:
 *   - checks if the file descriptor is valid
 *   - calls the `close()` system call to close the file descriptor
 * Return:
 *   - 0 if the file descriptor was closed successfully
 *   - -1 if the file descriptor was not valid or could not be closed
 */

void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Description:
 *   - checks the number of arguments
 *   - opens the source file
 *   - opens the destination file
 *   - copies the content of the source file to the destination file
 *   - closes the source file
 *   - closes the destination file
 * Return:
 *   - 0 if the program was successful
 *   - -1 if an error occurred
 */

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
