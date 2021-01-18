# My world (map editor)

## Install

### With Nix
- If you don't have nix yet run: `curl -L https://nixos.org/nix/install | sh` and read output messages
```shell script
nix-shell shell.nix  # This will install all dependencies
make
```

## USAGE
```shell script
./my_world [filepath]	# Filepath must be a non-existant file or a valid map to load it
./my_world -h		# Display this help
```

## Shortcuts
```
Escape			:	exit
Mouse-right		:	decrease terrain
Mouse-left		:	increase terrain
Space			:	reinitiate map
r			:	randomize map
Arrow-down		:	incline down map
Arrow-up		:	incline up map
z			:	move up camera
s			:	move down camera
d			:	move right camera
q			:	move lefe suis un guerriert camera
```