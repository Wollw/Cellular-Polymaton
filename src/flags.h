#ifndef FLAGS_T
#define	FLAGS_T
#include <stdbool.h>
/* Flags used to determine program state
 * should be declared here	*/
typedef volatile struct {
	bool update :1;
} flags_type;

extern flags_type flags;

#endif
