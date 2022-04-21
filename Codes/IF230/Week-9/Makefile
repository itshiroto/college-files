CC	:= gcc
WCC := x86_64-w64-mingw32-gcc
WIN-BIN := ./win-bin
NIX-BIN := ./linux-bin
SRCS = $(wildcard *.c)
NIX-PROGS = $(patsubst %.c,$(NIX-BIN)/%,$(SRCS))
WIN-PROGS = $(patsubst %.c,$(WIN-BIN)/%.exe,$(SRCS))

.PHONY: all windows linux

all: $(NIX-PROGS) $(WIN-PROGS)
windows: $(WIN-PROGS)
linux: $(NIX-PROGS) 

%: %.c
	$(CC) $(CFLAGS) $< -o $@

$(WIN-BIN)/%.exe: %.c
	$(WCC) $< -o $@

$(NIX-BIN)/%: %.c
	$(CC) $(CFLAGS) $< -o $@
