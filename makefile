unique: unique.o lines.o match.o
	gcc -o unique unique.o lines.o match.o

unique.o: unique.c
	gcc -c unique.c

lines.o: lines.c lines.h
	gcc -c lines.c

match.o: match.c match.h
	gcc -c match.c
