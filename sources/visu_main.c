#include "corewar_vm.h"

t_window    *init_window(void)
{
    t_window *window;
    WINDOW   *memory;
    WINDOW   *info1;
    WINDOW   *info2;
    WINDOW   *champions;

    memory = NULL;
    info1 = NULL;
    info2 = NULL;
    champions = NULL;
    window = malloc(sizeof(t_window));
    window->memory = memory;
    window->info1 = info1;
    window->info2 = info2;
    window->champions = champions;
    return (window);
}

void	color_player(t_vm *vm, size_t act_player, size_t size, size_t nb_player)
{
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	start = MEM_SIZE / nb_player;
	start = start * act_player;
	(void)size;
	while (j < 64)
    {
		i = 0;
		while (i < 64)
		{
			// if (i - start != size)
				// break;
			if (i >= start && size > 0)
			{
				getch();
				size--;
				mvwprintw(vm->window->memory, j, i * 3, "%c%02x", ' ', vm->arena[i + j * 64]);
			}
			i++;
		}
		wrefresh(vm->window->memory);
		j++;
    }
}

void	init_color_stuff(t_vm *vm)
{
	int i;

	i = 0;
	init_pair(0, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    while (i < vm->nb_player)
    {
		wattron(vm->window->memory, COLOR_PAIR(i));
		color_player(vm, i, vm->player[i].prog_size, vm->nb_player);
		wrefresh(vm->window->memory);
		i++;
    }
	wattrset(vm->window->memory, A_NORMAL);
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
        printf("ERROR, SCREEN TO SHORT, ZOOM OUT");
        return (-1);
    }
    y = ymax;
	x = 192;
    vm->window = init_window();
    vm->window->memory = newwin(y + 1, x + 1, 0, 0);
    vm->window->info1 = newwin(9, 75, 0, xmax - 75);
    vm->window->champions = newwin(50 - 12.5, 75, 9, xmax - 75);
    vm->window->info2 = newwin(11, 75, ymax - 11, xmax - 75);
    box(vm->window->info1, 0, 0);
    box(vm->window->info2, 0, 0);
    box(vm->window->champions, 0, 0);
    return(0);
}

void    refresh_window(t_vm *vm)
{
    wrefresh(vm->window->memory);
    wrefresh(vm->window->info1);
    wrefresh(vm->window->champions);
    wrefresh(vm->window->info2);
    refresh();
}

void	aff_memory(t_vm *vm)
{
	size_t i;
	size_t j;

	// init_color_stuff(vm);
	j = 0;
    while (j < 64)
    {
		i = 0;
		while (i < 64)
		{
			mvwprintw(vm->window->memory, j, i * 3, "%c%02x", ' ', vm->arena[i + j * 64]);
			i++;
		}
		j++;
    }
	wrefresh(vm->window->memory);
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
    	mvwprintw(vm->window->champions, j, 1, "Player %d :", i + 1);
    	j += 2;
    	mvwprintw(vm->window->champions, j, 1, "%s", vm->player[i].prog_name);
    	j += 4;
		i++;
	}
}

void    display_round(t_vm *vm)
{
	aff_memory(vm);
	aff_info(vm);
	aff_champions(vm);
	refresh_window(vm);
}

void	color_arena(t_vm *vm, t_cursor *cursor)
{
	refresh_window(vm);
	(void)cursor;
}