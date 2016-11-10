list: pid.c
	gcc pid.c -o pid

run: pid
	./pid

clean:
	rm pid
	rm *~
