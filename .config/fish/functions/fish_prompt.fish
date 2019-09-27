#!/usr/bin/fish

function fish_prompt
	set_color red --bold
	printf "["
	set_color green
	printf "%s@%s" "$USER" "$hostname"
	set_color white
	printf ":"
	set_color blue
	printf "%s" (prompt_pwd)
	set_color red --bold
	printf "] "
	set_color normal
end