SORT_SRCS = lmsort1.c lmsort2.c lmsort3.c lqsort1.c lqsort2.c lqsort3.c lqsort4.c
TEST_SRCS = test1.c test2.c
LIB_SRCS = elem.c list.c
HDRS = elem.h list.h
SRCS = $(SORT_SRCS) $(TEST_SRCS) $(LIB_SRCS)
OBJS = $(subst .c,.o,$(SRCS))
TEST1_EXES = $(subst .c,_test1,$(SORT_SRCS))
TEST2_EXES = $(subst .c,_test2,$(SORT_SRCS))
EXES = $(TEST1_EXES) $(TEST2_EXES)

CC = gcc
OPTFLAGS = -O3
#OPTFLAGS =
CPPFLAGS =
DBGFLAGS =
#DBGFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -std=c99 -pedantic -Wall -Werror $(OPTFLAGS) $(DBGFLAGS)
LDFLAGS =
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

%_test1: test1.o elem.o list.o %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%_test2: test2.o elem.o list.o %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: all clean

all: $(EXES)

lmsort1.o: lmsort1.c $(HDRS)

lmsort2.o: lmsort2.c $(HDRS)

lmsort3.o: lmsort3.c $(HDRS)

lqsort1.o: lqsort1.c $(HDRS)

lqsort2.o: lqsort2.c $(HDRS)

lqsort3.o: lqsort3.c $(HDRS)

lqsort4.o: lqsort4.c $(HDRS)

elem.o: elem.c elem.h

list.o: list.c elem.h list.h

test1.o: test1.c $(HDRS)

test2.o: test1.c $(HDRS)

clean:
	$(RM) $(EXES)
	$(RM) $(OBJS)
	$(RM) *.gcno *.gcov *.gcda
	$(RM) a.out *~
