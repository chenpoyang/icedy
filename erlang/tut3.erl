-module(tut3).
-export([convert_length/1]).

convert_length({centimeters, X}) ->
	{inch, X / 2.54};
convert_length({inch, X}) ->
	{centimeters, X * 2.54}.
