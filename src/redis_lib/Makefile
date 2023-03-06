CPPFLAGS=-Wall -Wextra -g -O0 -I../redis/deps/hiredis/
CFLAGS=-Wall -Wextra -g -O0 
OBJS=ae.o anet.o monotonic.o zmalloc.o redisassert.o
all: libredis-base.a

libredis-base.a: ${OBJS}
	ar rv $@ $^
	ranlib $@



clean:
	rm -f libredis-base.a *.o
