CXX := clang++
INCLUDES := -Isrc -Ivendor -Ivendor/VultrCore/src -Ivendor/VultrCore/vendor
CXXFLAGS := -g -DDEBUG -std=c++20 -fPIC -Wno-reorder -Wno-deprecated-enum-enum-conversion -Wno-nullability-completeness -Wno-deprecated-volatile
# Intentionally not evaluated, do NOT convert = to :=
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP)/$*.d

TARGET := Gameplay

BUILD ?= build
DEP ?= .deps

SRCS := src/sources.cpp
OBJS := $(addprefix $(BUILD)/,$(SRCS:%.cpp=%.o))
DEPS := $(addprefix $(DEP)/,$(SRCS:%.cpp=%.o))

LDFLAGS := -Lvendor/VultrCore/build/ -lvultr


$(BUILD)/%.o: %.cpp | $(BUILD) $(DEP)
	mkdir -p $(@D)
	mkdir -p $(DEP)/$(dir $<)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f $(OBJS) $(DEPS) $(BUILD)/lib$(TARGET).so

$(TARGET): $(OBJS)
	$(CXX) -o $(BUILD)/lib$@.so $^ -shared $(LDFLAGS)

$(BUILD) $(DEP):
	@mkdir -p $@

$(DEPS):

include $(wildcard $(DEPS))
