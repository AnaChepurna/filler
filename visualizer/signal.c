#include "visualizer.h"

static void		signal_stop_handler(int signo)
{
	if (signo == SIGTSTP)
	{
		manage_term(RE_SET);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
}

static void		signal_continue_handler(int signo)
{
	if (signo == SIGCONT)
	{
		manage_term(SET);
		start_signal_handling();
	}
}

static void		signal_interrupt_handler(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT || signo == SIGTERM)
	{
		manage_term(RE_SET);
		exit(2);
	}
}

void			start_signal_handling(void)
{
	signal(SIGCONT, signal_continue_handler);
	signal(SIGTSTP, signal_stop_handler);
	signal(SIGINT, signal_interrupt_handler);
	signal(SIGTERM, signal_interrupt_handler);
	signal(SIGQUIT, signal_interrupt_handler);
}