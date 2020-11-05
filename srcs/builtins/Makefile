CD_DIR		= ./cd/
ECHO_DIR	= ./echo/
ENV_DIR		= ./env/
EXPORT_DIR	= ./export/
PWD_DIR		= ./pwd/
UNSET_DIR	= ./unset/

all:
	make -C $(CD_DIR)
	make -C $(ECHO_DIR)
	make -C $(ENV_DIR)
	make -C $(EXPORT_DIR)
	make -C $(PWD_DIR)
	make -C $(UNSET_DIR)

clean:
	$(MAKE) clean -C $(ECHO_DIR)
	$(MAKE) clean -C $(CD_DIR)
	$(MAKE) clean -C $(ENV_DIR)
	$(MAKE) clean -C $(EXPORT_DIR)
	$(MAKE) clean -C $(PWD_DIR)
	$(MAKE) clean -C $(UNSET_DIR)

fclean:
	$(MAKE) fclean -C $(ECHO_DIR)
	$(MAKE) fclean -C $(CD_DIR)
	$(MAKE) fclean -C $(ENV_DIR)
	$(MAKE) fclean -C $(EXPORT_DIR)
	$(MAKE) fclean -C $(PWD_DIR)
	$(MAKE) fclean -C $(UNSET_DIR)

re:fclean all

.PHONY:all clean fclean re