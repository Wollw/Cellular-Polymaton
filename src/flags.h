#ifndef FLAGS_T
#define	FLAGS_T
#include <stdbool.h>
/* Flags used to determine program state
 * should be declared here	*/
typedef volatile struct {
	bool update :1;
} flags_t;

extern flags_t flags;

#endif
