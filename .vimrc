:set background=dark
:inoremap ( ()<left>
:inoremap (( (
:inoremap {{ {
:inoremap [ []<left>
:inoremap {<CR> {<CR>  <CR>}<up><right>
:inoremap <expr> ) strpart(getline('.'), col('.')-1, 1) == ")" ? "\<Right>" : ")"
:inoremap <expr> } strpart(getline('.'), col('.')-1, 1) == "}" ? "\<Right>" : "}"
:inoremap <expr> ] strpart(getline('.'), col('.')-1, 1) == "]" ? "\<Right>" : "]"
:nmap ; :
:nmap , ;
:nmap  0i//
:set cindent
:set autoindent
:set tabstop=2 " tab is 2 spaces
:set expandtab " convert tabs to spaces
:set shiftwidth=2 " no of spaces for autoindent
:set number " show line numbers
:set showmatch " show matching parens
:set hlsearch " highlight search terms
:set incsearch " highlight matching search terms while typing
:set undolevels=500
