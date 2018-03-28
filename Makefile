C=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++11
LDFLAGS=
LDLIBS= -lm

SRCS=main.cpp zbiorPunktow.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: zbiorPunktow_bin
debug: CPPFLAGS+=-g
debug: LDFLAGS+=-g
debug: zbiorPunktow_bin

zbiorPunktow_bin: $(OBJS)
	$(CXX) $(LDFLAGS)  $(OBJS) -o zbiorPunktow_bin  $(LDLIBS) 

main.o: main.cpp zbiorPunktow.h

zbiorPunktow.o: zbiorPunktow.cpp zbiorPunktow.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) zbiorPunktow_bin