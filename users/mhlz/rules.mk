SRC += mhlz.c

ifeq ($(strip $(INCLUDE_DEFAULT_COMBOS)), yes)
	COMBO_ENABLE = yes
    OPT_DEFS += -DINCLUDE_DEFAULT_COMBOS
endif

