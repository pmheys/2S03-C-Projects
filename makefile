CFLAGS = -Wall -g -ansi -O2 -std=c99 -pg
OBJS1 = denoise.o timing.o main_filter.o

denoise: $(OBJS1)
	$(CC) -o $@ $?



clean:
	rm -rf $(OBJS1)
	rm denoise
