K=keyboards/ergodox_ez/glow/keymaps/dave-thompson
git reset -q
for pair in keymap.c:dave-thompson.c config.h:config_dave-thompson.h rules.mk:rules.mk; do
  src=${pair%%:*}; dst=${pair#*:}
  git update-index --add --cacheinfo "100644,$(git rev-parse HEAD:$K/$src),$dst"
  git rm -q --cached "$K/$src"
done
git add -A design $K/design
git commit -m "refactor: move keymap files to userspace root (unchanged)"