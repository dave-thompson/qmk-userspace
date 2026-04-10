# keyboard.svg — How to Read This Diagram

This document explains the structure and conventions of `keyboard.svg` for the benefit of anyone (human or AI) comparing the diagram to the QMK source code.

---

## Overview

The diagram documents a 32-key Ergodox EZ layout across **three layers**, stacked vertically:

1. **BASE** — Graphite alpha layout with home-row mods (HRMs)
2. **NUMBERS** — Symbols and numbers, also with HRMs on the number row
3. **NAVIGATION** — Navigation, window management, editing shortcuts; no HRMs

Each layer section has two parts: the **keymap** (the physical keys) and a **combo group** below it (for BASE and NAV only; NUMBERS has no combos).

---

## Reading the Keymap

### Key layout
Each layer shows three rows of ten keys (left half: columns 1–5, right half: columns 6–10), plus thumb keys at the bottom of the left and right halves. The two halves are visually separated by a gap in the middle of each row.

### Key labels
- A key showing a **single character** (e.g. `B`, `/`, `↑`) sends that character when tapped.
- A key showing **two characters separated by a space** (e.g. `' "` or `. !`) sends the first character when tapped and the second when shifted.
- A key showing a **word or abbreviation** (e.g. `close`, `paste`, `alfred`) triggers a named action or macro.

### Home-row mods (HRMs)
Keys with a **blue background** (`#dbeafe` fill, `#93c5fd` stroke) are HRM keys. They show the alpha letter large, with the modifier name small below it (`ctrl`, `cmd`, `opt`, `shift`). The modifier fires on hold; the letter fires on tap.

In BASE, HRMs are on row 2: **N R T S** (left, ctrl/cmd/opt/shift) and **H A E I** (right, shift/opt/cmd/ctrl).

In NUMBERS, HRMs are on the number row: **1 2 3 4** (left) and **7 8 9 0** (right), same modifier order.

### Thumb keys (BASE only)
The two thumb keys sit below row 3, inset toward the centre:
- Left thumb: **nav** — holds the NAV layer (purple background)
- Right thumb: **num** (with space-bar symbol) — holds the NUMBERS layer (purple background)

### Navigation layer keys
Coloured backgrounds indicate action categories:
- **Pink** (`#fce7f3`) — window/app management (close, min)
- **Red** (`#fee2e2`) — undo/redo/save
- **Green** (`#dcfce7`) — clipboard (cut, copy, paste)
- **Yellow** (`#fef9c3`) — text formatting (bold, italic, underline)
- **Orange** (`#ffedd5`) — selection with arrow (◀ sel, sel ▶, ▼ sel)
- **Indigo** (`#e0e7ff`) — arrow keys (◀ ▼ ▶ ▲)
- **Teal** (`#ccfbf1`) — app-switcher / launcher (expose, alfred, switch)
- **White** (`#ffffff`) — utility / modifier-style keys (esc, lock, ctrl, tab, backspace, return)

---

## Reading the Combo Groups

Below the BASE and NAV keymaps is a **combo group**: a grid of small rounded-rectangle keys representing physical key combinations. Each combo is triggered by pressing two or three keys simultaneously.

### Grid layout
Combo keys are arranged in three rows, each row corresponding to the matching physical row of the keymap above. The x-positions of combo keys align with the x-positions of the keymap columns, so you can read which physical keys are involved by looking at which columns the combo keys occupy.

The 10 possible column x-positions are (left edge of each combo key):
`31, 92, 153, 214, 275` (left half) and `363, 424, 485, 546, 607` (right half).

### Colour shading (which keys are involved)
Each combo key in the grid may have a **coloured stripe** on its left or right edge. These stripes are the visual cue for which key(s) are pressed:
- A stripe on the **right edge** of a key means that key is the **left** member of the pair.
- A stripe on the **left edge** of a key means that key is the **right** member of the pair.
- A 2-key combo therefore shows one stripe on the right of the left key, and one stripe on the left of the right key — both the same colour.
- An unshaded key position within a combo group means that position is not used by any combo.

The stripe colour identifies the combo's **output category** (matches the colour coding of the corresponding NAV keys where applicable):
- **Pink** (`#fce7f3`) — punctuation / symbol combos
- **Teal** (`#ccfbf1`) — bracket/parenthesis combos
- **Green** (`#dcfce7`) — editing action combos (NAV layer)
- **Purple** (`#ede9fe`) — window/tiling combos (NAV layer)

### The combo label
The output of each combo is shown as a label **centred between the two (or three) involved keys**:
- Single-character outputs use a larger font (`cl-m` class, 12px).
- Multi-character or two-line outputs use a smaller font (`cl-s` class, 9px), sometimes with two `<tspan>` lines.

### The brace annotation
Some combos also have a **bracket/brace** drawn below the combo row, spanning the involved keys, with a grey label underneath. This indicates a **three-key combo** (all three keys in the span must be pressed simultaneously). The label names the action.

**Example:** In the BASE combo row 1, the keys at columns L, D, W have a brace below them labelled `num word` — pressing L+D+W together activates the Num Word feature.

---

## Specific Combos

### BASE layer combos (3 rows, left/right halves mirror each other)

**Row 1** (corresponding to physical row 1: B L D W Z / ' F O U J):
| Keys | Output | Notes |
|---|---|---|
| W + Z | `` ` `` | backtick |
| ' + F | `~` | tilde |
| L + D + W | `num word` | 3-key brace |
| F + O + U | `caps word` | 3-key brace |

**Row 2** (physical row 2: N R T S G / Y H A E I):
| Keys | Output |
|---|---|
| S + G | `_` |
| Y + H | `@` |
| R + T + S | `del word` — 3-key brace |
| H + A + E | `enter` — 3-key brace |

**Row 3** (physical row 3: Q X M C V / K P , . :;):
| Keys | Output | Colour |
|---|---|---|
| X + M | `(` | teal |
| M + C | `—` (em dash) | pink |
| P + , | `&` | pink |
| , + . | `)` | teal |

### NAV layer combos (3 rows)

**Row 1** (physical NAV row 1: esc ⌫ close min italic / expose ◀sel ▲ sel▶ lock):
| Keys | Output | Colour |
|---|---|---|
| ⌫ + close | `quit` | pink |
| close + min | `new` | pink |
| min + italic | `del file` | purple |
| ◀sel + ▲ | `prev tab` | teal |
| ▲ + sel▶ | `next tab` | teal |
| ⌫ + close + min | `tile left` — 3-key brace | — |

**Row 2** (physical NAV row 2: ctrl cut copy paste bold / tab ◀ ▼ ▶ ⌫):
| Keys | Output | Colour |
|---|---|---|
| cut + copy | `all` | green |
| copy + paste | `pst text` | green |
| paste + bold | `scr shot` | purple |
| cut + copy + paste | `fullscreen` — 3-key brace | — |

**Row 3** (physical NAV row 3: undo redo save ↩ under / — alfred ▼sel switch —):
| Keys | Output | Colour |
|---|---|---|
| redo + save | `zoom −` | purple |
| save + ↩ | `zoom +` | purple |
| alfred + ▼sel | `prev win` | teal |
| ▼sel + switch | `next win` | teal |
| undo + redo + save | `tile right` — 3-key brace | — |

---

## CSS Classes Quick Reference

| Class | Usage |
|---|---|
| `.kl` | Normal key label (13px, dark) |
| `.klm` | HRM main label (13px, blue) |
| `.kls` | HRM modifier sub-label (9px, blue) |
| `.klp` | Thumb key main label (11px, purple) |
| `.klps` | Thumb key sub-label (9px, purple) |
| `.kln` | Navigation layer key label (11px) |
| `.ico` | Icon/symbol key (24px, grey, light weight) |
| `.sec` | Section title (BASE / NUMBERS / NAVIGATION) |
| `.combo-key` | Combo key box (white fill, grey stroke) |
| `.cl-m` | Base combo label, single char (12px) |
| `.cl-s` | Combo label, multi-char (9px) |
| `.cl-gr` | 3-key brace label (9px, grey, dimmed) |
| `.cb-gr` | Brace/bracket line strokes |
| `.t-*` | Text colour overrides (pnk, grn, red, tel, ora, ind, yel, gry) |
