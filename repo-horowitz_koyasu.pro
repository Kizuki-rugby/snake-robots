TEMPLATE = subdirs

SUBDIRS += \
    AsGui \
    TinyGame \
    engines \
    info_bank \
    ncurses_example \
    test_info \
    test_ncurses_forms \
    tools \
    tui \
    unit-test

LIBS+=-lncurses
