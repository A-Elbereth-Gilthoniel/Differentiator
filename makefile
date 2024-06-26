TARGET = program


PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_FILE = ./files/
DELF = .\obj\


SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))


$(TARGET) : $(OBJ)
		g++ $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
		g++ -c $< -o $@


.PHONY : clean
clean :
	del $(DELF) $(TARGET).exe -rf


draw:
	dot $(PREF_FILE)Tree_Graph.dot -T png > $(PREF_FILE)Tree_graph.png
	dot $(PREF_FILE)Tree_Graph.dot -T svg > $(PREF_FILE)Tree_graph.svg
	dot $(PREF_FILE)Tree_Graph2.dot -T png > $(PREF_FILE)Tree_graph2.png
	dot $(PREF_FILE)Tree_Graph2.dot -T svg > $(PREF_FILE)Tree_graph2.svg
	dot $(PREF_FILE)Tree_Graph3.dot -T png > $(PREF_FILE)Tree_graph3.png
	dot $(PREF_FILE)Tree_Graph3.dot -T svg > $(PREF_FILE)Tree_graph3.svg

pdf:
	pdflatex $(PREF_FILE)differentiator.tex
