#ifndef _LINUX_UKALLSYMS_H
#define _LINUX_UKALLSYMS_H

#include <errno.h>
#include <uk/plat/common/sections.h>

#define KSYM_NAME_LEN 128
#define KSYM_SYMBOL_LEN (sizeof("%s+%#lx/%#lx [%s]") + (KSYM_NAME_LEN - 1) + \
			 2*(64*3/10)  + 1)

static inline int is_ksym_addr(unsigned long addr)
{
	if (addr >= (unsigned long)__TEXT && addr <= (unsigned long)__END)
		return 1;
	return 0;
}

#ifdef CONFIG_DEBUG_BACK_TRACE

/* Look up a kernel symbol and return it in a text buffer. */
extern int sprint_symbol(char *buffer, unsigned long address);
extern void uk_dump_backtrace(void);

#else /* !CONFIG_DEBUG_BACK_TRACE */
static inline int sprint_symbol(char *buffer, unsigned long addr)
{
	*buffer = '\0';
	return 0;
}

void uk_dump_backtrace(void)
{
}
#endif /*CONFIG_DEBUG_BACK_TRACE */

#endif /*_LINUX_UKALLSYMS_H*/
