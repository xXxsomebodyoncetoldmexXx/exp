function fcp
	rsync -v -h -r -progress $argv
end


function fcp(){
  rsync -v -h -r -progress $1
}
