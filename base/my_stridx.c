int my_stridx(const char *str, char c)
{
    for (char *p = str; *p != '\0'; p++)
        if (*p == c)
            return p - str;
    return -1;
}
