ifneq ("$(PLATFORM)", "")
include makecfg.$(PLATFORM)
endif
IPATH     = -I./include/ -I./include/model/block
PROGRAM   = tetris
TARGET    = bin/$(PROGRAM)
CXXSRCS  += $(notdir $(wildcard *.cpp)) $(notdir $(wildcard src/*.cpp)) $(notdir $(wildcard src/model/*.cpp))\
			$(notdir $(wildcard src/view/*.cpp)) $(notdir $(wildcard src/controller/*.cpp))
CSRCS    += $(notdir $(wildcard src/view/qcs610/*.c))
OBJDIR    = ./obj
OBJS      = $(addprefix $(OBJDIR)/, $(CXXSRCS:.cpp=.o)) $(addprefix $(OBJDIR)/, $(CSRCS:.c=.o))
.PHONY: x86 qcs610
VPATH    += :src:src/view/:src/model:src/controller:

all:
	@echo "Platform is not specified"
x86 qcs610: setenv
	PLATFORM=$@ $(MAKE) -C . $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(IPATH) $(CXXFLAGS) $(DFLAGS) -c -o $@ $^
$(OBJDIR)/%.o: %.c
	$(CXX) $(IPATH) $(CXXFLAGS) $(DFLAGS) -c -o $@ $^
%.o: %.cpp
	$(CXX) $(IPATH) $(CXXFLAGS) $(DFLAGS) -c -o $@ $^
%.o: %.c
	$(CXX) $(IPATH) $(CXXFLAGS) $(DFLAGS) -c -o $@ $^
clean:
	rm -rf $(PROGRAM) obj bin
setenv:
	mkdir -p bin obj

