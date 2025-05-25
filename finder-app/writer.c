
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        syslog(LOG_USER | LOG_ERR, "Not enough arguments");
        return 1;
    }

    int fd = 0;
    fd  = open(argv[1], O_WRONLY | O_CREAT);
    if (fd == -1)
    {
        syslog(LOG_USER | LOG_ERR, "Failed to open fail %s", argv[1]);
        return 1;
    }

    syslog(LOG_USER | LOG_DEBUG, "Writing %s to file %s", argv[2], argv[1]);
    ssize_t nr;
    nr = write (fd, argv[2], strlen(argv[2]));

    close(fd);
}