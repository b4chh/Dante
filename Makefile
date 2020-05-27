##
## EPITECH PROJECT, 2019
## mf
## File description:
## mf
##

GENE_DIR = generator
SOLVER_DIR = solver


all:	$(GENE_DIR) $(SOLVER_DIR)
	cd $(GENE_DIR) && $(MAKE)
	cd $(SOLVER_DIR) && $(MAKE)

clean:
	cd $(GENE_DIR) && $(MAKE) clean
	cd $(SOLVER_DIR) && $(MAKE) clean

fclean:	clean
	cd $(GENE_DIR) && $(MAKE) fclean
	cd $(SOLVER_DIR) && $(MAKE) fclean

re: clean fclean all

.PHONY: all clean fclean re
