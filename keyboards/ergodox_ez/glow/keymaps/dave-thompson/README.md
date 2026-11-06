# ErgoDox EZ Glow

Board-specific glue for the shared 32-key keymap in [dave-thompson.c](../../../../../dave-thompson.c).

- `layout.h` maps `LAYOUT_32` onto `LAYOUT_ergodox`
- `keymap.c` adds the ErgoDox-only code (LED layer colours, Chordal Hold handedness)
- `config.h` and `rules.mk` include the shared settings, then add ZSA and RGB settings
- `keymap.json` imports the community modules used by the 32-key keymap
