ARCH := $(shell uname -m)

DIR_APPS       := apps
DIR_SRC        := src
DIR_BUILD      := build/$(ARCH)
DIR_BIN        := build/bin
DIR_INC        := ./include
DIR_INCS       := -I../common/include -I$(DIR_INC)

DIR_LIB.x86_64 := ../common/libs/intel64

APP1           := $(DIR_BIN)/test1
APP1OBJ        := $(DIR_APPS)/test1.o


APPS           := $(APP1)

ifndef CC
    CC := gcc
endif
ifndef CXX
    CXX := g++
endif

CXXFLAGS       := -std=c++11 -c -O2 $(DIR_INCS)
CXXFLAGS       := -std=c++11 -c $(DIR_INCS) -g
CXXOBJ         := $(patsubst $(DIR_SRC)/%.cpp,$(DIR_BUILD)/%.o,$(wildcard $(DIR_SRC)/*.cpp))


LIBS           := -L$(DIR_LIB.$(ARCH)) -lecbufr -lsqlite3
#LIBS           += ../common/build/common.a -lpthread

#ifneq ($(ARCH),quark)
#    LIBS += -lGL -lX11
#endif

# TARGETS
#all: start common $(APP)
all: start $(APP1)

#	$(CXX) -o $(APP) $< $(LIBS)
$(APP1): $(CXXOBJ) $(APP1OBJ)
	$(CXX) -o $(APP1) $(APP1OBJ) $(CXXOBJ) $(LIBS)

$(CXXOBJ): $(DIR_BUILD)/%.o : $(DIR_SRC)/%.cpp
	echo $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

.SUFFIXES: .cpp .o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

common:
	make -C ../common ARCH=$(ARCH)
start:
	mkdir -p $(DIR_BUILD)
	mkdir -p $(DIR_BIN)
clean:
	rm -rf $(DIR_BUILD)/*.o
	rm -f $(DIR_APPS)/*.o
	rm -f $(APPS)
