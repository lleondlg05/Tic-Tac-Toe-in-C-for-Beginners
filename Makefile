.PHONY: clean All

All:
	@echo "----------Building project:[ Tic-Tac-Toe - Debug ]----------"
	@cd "Tic-Tac-Toe" && "$(MAKE)" -f  "Tic-Tac-Toe.mk"
clean:
	@echo "----------Cleaning project:[ Tic-Tac-Toe - Debug ]----------"
	@cd "Tic-Tac-Toe" && "$(MAKE)" -f  "Tic-Tac-Toe.mk" clean
