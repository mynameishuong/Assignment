/**
* Writes a string to a file, replacing any existing contents.
* Usage: writer <writefile> <writestr>
*
* The directory containing writefile is assumed to already exist.
* All errors are reported through syslog using the LOG_USER facility.
*
* Author: Sarkar22
*/

#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	const char *writefile;
	const char *writestr;
	size_t remaining;
	ssize_t written;
	int fd;

	openlog("writer", LOG_PID, LOG_USER);

	if (argc != 3) {
		syslog(LOG_ERR, "Invalid number of arguments: %d, expected 2", argc - 1);
		syslog(LOG_ERR, "Usage: %s <writefile> <writestr>", argv[0]);
		closelog();
		return 1;
	}

	writefile = argv[1];
	writestr = argv[2];

	fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		syslog(LOG_ERR, "Could not open %s for writing: %m", writefile);
		closelog();
		return 1;
	}

	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

	remaining = strlen(writestr);
	while (remaining > 0) {
		written = write(fd, writestr, remaining);
		if (written == -1) {
			syslog(LOG_ERR, "Could not write to %s: %m", writefile);
			close(fd);
			closelog();
			return 1;
		}
		remaining -= written;
		writestr += written;
	}

	if (close(fd) == -1) {
		syslog(LOG_ERR, "Could not close %s: %m", writefile);
		closelog();
		return 1;
	}

	closelog();
	return 0;
}
