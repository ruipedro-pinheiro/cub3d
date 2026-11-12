NAME = cub3d
SRCDIR = src
OBJDIR = .obj
INCDIR = inc
MINILIB_DIR = $(INCDIR)/minilibx
MINILIB = $(MINILIB_DIR)/libmlx.a
LIBFT_DIR = $(INCDIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFT_DIR) -g3 -O0 -Wshadow -Wstrict-prototypes -Wpointer-arith
ASAN_FLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer
SRC = main.c \
	  parse_prep.c \
	  parsing/validation.c \
	  parsing/config/headers.c \
	  parsing/config/headers_values.c \
	  win.c \
	  render_canvas.c \
	  utils.c \
	  draw.c \
      mini_map.c \
      player.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

################################################################################
#                                PROGRESS BAR                                  #
################################################################################
CNT = ._cnt
RESET := $(shell echo 0 > $(CNT))
C = \033[1;36m
Y = \033[1;33m
R = \033[1;31m
G = \033[1;32m
B = \033[1m
X = \033[0m

define progress
n=$$(($$(cat $(CNT)) + 1)); echo $$n > $(CNT); \
t=$(1); pct=$$((n * 100 / t)); f=$$((n * 20 / t)); \
bar=""; i=0; \
while [ $$i -lt $$f ]; do bar="$${bar}█"; i=$$((i+1)); done; \
while [ $$i -lt 20 ]; do bar="$${bar}░"; i=$$((i+1)); done; \
printf "\r\033[K $(C)🔧 [$(NAME)] $(Y)$$bar $(B)$$pct%%$(X)"
endef

################################################################################
#                                   RULES                                      #
################################################################################

all: $(NAME)
	@if [ $$(cat $(CNT)) -gt 0 ]; then printf "\n"; fi
	@printf " $(C)✅ [$(NAME)] $(B)Build complete$(X)\n"

$(NAME): $(OBJ) $(LIBFT) $(MINILIB)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR)  $(OBJ) $(LIBFT) -L$(MINILIB_DIR) $(MINILIB) -lmlx -lXext -lX11 -lm -o $(NAME)

$(MINILIB):
	@printf "$(Y) 📚 [MiniLibX] building... $(RESET)"
	@$(MAKE) -C $(MINILIB_DIR) --silent 2>/dev/null

$(LIBFT):
	@$(MAKE) --silent -C $(LIBFT_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call progress,$(words $(SRC)))

clean:
	@printf "$(R) 🗑️ [$(NAME)] Cleaned$(X)\n"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(MINILIB_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --silent -C $(LIBFT_DIR) fclean
	@rm -f /tmp/debug.log minishell .minishell_history .mini_cnt

re: fclean all

asan:  CFLAGS += $(VAL_FLAGS) $(ASAN_FLAGS)
asan:  re

run: re
	./$(NAME)

norm:
	@norminette src inc/*.h inc/libft | grep "Error" || echo "${G}No errors found :3${X}"

.PHONY: all clean fclean re debug asan
