#ifndef _LINUX_UKALLSYMS_H
#define _LINUX_UKALLSYMS_H

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
