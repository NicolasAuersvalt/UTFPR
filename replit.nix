{ pkgs }: {
	deps = [
   pkgs.haskellPackages.snap-templates
   pkgs.vim
   pkgs.vimPlugins.vim-helm
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}