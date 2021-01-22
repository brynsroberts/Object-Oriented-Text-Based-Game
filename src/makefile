###
### Project: finalProject
### Program name: makefile
### Author: Bryan Roberts 
### Date: 4/27/19
### Description: 
### concepts adapted from @author - Harlan James <waldroha@oregonstate.edu>
### concepts adapted from make example file from lecture

CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#Project Name
PROJ = main

# compile exectuable 
$(PROJ): main.o bulbasaur.o character.o pokemon.o space.o squirtle.o validation.o charmander.o ponyta.o bellsprout.o towncenter.o hospital.o catch.o gym.o boss.o game.o store.o
	$(CXX) main.o bulbasaur.o character.o pokemon.o space.o squirtle.o validation.o charmander.o ponyta.o bellsprout.o towncenter.o hospital.o catch.o gym.o boss.o game.o store.o -o $(PROJ)

# finalProject object file
finalProject.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# bulbasaur  object file
bulbasaur.o: bulbasaur.cpp bulbasaur.hpp	
	$(CXX) $(CXXFLAGS) -c bulbasaur.cpp

# character  object file
character.o: character.cpp character.hpp	
	$(CXX) $(CXXFLAGS) -c character.cpp

# pokemon  object file
pokemon.o: pokemon.cpp pokemon.hpp	
	$(CXX) $(CXXFLAGS) -c pokemon.cpp

# space  object file
space.o: space.cpp space.hpp	
	$(CXX) $(CXXFLAGS) -c space.cpp

# squirtle  object file
squirtle.o: squirtle.cpp squirtle.hpp	
	$(CXX) $(CXXFLAGS) -c squirtle.cpp

# charmander  object file
charmander.o: charmander.cpp charmander.hpp	
	$(CXX) $(CXXFLAGS) -c charmander.cpp

# validation  object file
validation.o: validation.cpp validation.hpp	
	$(CXX) $(CXXFLAGS) -c validation.cpp

# ponyta  object file
ponyta.o: ponyta.cpp ponyta.hpp	
	$(CXX) $(CXXFLAGS) -c ponyta.cpp

# bellsprout  object file
bellsprout.o: bellsprout.cpp bellsprout.hpp	
	$(CXX) $(CXXFLAGS) -c bellsprout.cpp

# town center  object file
towncenter.o: towncenter.cpp towncenter.hpp	
	$(CXX) $(CXXFLAGS) -c towncenter.cpp

# hospital  object file
hospital.o: hospital.cpp hospital.hpp	
	$(CXX) $(CXXFLAGS) -c hospital.cpp

# store  object file
store.o: store.cpp store.hpp	
	$(CXX) $(CXXFLAGS) -c store.cpp

# catch  object file
catch.o: catch.cpp catch.hpp	
	$(CXX) $(CXXFLAGS) -c catch.cpp

# gym  object file
gym.o: gym.cpp gym.hpp	
	$(CXX) $(CXXFLAGS) -c gym.cpp

# boss  object file
boss.o: boss.cpp boss.hpp	
	$(CXX) $(CXXFLAGS) -c boss.cpp

# game  object file
game.o: game.cpp game.hpp	
	$(CXX) $(CXXFLAGS) -c game.cpp

# remove all object files and executable file
clean:
	rm *.o $(PROJ)

