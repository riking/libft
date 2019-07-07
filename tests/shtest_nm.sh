#!/bin/sh

nm -u github.com/riking/libft/libft.a
nm -u github.com/riking/libft/libft.a | grep -v -e _free -e _malloc -e _write | grep -v -e '^$' | grep -v _ft_ | grep -v libft.a && (echo FAIL; exit 1)

exit 0
