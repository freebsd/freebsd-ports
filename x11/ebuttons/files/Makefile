LIBS	= -L${X11BASE}/lib -lepplet
CFLAGS	+= -I${X11BASE}/include

all: E-Buttons.epplet

E-Buttons.epplet: E-buttons.c
	${CC} ${CFLAGS} ${.ALLSRC} ${LIBS} -o ${.TARGET}

clean:
	rm -f E-Buttons.epplet E-buttons.epplet
