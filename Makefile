OUTFILE = app

CFLAGS = -Wall -Werror

all: app

app:
	gcc $(CFLAGS) main.c quaternion.c gyroscope.c accelerometer.c -lm
