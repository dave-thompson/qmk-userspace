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
Keys with a **muted yellow background** (`#feffe9` fill, standard `#cdcdcd` stroke) are HRM keys. They show the alpha letter large, with the modifier name small below it (`ctrl`, `cmd`, `opt`, `shift`). The modifier fires on hold; the letter fires on tap.

Both the letter (`#282828`) and the modifier name (`#727272`) are neutral. The letter is the same dark neutral as every other alpha because it is not a different key, and the modifier name is grey so that no *hue* is spent on the HRMs at all beyond the key tint itself.

**The HRM tint is deliberately far weaker than the standard key treatment.** At 16 keys it is the largest single
block of colour in the diagram, so a normal-strength yellow (`#feffda`, as used by the NAV formatting keys) made
the home rows the loudest thing on the page and drowned out both the thumb keys and the combo stripes.

It is not a bespoke value: it is the palette yellow on the **same blend-toward-white rule everything else uses**,
just taken much further. Stripes blend 45%, keys blend 50%, the HRM fill blends **70%** — `#fdffb6` → `#feffe9`.
So the HRM tint is no longer an exception to the fill rule, only an extreme setting of it. The one thing that
does remain an exception is the stroke, which stays the standard neutral `#cdcdcd` rather than a yellow one.

**The signal here is chroma, not lightness.** The fill sits a few thousandths in lightness below white —
effectively nothing — and separates from the white keys beside it on chroma alone, at 0.029. The usable range is
narrow, and the blend is squeezed from both sides:

| Blend | Fill | Chroma | vs NAV yellow | vs the thumb fill |
|---|---|---|---|---|
| 68% | `#feffe8` | 0.030 | ×1.60 | ×1.57 |
| **70%** | **`#feffe9`** | **0.029** | **×1.67** | **×1.50** |
| 72% | `#feffeb` | 0.026 | ×1.83 | ×1.37 |
| 75% | `#feffed` | 0.024 | ×2.04 | ×1.23 |
| 78% | `#ffffef` | 0.021 | ×2.29 | ×1.10 |

**This is a three-way bind with no clean answer.** The HRM has to stay far enough below NAV's formatting keys
(`#feffda`, C 0.048) that the two do not read as the same yellow, and high enough to hold its own against the
thumbs. Every step toward one is a step away from the other.

70% favours parity with the thumbs and accepts a little bleed with `bold`/`italic`/`under`. 75% is the reverse
and is kept as the alternative — see the variants note at the end. 72% splits the difference without resolving
either side.

**Why the HRM needs to sit above the thumbs at all**, when area-weighted the two are within 2%: teal reads about
1.28× hotter than yellow per unit chroma — the reciprocal of the 0.78 damp applied to teal throughout — and the
thumbs concentrate a third of their colour into a 1px border, where a fill diffuses it. Equal chroma is not equal
presence when the hues differ and the distribution differs.

**The durable fix is still to move NAV's formatting keys off yellow.** That note predates the thumbs and now
matters more, since the constraint has gained a second side. Freeing the yellow would let the HRM go wherever
the thumbs need it.

In BASE, HRMs are on row 2: **N R T S** (left, ctrl/cmd/opt/shift) and **H A E I** (right, shift/opt/cmd/ctrl).

In NUMBERS, HRMs are on the number row: **1 2 3 4** (left) and **7 8 9 0** (right), same modifier order.

### Thumb keys (BASE only)
The two thumb keys sit below row 3, inset toward the centre:
- Left thumb: **nav** — holds the NAV layer
- Right thumb: **num** (with space-bar symbol) — holds the NUMBERS layer

Both use **teal** — `#eafcfe` fill, `#95d0d6` stroke, `#005b62` labels. On BASE, teal means *layer
switching*: the thumbs and the `lyr` combo, and nothing else.

**The thumbs are the one key group not on the standard key treatment.** Their fill is far lighter than the rule
gives and their stroke is desaturated to match, because a full-strength teal key does not survive being isolated:

| | Fill | Stroke |
|---|---|---|
| NAV teal keys (in a row) | `#d5f8fc` C 0.037 | `#66d8e3` C 0.104 |
| **thumbs** (alone) | `#eafcfe` C 0.019 | `#95d0d6` C 0.061 |

Roughly half the chroma at both tiers, for the same total weight — 0.159 against the NAV keys' 0.159. The colour
is redistributed, not removed.

**Why the fill had to go first.** The fill is 54×46 = 2484 px against the stroke's ~196 px, so it carries about
thirteen times the colour. Teal is the hue that reads hotter than its chroma predicts (see ‡), and on two large
isolated keys that lands hardest — the original `#dbf9fc` fill read as garish, closer to signage than to the
rest of the diagram. Dropping the fill to white fixed that but left the keys hollow, `nav` worst of all since it
has no glyph to fill the space. The fill came back at a much lower chroma instead.

**The stroke is damped, not blended, and the distinction is load-bearing.** Blending toward white raises
lightness: softening the border that way took it to L 0.93, where every other border in the diagram sits between
0.78 and 0.88. The thumbs would have had a *paler* outline than a plain white key — backwards for the most
important keys on the layer. Damping holds lightness at teal's rule value of 0.820 and removes only chroma, so
the border stays exactly as well-defined as every other border and simply carries less colour.

**Blending changes weight; damping changes colour.** Both levers appear in this diagram and they are not
interchangeable — see the pink note under ¶ for a case where the opposite was true.

One number to watch if these are ever restyled: against a very light fill the original stroke sat at a
fill-to-stroke chroma ratio of 7.6, where the palette band is 2.85–3.35. That is what "the border feels heavy"
measures as, and no small adjustment fixes it. Both tiers were eventually raised together to restore colour
without disturbing the ratio, which now sits at **3.19**.

### The two colour treatments

Every coloured element in the diagram uses one of exactly two treatments, applied consistently across all three layers:

| Element | Fill | Stroke |
|---|---|---|
| **Keys** (54×46) | base tint lightened 50% toward white (see ¶) | same hue, mid-strength (see ‖) |
| **Combo stripes** (11×28) | base tint lightened 45% toward white (except green — see §) | none |

Each hue has one **base tint**, and the other tiers are derived from it. The base tints are seven of the
eight colours of [this colorkit palette](https://colorkit.co/palette/ffadad-ffd6a5-fdffb6-caffbf-9bf6ff-a0c4ff-bdb2ff-ffc6ff/):

| Hue | Meaning | Base tint | Stripe | Key fill | Stroke | Dark (labels) |
|---|---|---|---|---|---|---|
| Pink | punctuation (BASE) · window mgmt (NAV) | `#ffc6ff` | `#ffe0ff` | `#ffe7ff` ¶ | `#eea7ef` ‖ | `#703472` |
| Teal | layer switching (BASE) · app switching (NAV) | `#9bf6ff` | `#d1f8fc` ‡ | `#d5f8fc` ‡ · `#eafcfe` ✦ | `#66d8e3` ‡ · `#95d0d6` ✦ | `#005b62` |
| Blue | arrow keys · window / tiling combos | `#a0c4ff` | `#d6e5ff` ◆ | `#dbe9ff` ¶ | `#8db8ff` | `#254d90` |
| Green | clipboard / editing | `#caffbf` | `#d8f8d0` § | `#e4ffdf` | `#98e488` | `#245f17` |
| Red | undo / redo / save | `#ffadad` | — | `#ffdcdc` ¶ | `#ff9a9b` ‖ | `#852e34` |
| Orange | selection | `#ffd6a5` | — | `#ffead2` | `#efb05e` | `#6f4600` |
| Yellow | text formatting | `#fdffb6` | — | `#feffda` | `#dfdf6d` | `#545300` |
| Muted yellow | home-row mods only | (yellow @ 70%) | — | `#feffe9` | standard `#cdcdcd` | neutral `#727272` |

**✦ Teal has two key treatments.** The NAV app-switcher keys use the standard one; the BASE thumbs use a much
lighter fill and a damped stroke because they sit alone in open space. Same hue, same total weight, half the
chroma at both tiers — see [Thumb keys](#thumb-keys-base-only). They are the only key group in the diagram off
the standard treatment.

**Purple is not used.** The palette's eighth colour was retired when the NAV arrows and tiling combos moved to
blue. Purple is the only hue that is both the darkest and the most chromatic of the eight, and that is a gamut
fact rather than a quirk of the palette: at a pastel lightness of L=0.88 purple can hold only 0.063 chroma
against green's 0.270, so to be a recognisable purple at all it had to be pushed darker and more saturated than
everything around it. It was the one member that broke the family's pattern in order to exist, which is why it
read as not belonging. Blue sits in the same gamut-poor zone — worst of the eight at 0.059 — but wears it better
by staying lighter and less chromatic instead.

Retiring it costs one collision and buys another: blue now covers both the arrows (keys) and the tiling combos
(stripes), the same double duty purple had. The treatment split keeps them apart — nothing on NAV is both a key
and a stripe — and the layer reads less cluttered for having one fewer hue.

**The derivation.** Only the base tints are chosen; the rest follow, so a new hue needs one value rather than four:

| Tier | Rule |
|---|---|
| Stripe | base tint blended 45% toward white |
| Key fill | base tint blended 50% toward white (see ¶ for the four exceptions) |
| HRM fill | yellow base tint blended 75% toward white (HRM keys only) |
| Stroke | OKLCH(`L`−0.10 floored at 0.78, `C`+0.045, `h`) of the base tint (see ‖ for two departures) |
| Dark | OKLCH(0.43, 0.12 clamped to sRGB, `h`) of the base tint |

**The label ceiling is 0.12, and it is a ceiling rather than a target.** At L=0.43 most hues cannot reach high
chroma at all — the sRGB gamut runs out first, and by very different amounts: teal tops out at 0.073, orange and
yellow at about 0.092. An earlier target of 0.19 therefore produced by far the loosest tier in the system,
because it was met by only two hues and clamped for the rest. At 0.12 every hue except teal, orange and yellow
sits on the ceiling exactly, and those three are unchanged.

**Every dark is rule-derived** — all seven reproduce exactly from OKLCH(0.43, 0.12 clamped, `h` of the base
tint). It is the only tier with no exceptions at all.

Lightness is untouched at 0.43 for every label, so contrast against the fills is exactly as it was; only
saturation moved. Do not raise the ceiling to even the tier further: above 0.12 the gamut-limited hues stop
following and the spread widens again.

The stroke offsets were fitted against the nine hues of the pre-palette diagram (which had a separate indigo), where the tiers were Tailwind
‑100/‑300/‑800; they reproduce those old strokes to within a shade. Chroma sits a step above that baseline
because the palette itself is a step stronger than Tailwind ‑100.

**§ Green's stripe is darkened, not blended.** Stripes have no stroke, so all that separates one from the
white combo key beneath it is the fill. Green's base tint is the lightest of the five stripe hues, and on the
blend rule it sits only about 0.04 in OKLCH lightness below white — half what the other four manage, and visibly
faint at 11px. Un-blending does not fix it: even undiluted, green reaches only 0.05, because the tint is intrinsically
light rather than intrinsically pale. Its chroma was never the problem — on the rule it was already the *highest* of
the five.

So green's stripe is set by lightness instead: OKLCH(0.946, 0.063, 140.2) = `#d8f8d0`, which puts it at 0.054
below white, between teal's 0.047 and pink's 0.059. If you restyle the stripes, move green by its lightness
against white rather than by the blend percentage — the blend is close to a dead lever for this hue.

**Green has to be re-derived whenever the stripe blend changes**, since it does not follow the rule and so does
not move with the others. Scale its lightness-below-white and its chroma by the same factor the four
rule-following hues move; they track each other closely enough for the mean to be safe (30% → 40% was ×0.85,
40% → 45% ×0.92, in both cases agreeing within a percent across the four). Skipping this does not merely leave green stale — it inverts the
intent, because a weaker blend for the others would make green the *strongest* stripe rather than a mid one.

**‡ Teal is damped across all three tiers.** Its stripe, key fill and stroke each carry about 22% less chroma
than the rules give. The palette's teal is a pure cyan (h=204) where the pre-palette one was an aqua-green
(h=181), and cyan reads considerably hotter than its OKLCH chroma predicts — undamped, the three app-switcher
keys were the loudest thing on the page.

This is the one hue where the measurements actively mislead, so do not tune it from the tables. By lightness teal
ranks 6th of 8, and its stroke carries the *lowest* chroma of any hue — on every number in this document it looks
like one of the quietest hues, and it still reads as one of the more intense. Trust the eye over the figures
here, and if you add a hue anywhere in the 180–215 band expect the same discrepancy.

The damp was originally applied to the stroke alone, which left the fill and stripe deriving straight off the
undamped base tint — teal then read hot on the NAV keys even though its outline had been corrected. All three
tiers now carry it. If you re-derive teal, damp every tier or none; correcting one in isolation is what caused
the problem.

**One hue, one set of values.** A green key is `#e4ffdf` whether it is a BASE thumb or a NAV clipboard key; a green label is `#245f17` wherever it sits. An earlier revision let green drift into two fills and two darks by setting them in separate places — if you add an element, take its values from this row rather than copying a neighbouring hex.

**The one exception is muted yellow**, used only by the 16 HRM keys. It is a *fill-only* hue: it follows the blend rule but at 75% rather than the keys' 50%, and its stroke is the standard neutral rather than a yellow one. Both exist for the same reason — 16 keys is the largest block of colour in the diagram, so a full-strength treatment there outweighs everything else on the page.

The grey stroke also does the work of keeping muted yellow apart from real yellow. A desaturated yellow stroke reads as the same family as NAV's `#dfdf6d`, so the home rows and the formatting keys grouped together across the page even though their fills differ; removing hue from the border breaks that grouping. Treat this as its own row rather than as "yellow, lighter" — the two are not interchangeable, and the home rows stay findable on the tint and the `ctrl`/`opt`/`cmd`/`shift` sub-labels alone.

A useful consequence: **every key on BASE and NUMBER except the two thumbs uses the `#cdcdcd` border**, so on those layers the border is constant and only the fill carries meaning.

### Hue weight is not even

The palette colours differ a lot in how heavy they read, and the rules do not correct for it — the same blend
applied to a hue that starts dark leaves it comparatively dark. Measured as lightness distance from the ground,
fill plus stroke together, with the fill-to-stroke chroma ratio alongside:

| Hue | Base tint L | Key blend | Weight | Ratio |
|---|---|---|---|---|
| Blue (arrows) | 0.816 | 62% ¶ | **0.225** | 3.35 |
| Red | 0.827 | 57% ¶ | 0.220 | 3.11 |
| Orange | 0.899 | 50% | 0.186 | 3.15 |
| Pink (NAV keys) | 0.895 | 58% ¶ | 0.161 | 3.06 |
| Teal (BASE thumbs) ✦ | 0.919 | — | 0.159 | 3.19 |
| Teal (NAV keys) ‡ | 0.919 | 50% | 0.159 | 2.85 |
| Green | 0.948 | 50% | 0.125 | 2.85 |
| Yellow | 0.982 | 50% | **0.109** | 2.86 |

Teal is marked ‡ because this table understates it — see the damping note above; chroma damping barely moves
lightness, so its figures here are unchanged by the correction.

**¶ Four fills are off the 50% blend, sized by how exposed the keys are rather than by how heavy the hue is.**
Orange, teal, green and yellow are all left on a flat 50%.

| Hue | Blend | Why |
|---|---|---|
| Blue | 62% | The four arrow keys are the heaviest group on NAV. They sit among the orange selection keys and above the teal row, so they have neighbours, but the tint is dark enough to need a real step. |
| Pink (NAV keys) | 58% | `close`/`new` are lightness-matched to the teal keys beside them so the row reads level — fill L 0.954 against teal's 0.955, stroke L 0.819 against 0.820. |

The BASE thumbs are not in this table because they are not on a blend at all — see ✦. They are the case that
outgrew the correction: exposure was handled by lightening the fill for blue, purple and red, but two isolated
keys in a hot hue needed both tiers moved, which is a different treatment rather than a different number.
| Red | 57% | A trim, and a balance: see ‖. |

**‖ Two strokes are not rule-derived, and both departures pay for something specific.**

Red's stroke sits at L=0.791 rather than the rule's floored 0.780. On the rule it was too heavy at 0.233; pulled
back by lightening the fill instead, its fill-to-stroke ratio hit 3.89 — the highest in the palette — and the
border read markedly unlike the interior. Red loses chroma fast as it lightens, so a light red fill goes nearly
colourless while its stroke stays strong. Moving the stroke off the floor instead gives weight 0.220 and ratio
3.11, both in family.

That departure also avoids a collision. **The stroke rule floors lightness at 0.78, and only the hues whose base
tints are dark enough reach that floor** — here, blue at 0.779. A rule-derived red would land at 0.780 and the
two would agree to within 0.1%, reading as a matched pair for no reason. Red at 0.791 is clear of it.

Pink's stroke is off the rule for the lightness match described above.

**Note where the weight actually lives.** The stroke carries roughly three quarters of a key's combined weight,
so the fill blend is the weaker lever — moving a fill 15 points shifts the total by about 10%. The efficient move
is to trade between the tiers rather than change the total: lightening the fill and darkening the stroke buys
stroke chroma at almost no cost in weight, and the reverse buys a tighter border-to-fill relationship. Both were
used above.

### The neutrals

Everything that is not one of the eight palette hues is a **pure grey — chroma exactly zero**. There is no
tinted grey anywhere in the file, and no near-neutral hiding at low chroma:

| Value | Lightness | Used by |
|---|---|---|
| `#ffffff` | 1.000 | key fill, combo-key fill |
| `#f4f4f4` | 0.967 | the ground — panel, plus eight small rects that mask the brace lines behind their labels |
| `#d5d5d5` | 0.872 | section divider rule |
| `#cdcdcd` | 0.847 | key stroke, combo-key stroke, HRM stroke |
| `#727272` | 0.551 | HRM sub-labels, icons, section headers, brace lines, brace labels |
| `#404040` | 0.372 | `.t-gry`, the grey combo label |
| `#282828` | 0.277 | key legends (`.kl`, `.klm`) |
| `#000000` | 0.000 | drop-shadow flood only, at `18` alpha |

These were previously Tailwind's `gray` ramp, which is cool — every one sat around h≈258 with chroma rising from
0.009 at the lightest to 0.031 at the darkest, so the cast was strongest in the key legends where it showed most.
That was consistent while the ground belonged to the same ramp. Once the ground went neutral the greys were the
only cool thing left on the page, so they were neutralised too, **at unchanged lightness** — every value above is
within 0.0015 of the lightness it replaced, so all contrast relationships carry over untouched and only the cast
is gone.

**Neutral is the load-bearing choice, not just a tidy one.** The palette spans the full hue circle, warm and
cool. A tinted grey ramp necessarily sides with one half of it: the old cool greys sat in the same family as the
blue and purple elements, giving those a faintly related field that red, orange and yellow did not get.
Pure grey is the only ramp that favours nothing. If you ever warm or cool these, expect it to show up as one end
of the palette looking more "designed in" than the other.

**One caution on the ground.** At 0.967 it is only 0.033 in lightness below white, and white is the dominant
surface here — 51 white keymap keys and 39 white combo keys against 39 tinted keys. That gap is the single most
load-bearing contrast in the diagram, and it is deliberately narrow: the previous `#eef0f3` gave 0.046. Going
lighter still would leave the all-white rows on BASE and NUMBER leaning entirely on the stroke and the shadow.
Note that the direction is asymmetric — lightening the ground *increased* contrast for everything darker than it
(the divider went 0.083 to 0.096), so only the white surfaces pay.


Note that hue meanings are mostly global but not entirely. Pink means punctuation on BASE and window
management on NAV; teal means layer switching on BASE and app switching on NAV; blue covers both the NAV arrow
keys and the window/tiling combos. NAV carries more categories than there are comfortably distinguishable hues, so it
is treated as its own colour world; only green holds a single meaning everywhere. Pink's and teal's two meanings
are at least on different layers. Blue's are not, which is why that pair leans on the key/stripe treatment split
to stay apart — the arrows are keys, the tiling combos are stripes, and nothing on NAV is both.

Keys are therefore quiet and outlined; stripes are small enough to carry a stronger fill without shouting. The treatment tells you which kind of element you are looking at and never varies by layer; the hue tells you the category, and what a given hue *means* is per-layer (see the combo sections below). When adding a colour, match the treatment of its element type rather than copying a hex from a different element — a key and a stripe of the "same" colour are deliberately different tints.

### Navigation layer keys
Coloured backgrounds indicate action categories. All use the key treatment above — a near-white fill with a mid-strength stroke of the same hue:

| Category | Fill | Stroke | Keys |
|---|---|---|---|
| **Pink** | `#ffe7ff` | `#eea7ef` | window/app management (close, new) |
| **Red** | `#ffdcdc` | `#ff9a9b` | undo/redo/save |
| **Green** | `#e4ffdf` | `#98e488` | clipboard (cut, copy, paste) |
| **Yellow** | `#feffda` | `#dfdf6d` | text formatting (bold, italic, underline) |
| **Orange** | `#ffead2` | `#efb05e` | selection with arrow (◀ sel, sel ▶, ▼ sel) |
| **Blue** | `#dbe9ff` | `#8db8ff` | arrow keys (◀ ▼ ▶ ▲) |
| **Teal** | `#d5f8fc` | `#66d8e3` | app-switcher / launcher (alfred, switch) |
| **White** | `#ffffff` | `#cdcdcd` | utility / modifier-style keys (esc, lock, ctrl, backspace, return, edit, open, emoji) |

NAV still reads as the busiest layer, because 21 of its keys are tinted against 18 across BASE and NUMBER combined — and NAV's 21 carry six hues where BASE's 18 carry two. That is density and variety rather than a different palette, and is intended.

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

The stripe colour identifies the combo's output category, and differs by layer:

**BASE layer combos:**
- **Pink** (stripe `#ffe0ff`, label `#703472`) — punctuation/symbol combos (`~`, `` ` ``, `_`, `@`, `(`, `—`, `&`, `)`)
- **Teal** (stripe `#d1f8fc`, label `#005b62`), labelled `lyr` — the R+T+A+E 4-key combo (layer toggle)

The `lyr` stripe carries its link to the thumb keys by **hue**: teal is the layer-switching colour on BASE, so
`lyr` and the `nav`/`num` thumbs read as one category despite being different element types. It is the minority
colour in its own grid — four teal stripes among sixteen pink — which makes it easy to pick out.

### Combos that are deliberately not drawn

Some combos exist in `keymap.c` but are intentionally omitted from this diagram. **Their absence is not a mismatch with the source, and they should not be "restored" by anyone reconciling the two.**

| Combo | Output | Defined in `keymap.c` as |
|---|---|---|
| L + D + O + U | Spanish input | `spanish[]` |
| D + W | `-` (hyphen) | `hyphen[]` |

The diagram is a legibility aid rather than an exhaustive index — the combo grid only stays readable at a glance with so many stripes on it. Which combos are omitted is a presentation choice and may change between iterations; `keymap.c` remains the complete and authoritative list.

One visible consequence: in BASE combo row 1 the `D` position now carries no stripe at all. It is still part of the L+D+W `num word` brace below it — braces and stripes are independent annotations, so an unstriped key may still appear in a brace.

**NAV layer combos:**
- **Pink** (stripe `#ffe0ff`) — window management (`quit`, `min`)
- **Blue** (stripe `#d6e5ff`) — window/tiling actions (`scr shot`, `zoom -`, `zoom +`, `del file`), matching the blue arrow keys
- **Green** (stripe `#d8f8d0`) — clipboard/editing actions (`all`, `pst text`)
- **Teal** (stripe `#d1f8fc`) — tab/window switching (`tab ◀`, `tab ▶`, `win ◀`, `win ▶` — word over arrow, two lines), matching the teal app-switcher NAV keys

**◆ The blue stripes are heavier than the rest of the tier** — 0.081 in lightness below the white combo key,
against pink's 0.059, green's 0.054 and teal's 0.047. Blue cannot be both light and chromatic: matched to the
tier on lightness its chroma falls to 0.029 and it reads badly washed out. 0.081 is a compromise that keeps
chroma at teal's level while shedding most of the excess weight. Blue and teal stripes never sit adjacent — blue
occupies the left half of the NAV grid, teal the right — so the two do not have to separate at close range.

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
| Keys | Output | Colour | Notes |
|---|---|---|---|
| W + Z | `~` | pink | tilde |
| ' + F | `` ` `` | pink | backtick |
| L + D + W | `num word` | — | 3-key brace |
| F + O + U | `caps word` | — | 3-key brace |

**Row 2** (physical row 2: N R T S G / Y H A E I):
| Keys | Output | Colour |
|---|---|---|
| R + T + A + E | `lyr` (layer toggle) | blue |
| S + G | `_` | pink |
| Y + H | `@` | pink |
| R + T + S | `del word` — 3-key brace | — |
| H + A + E | `enter` — 3-key brace | — |

**Row 3** (physical row 3: Q X M C V / K P , . :;):
| Keys | Output | Colour |
|---|---|---|
| X + M | `(` | pink |
| M + C | `—` (em dash) | pink |
| P + , | `&` | pink |
| , + . | `)` | pink |
| X + M + C | `tab` — 3-key brace | — |
| P + , + . | `send` (Cmd+Enter) — 3-key brace | — |

### NAV layer combos (3 rows)

**Row 1** (physical NAV row 1: esc ⌫ close min italic / edit ◀sel ▲ sel▶ lock):
| Keys | Output | Colour |
|---|---|---|
| ⌫ + close | `quit` | pink |
| close + min | `new` | pink |
| min + italic | `del file` | purple |
| ◀sel + ▲ | `tab` / `◀` | teal |
| ▲ + sel▶ | `tab` / `▶` | teal |
| ⌫ + close + min | `tile left` — 3-key brace | — |

**Row 2** (physical NAV row 2: ctrl cut copy paste bold / (blank) ◀ ▼ ▶ ⌫):
| Keys | Output | Colour |
|---|---|---|
| cut + copy | `all` | green |
| copy + paste | `pst text` | green |
| paste + bold | `scr shot` | purple |
| cut + copy + paste | `fullscreen` — 3-key brace | — |

**Row 3** (physical NAV row 3: undo redo save ↩ under / open alfred ▼sel switch ☺):
| Keys | Output | Colour |
|---|---|---|
| redo + save | `zoom −` | purple |
| save + ↩ | `zoom +` | purple |
| alfred + ▼sel | `win` / `◀` | teal |
| ▼sel + switch | `win` / `▶` | teal |
| undo + redo + save | `tile right` — 3-key brace | — |
| ◀ + ▼ + ▶ | `swap screen` — 3-key brace | — |

---

## CSS Classes Quick Reference

| Class | Usage |
|---|---|
| `.kl` | Normal key label (13px, dark) |
| `.klm` | HRM main label (13px, dark neutral — same as `.kl`) |
| `.kls` | HRM modifier sub-label (9px, neutral grey) |
| `.klp` | Thumb key main label (11px, teal) — currently unused |
| `.klps` | Thumb key sub-label (9px, teal) — also the `num` thumb's space glyph, at an inline 20px |
| `.kln` | Navigation layer key label (11px) |
| `.ico` | Icon/symbol key (24px, grey, light weight) |
| `.sec` | Section title (BASE / NUMBERS / NAVIGATION) |
| `.combo-key` | Combo key box (white fill, grey stroke) |
| `.cl-m` | Base combo label, single char (12px) |
| `.cl-s` | Combo label, multi-char (9px) |
| `.cl-gr` | 3-key brace label (9px, grey, dimmed) |
| `.cb-gr` | Brace/bracket line strokes |
| `.t-*` | Text colour overrides (pnk, grn, red, tel, ora, blu, yel, gry) |

---

## Variants

Two versions of the thumb treatment are kept, one per commit on this branch. Everything else in this document
applies to both.

| Version | Thumb fill | Thumb stroke | HRM |
|---|---|---|---|
| **bordered thumbs** | `#eafcfe` | `#95d0d6` teal, damped | `#feffe9` (70%) |
| **thumbs as HRMs** | `#eafcfe` | `#cdcdcd` neutral | `#ffffef` (78%) |

**The values quoted throughout this document are those of _bordered thumbs_.** Where the other version differs,
it differs only in the two rows above — the thumb stroke and the HRM blend. Nothing else in the diagram changes
between them.

**Thumbs as HRMs** puts the thumb keys on the HRM formula: tinted fill, neutral stroke, neutral labels, all the
hue in the fill. That makes the two hold-for-a-modifier key types one category rather than two exceptions, and
restores the property that every key on BASE and NUMBER carries the `#cdcdcd` border. Its HRM sits at 78%
because with a neutral thumb border the thumbs carry *less* colour than the home rows, so the compensation runs
the opposite way — see the blend table under [Home-row mods](#home-row-mods-hrms).

**Bordered thumbs** keeps the thumbs visually distinct, with a teal border damped to about 60% of the rule
value. Its HRM sits at 70% to hold parity against that border, which costs a little bleed with NAV's formatting
keys. That trade is the main thing separating the two.
