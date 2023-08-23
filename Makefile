PREFIX = $(HOME)/.local

CXX = g++  # Use the appropriate C++ compiler here

all: nf-profile

nf-profile: neofetchprofile.cpp
	$(CXX) neofetchprofile.cpp -o nf-profile

install: nf-profile
	mkdir -p $(PREFIX)/bin
	install nf-profile $(PREFIX)/bin/nf-profile
	@rm -rf ./nf-profile

.PHONY: all install
