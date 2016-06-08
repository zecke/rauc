#pragma once

#include <glib.h>

#include "config_file.h"

typedef struct {
	/* a busy context must not be reconfigured */
	gboolean busy;
	gboolean pending;

	/* system configuration data */
	gchar *configpath;
	RaucConfig *config;

	/* signing data */
	gchar *certpath;
	gchar *keypath;
	/* optional global mount prefix overwrite */
	gchar *mountprefix;

	/* optional custom handler extra arguments */
	gchar *handlerextra;

	/* is there already a manifest we should start with */
	gchar *manifestpath;

	/* prevent EEPROM change */
	gboolean inhibit_change_bootable;
} RaucContext;

gboolean r_context_get_busy(void);
void r_context_set_busy(gboolean busy);

RaucContext *r_context_conf(void);
const RaucContext *r_context(void);
