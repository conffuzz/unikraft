#include <uk/plat/common/common.lds.h>

SECTIONS
{

	/* . = 0x100000; */
        _text = ALIGN(__PAGE_SIZE);//.;
        .text :
        {
                *(.text)
                *(.text.*)
        }
        _etext = .;
        /* Code */

	EXCEPTION_SECTIONS


	CTORTAB_SECTION

	INITTAB_SECTION

	EVENTTAB_SECTION
	.dynamic : { *(.dynamic) } :data :dynamic

}
INSERT BEFORE .rodata

SECTIONS
{
	TLS_SECTIONS
}
INSERT BEFORE .data
