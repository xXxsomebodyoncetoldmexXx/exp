function car
	g++ -std=c++17 -Wall -Wextra -Ofast -DLOCAL_PROJECT $argv && echo "[RUN]" && ./a.out
end

function car(){
  g++ -std=c++17 -Wall -Wextra -Ofast -DLOCAL_PROJECT $1 && echo "[RUN]" && ./a.out
}
