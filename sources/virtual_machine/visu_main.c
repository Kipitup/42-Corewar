#include "corewar_vm.h"

t_window    *init_window(void)
{
    t_window *window;
    WINDOW   *memory;
    WINDOW   *info1;
    WINDOW   *info2;
    WINDOW   *champions;
    WINDOW   *input;

    memory = NULL;
    info1 = NULL;
    info2 = NULL;
    champions = NULL;
    input = NULL;
    window = malloc(sizeof(t_window));
    window->memory = memory;
    window->info1 = info1;
    window->info2 = info2;
    window->champions = champions;
    window->input = input;
    return (window);
}

void	color_player(t_vm *vm, size_t act_player, size_t size, size_t nb_player)
{
	int i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	start = MEM_SIZE / nb_player;
	start = start * (act_player -1);
	while (j < 64 && size > 0)
    {
		i = 0;
		while (i < 64 && size > 0)
		{
			if (i + j * 64 >= start && size > 0)
			{
				vm->arena_color[i + j * 64] = act_player;
				size--;
			}
			i++;
		}
		j++;
    }
}

void	pair_colors(t_vm *vm)
{
	int i;

	i = 1;
	init_pair(i, COLOR_GREEN, COLOR_BLACK);
	i++;
	if (i <= vm->nb_player)
	{
		init_pair(i, COLOR_BLUE, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
	{
		init_pair(i, COLOR_RED, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
		init_pair(i, COLOR_CYAN, COLOR_BLACK);
	i = 1;
	init_pair(i + vm->nb_player, LIGHT_GREEN, COLOR_BLACK);
	i++;
	if (i <= vm->nb_player)
	{
		init_pair(i + vm->nb_player, LIGHT_BLUE, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
	{
		init_pair(i + vm->nb_player, LIGHT_RED, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
		init_pair(i + vm->nb_player, LIGHT_CYAN, COLOR_BLACK);
}

void	init_color_arena(t_vm *vm)
{
	int i;

	i = 0;
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	pair_colors(vm);
	while (i < 4096)
	{
		vm->arena_color[i] = 0;
		i++;
	}
	i = 0;
    while (i < vm->nb_player)
    {
		color_player(vm, i + 1, vm->player[i].prog_size, vm->nb_player);
		i++;
    }
}

int    init_visu(t_vm *vm)
{
	size_t ymax;
	size_t xmax;
	size_t y;
	size_t x;

    initscr(); // start ncurses
	start_color();
    noecho();
    cbreak();
    getmaxyx(stdscr, ymax, xmax); // get screen size
    if (ymax < 64 || xmax < 250) // too short ?
    {
		endwin();
        ft_printf("ERROR, SCREEN TO SHORT, ZOOM OUT\n");
        exit(-1);
    }
    y = ymax;
	x = 192;
    vm->window = init_window();
    vm->window->memory = newwin(y + 1, x + 1, 0, 0);
    vm->window->info1 = newwin(9, 75, 0, xmax - 75);
    vm->window->champions = newwin(50 - 12.5, 75, 9, xmax - 75);
    vm->window->input = newwin(11, 75, ymax - 22, xmax - 75);
    vm->window->info2 = newwin(11, 75, ymax - 11, xmax - 75);
	init_color_arena(vm);
	display_round(vm);
	display_round(vm);
	mvwprintw(vm->window->input, 1, 1, "Pause \t\t[SPACE]");
	refresh_window(vm);
    return(0);
}

void    refresh_window(t_vm *vm)
{
    wrefresh(vm->window->memory);
    wrefresh(vm->window->info1);
    wrefresh(vm->window->champions);
    wrefresh(vm->window->info2);
    wrefresh(vm->window->input);
    refresh();
}

void	reset_light(t_vm *vm)
{
	size_t i;
	size_t j;

	j = 0;
    while (j < 64)
    {
		i = 0;
		while (i < 64)
		{
			if (vm->arena_color[i + j * 64] > vm->nb_player)
				vm->arena_color[i + j * 64] -= vm->nb_player;
			i++;
		}
		j++;
    }
}

void	aff_memory(t_vm *vm)
{
	size_t i;
	size_t j;

	j = 0;
    while (j < 64)
    {
		i = 0;
		while (i < 64)
		{
			wattron(vm->window->memory, COLOR_PAIR(vm->arena_color[i + j * 64]));
			mvwprintw(vm->window->memory, j, i * 3, "%c%02x", ' ', vm->arena[i + j * 64]);
			wattroff(vm->window->memory, COLOR_PAIR(vm->arena_color[i + j * 64]));
			i++;
		}
		j++;
    }
	wrefresh(vm->window->memory);
	reset_light(vm);
}

void	aff_input(t_vm *vm)
{
	size_t j;

	j = 1;
	mvwprintw(vm->window->input, j, 1, "Play \t\t[SPACE]");
    j += 2;
    mvwprintw(vm->window->input, j, 1, "Next Turn \t\t[c]");
    j += 2;
    mvwprintw(vm->window->input, j, 1, "Leave \t\t\t[q]");
}

void	aff_info(t_vm *vm)
{
	size_t j;

	j = 1;
	mvwprintw(vm->window->info1, j, 1, "Cycle: %d", vm->cycle_counter);
    j += 2;
    mvwprintw(vm->window->info1, j, 1, "Players: %d", vm->nb_player);
    j += 2;
    mvwprintw(vm->window->info1, j, 1, "Last alive: Player %d", -1 * vm->last_reported_alive);
    j = 1;
    mvwprintw(vm->window->info2, j, 1, "Cycle to die: %d", vm->cycle_to_die);
    j += 2;
    mvwprintw(vm->window->info2, j, 1, "Checks: %d", vm->check_counter);
    j += 2;
    mvwprintw(vm->window->info2, j, 1, "Lives", vm->check_counter);
}

void	aff_champions(t_vm *vm)
{
	int i;
	size_t j;
	
	
	i = 0;
	j = 1;
	while (i < vm->nb_player)
	{
		wattron(vm->window->champions, COLOR_PAIR(i + 1 + vm->nb_player));
    	mvwprintw(vm->window->champions, j, 1, "Player %d :", i + 1);
    	j += 2;
    	mvwprintw(vm->window->champions, j, 1, "%s", vm->player[i].prog_name);
    	j += 4;
		wattroff(vm->window->champions, COLOR_PAIR(i + 1 + vm->nb_player));
		i++;
	}
}

void    display_round(t_vm *vm)
{
	aff_memory(vm);
	aff_info(vm);
	aff_champions(vm);
	aff_input(vm);
	refresh_window(vm);
}

void	print_tab(unsigned char *arena_color)
{
	size_t i;
	size_t j;

	j = 0;
    while (j < 64)
    {
		i = 0;
		while (i < 64)
		{
			ft_printf("%d", arena_color[i + j * 64]);
			i++;
		}
		ft_printf("\n");
		j++;
    }
}

void	color_arena(t_vm *vm, t_cursor *cursor, unsigned long long pos)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		vm->arena_color[(pos % MEM_SIZE) + i] = cursor->player_id + vm->nb_player;
		i++;
	}
}

int		get_visu_input(t_vm *vm, int ch)
{
	if (ch == 'c')
	{
		ch = getch();
		if (ch != 'q')
			return (ch);
	}
	if (ch == 'q')
	{
		system("clear");
		exit(0);
	}
	nodelay(vm->window->memory, 1);
	if (ch != 'c')
		ch = wgetch(vm->window->memory);
	if (ch == ' ')
	{
		mvwprintw(vm->window->input, 1, 1, "Pause \t\t[SPACE]");
		refresh_window(vm);
		ch = wgetch(vm->window->memory);
		while (ch != ' ' && ch != 'c' && ch != 'q')
			ch = wgetch(vm->window->memory);
	}
	return (ch);
}
