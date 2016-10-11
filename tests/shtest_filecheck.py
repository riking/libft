# version 1 by Matthew Hurd <mhurd@student.42.us.org>
# version 3 by Kane York <kyork@student.42.us.org>
#   run make and check libft.a contents
# version 4 by Kane York <kyork@student.42.us.org>
#   readd broken prototype parsing, fix to be more robust
#   print files that don't #include libft.h

import os
from subprocess import Popen, PIPE
import sys

ft_names = [
"ft_memset.c",
"ft_bzero.c",
"ft_memcpy.c",
"ft_memccpy.c",
"ft_memmove.c",
"ft_memchr.c",
"ft_memcmp.c",
"ft_strlen.c",
"ft_strdup.c",
"ft_strcpy.c",
"ft_strncpy.c",
"ft_strcat.c",
"ft_strncat.c",
"ft_strlcat.c",
"ft_strchr.c",
"ft_strrchr.c",
"ft_strstr.c",
"ft_strnstr.c",
"ft_strcmp.c",
"ft_strncmp.c",
"ft_atoi.c",
"ft_isalpha.c",
"ft_isdigit.c",
"ft_isalnum.c",
"ft_isascii.c",
"ft_isprint.c",
"ft_toupper.c",
"ft_tolower.c",
"ft_memalloc.c",
"ft_memdel.c",
"ft_strnew.c",
"ft_strdel.c",
"ft_strclr.c",
"ft_striter.c",
"ft_striteri.c",
"ft_strmap.c",
"ft_strmapi.c",
"ft_strequ.c",
"ft_strnequ.c",
"ft_strsub.c",
"ft_strjoin.c",
"ft_strtrim.c",
"ft_strsplit.c",
"ft_itoa.c",
"ft_putchar.c",
"ft_putstr.c",
"ft_putendl.c",
"ft_putnbr.c",
"ft_putchar_fd.c",
"ft_putstr_fd.c",
"ft_putendl_fd.c",
"ft_putnbr_fd.c"
]

srcnames = ft_names[:]
no_libfth = []

for filename in sorted(os.listdir(os.getcwd())):
	if filename[0] != '.' and filename[-1] == 'c' and 'ft_' in filename:
		try:
			srcnames.remove(filename)
		except:
			# extra file
			continue
		with open(os.getcwd() + "/" + filename) as data:
			d = data.read().splitlines()
			found = 0
			for l in d:
				if ((filename[:-2] + "(") in l) and ("static" not in l):
					l = l.expandtabs(4)
					print l + ";"
				if "#include \"libft.h\"" in l:
					found = 1
			if found != 1:
				no_libfth.append(filename)

make = Popen(["make", "libft.a"], stdin=None, stdout=PIPE, stderr=PIPE)
output, err = make.communicate(input=None)

sys.stdout.write(output)
sys.stdout.write(err)

if make.returncode != 0:
	sys.exit("[filecheck.py] could not make")

ar = Popen(["ar", "t", "libft.a"], stdin=None, stdout=PIPE, stderr=PIPE)
output, err = ar.communicate(input=None)

if ar.returncode != 0:
	print err
	sys.exit("[filecheck.py] could not inspect libft.a")
libnames = ft_names[:]
have_symdef = False
for filename in sorted(output.splitlines()):
	if filename == "__.SYMDEF SORTED":
		have_symdef = True
		continue
	head, _, _ = filename.rpartition('.o')
	filename = head + '.c'
	try:
		libnames.remove(filename)
	except Exception, e:
		print "Extra:", filename
		continue

print "Missing source files: ", srcnames
print "Missing #include libft.h: ", no_libfth
print "libft.a missing files: ", [x for x in libnames if x not in srcnames]
