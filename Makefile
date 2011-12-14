SORT_SRCS = lmsort1.c lmsort2.c lmsort3.c \
	    lqsort1.c lqsort2.c lqsort3.c lqsort4.c
TEST_SRCS = test1.c test2.c
LIB_SRCS = elem.c list.c
HDRS = elem.h list.h
SRCS = $(SORT_SRCS) $(TEST_SRCS) $(LIB_SRCS)
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)
LIBS = $(LIB_SRCS:%.c=%.o)
TEST1_EXES = $(subst .c,_test1,$(SORT_SRCS))
TEST2_EXES = $(subst .c,_test2,$(SORT_SRCS))
EXES = $(TEST1_EXES) $(TEST2_EXES)

CC = gcc
CPPFLAGS =
OPTFLAGS = -O3
DEBUGFLAGS =
#DEBUGFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -std=c99 -pedantic -Wall -Werror -MMD $(OPTFLAGS) $(DEBUGFLAGS)
LDFLAGS =

.PHONY: all clean

all: $(EXES)

%_test1: test1.o $(LIBS) %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%_test2: test2.o $(LIBS) %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

-include $(DEPS)

clean:
	$(RM) $(EXES) $(OBJS) $(DEPS)
	$(RM) *.gcno *.gcov *.gcda
	$(RM) -r *.dSYM
	$(RM) a.out *~
