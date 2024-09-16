CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17
LD=ld
LDFLAGS=-lncursesw -lncurses
PROJNAME=clera
INSTALLDIR=/usr/local/bin

run: db
	./$(PROJNAME)
db:
	$(CXX) $(PROJNAME).cpp $(CXXFLAGS) $(LDFLAGS) -g3 -o $(PROJNAME)
install: rel
	cp $(PROJNAME) $(INSTALLDIR)
rel:
	$(CXX) $(PROJNAME).cpp $(CXXFLAGS) $(LDFLAGS) -O3 -o $(PROJNAME)
