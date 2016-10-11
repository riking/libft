
grep '#include' ft*.c | grep -v libft.h | grep -v '<stdlib.h>' | grep -v '<unistd.h>' && echo FAIL

