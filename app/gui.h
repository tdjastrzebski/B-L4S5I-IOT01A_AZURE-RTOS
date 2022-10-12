#ifndef _GUI_H
#define _GUI_H

#include "tx_api.h"

void gui_thread_entry(ULONG parameter);
void show_message(const char *message);
void dismiss_message(void);

#endif // _GUI_H