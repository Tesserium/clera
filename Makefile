CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17
LD=ld
LDFLAGS=-lc -lc++ -lstdc++ -lm -lncurses -lncurses_g -lncurses++ -lncurses++_g
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
