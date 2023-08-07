#include "main.h"
#include "stdio.h"

/**
 * append_text_to_file - appends text to file
 * @filename: pointer to file name
 * @text_content: text to append
 * Description:
 *   - opens the file in append mode
 *   - writes the specified text to the end of the file
 *   - closes the file
 * Return:
 *   - 1 if the text was appended successfully
 *   - -1 if the file could not be opened
 *   - -1 if the file does not exist or the user lacks write permissions
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
