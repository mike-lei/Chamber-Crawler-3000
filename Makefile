CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Werror=vla -MMD

OBJECTS = main.o TextDisplay.o drow.o goblin.o vampire.o troll.o shade.o player.o Dwarf.o Elf.o Orc.o Human.o Halfling.o Merchant.o Dragon.o enemy.o Character.o MakeCharacter.o BA.o BD.o PH.o Potion.o RH.o WA.o WD.o DragonHoard.o MerchantHoard.o NormalHoard.o SmallHoard.o Treasure.o Item.o MakeItem.o door.o dotground.o empty.o Floortiles.o horizonWall.o MakeFloor.o passage.o stair.o verticalWall.o cell.o CellObject.o chamber.o ChamberVal.o floor.o MoveControl.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
