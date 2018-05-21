#include "visualizer.h"

int main(void)
{
	char b;
	manage_term(INIT);
	manage_term(SET);
	start_signal_handling();
	while (get_map())
	{
		usleep(50000);
		//sleep(1);
	}
	sleep(10);
	read(0, &b, 1);
	ft_putchar_fd('!', 2);
	ft_putnbr_fd(b, 2);
	sleep(10);
	manage_term(RE_SET);
	return 0;
}