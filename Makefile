LDLIBS=-lnetfilter_queue

all: netfilter-test

netfilter-test: main.o utils.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -g -o  $@

clean:
		rm -rf netfilter-test *.o