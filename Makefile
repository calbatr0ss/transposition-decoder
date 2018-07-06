CC = g++
CFLAGS = -g -Wall -std=c++11

EXEC = decode
SRC = main.cpp decoder.cpp transpoTree.cpp transpoNode.cpp
OBJDIR = build
$(shell mkdir -p $(OBJDIR) >/dev/null)
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

$(OBJDIR)/%.o: %.cpp
	@echo "Creating object $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	@echo "Creating executable $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	@echo "Deleting objects..."
	rm -rf $(OBJS)
	@echo "Deleting executable..."
	rm -rf $(EXEC)