#include "main.h"
#include "stdlib.h"

/**
 * create_file - creates a file
 * @filename: pointer to the file name
 * @text_content: the content of the file
 * Description:
 *   - opens the file in write mode
 *   - writes the specified content to the file
 *   - closes the file
 * Return:
 *   - 1 if the file was created successfully
 *   - -1 if the file could not be created
 */

int create_file(const char *filename, char *text_content)
{
	int i = 0, file;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";


	while (text_content[i] != '\0')
	{
		i++;
	}

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	write(file, text_content, i);

	return (1);
}
