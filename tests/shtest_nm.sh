
/usr/bin/make
nm -u libft.a
nm -u libft.a | grep -v -e _free -e _malloc -e _write | grep -v -e '^$' | grep -v _ft_ | grep -v libft.a && echo FAIL

