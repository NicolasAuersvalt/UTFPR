{ pkgs }: {
	deps = [
   pkgs.mailutils
   pkgs.imagemagick
   pkgs.unzip
   pkgs.mtools
   pkgs.haskellPackages.snap-templates
   pkgs.vim
   pkgs.vimPlugins.vim-helm
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}