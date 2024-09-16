CXX=g++
CXXFLAGS=-Wall -Wextra -Iinclude -std=c++17
LD=ld
LDFLAGS=-lncursesw -lncursesw_g -Llib
PROJNAME=clera
INSTALLDIR=/usr/local/bin

run: db
	./$(PROJNAME)
db:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -g3 $(PROJNAME).cpp -o $(PROJNAME)
install: rel
	cp $(PROJNAME) $(INSTALLDIR)
rel:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -O3 $(PROJNAME).cpp -o $(PROJNAME)
