# DWMBlocks Production Branch Management

## Updating from Upstream

### Prerequisites
Ensure the upstream remote is configured:
```bash
git remote add upstream https://github.com/torrinfail/dwmblocks.git
```

### Step 1: Sync Master with Upstream
First, update the `master` branch with upstream changes:
```bash
git checkout master
git fetch upstream master
git rebase upstream/master
git push origin master
```

**Note**: There should be no conflicts here if `master` remains unmodified locally.

### Step 2: Rebase Production Branch

**Warning**: This may produce conflicts that need to be resolved.

Rebase `prod` branch against the updated `master`:
```bash
git checkout prod
git rebase master
```

#### Handling Conflicts
If merge conflicts occur:

1. **Check conflicted files**:
   ```bash
   git status
   ```

2. **Resolve conflicts** in each file:
   - Look for conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`)
   - Edit files to resolve conflicts
   - Remove conflict markers

3. **Stage resolved files** and continue:
   ```bash
   git add blocks.def.h dwmblocks.c
   git rebase --continue
   ```

4. **If things go wrong**, abort and try again:
   ```bash
   git rebase --abort
   ```

### Step 3: Build and Test

After rebasing, rebuild and test dwmblocks:
```bash
make clean && make
pkill dwmblocks
./dwmblocks
```

Verify all blocks are working correctly:
```bash
# Test signal updates
pkill -RTMIN+10 dwmblocks  # Volume
pkill -RTMIN+11 dwmblocks  # Brightness
```

### Step 4: Push Changes

Once everything is working:
```bash
git push --force-with-lease origin prod
```

**Note**: Force push is required after rebasing. The `--force-with-lease` option ensures you don't overwrite any remote changes you haven't seen.

## Quick Reference

### Check Current Branch Status
```bash
git status
git log --oneline --graph --decorate -10
```

### View Differences
```bash
git diff master..prod  # See changes in prod vs master
git diff HEAD~1       # See last commit changes
```

### Emergency Rollback
If an update breaks something critical:
```bash
git checkout prod
git reset --hard origin/prod  # Reset to last known good state
```

### Backup Configuration
Before major updates, backup your custom configuration:
```bash
cp blocks.h blocks.h.backup
cp blocks.def.h blocks.def.h.backup
```

## Important Notes

1. **Preserve master** - Keep it synchronized with upstream, don't add custom changes
2. **Test thoroughly** - Always test after rebasing before pushing
3. **Keep backups** - Save your `blocks.h` and any custom scripts before updates
4. **Document changes** - Keep notes on custom modifications for easier conflict resolution

## Common Conflict Points

When updating from upstream, conflicts typically occur in:
- `blocks.def.h` - Block definitions and configuration
- `dwmblocks.c` - If you've modified core functionality
- `Makefile` - If you've changed build settings

## Production Block Scripts

Current production blocks use scripts located in:
```
$HOME/.config/dwmblocks/
├── battery.sh
├── brightness.sh
├── cpu-temperature.sh
├── date.sh
├── disk.sh
├── memory.sh
├── reboot-required.sh
└── volume.sh
```

Ensure these scripts remain executable and accessible after updates.