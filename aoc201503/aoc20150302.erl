-module(robosanta).

-export([main/0]).

move([], Ent0, Ent1, Visited) ->
    map_size(Visited);
move([Cur | Rest], Ent0, Ent1, Visited) ->
    {CurX, CurY} = Ent0,
    NewEnt0 = case Cur of
        $^ -> 
            { CurX, CurY + 1};
        $> ->
            { CurX + 1, CurY};
        $v ->
            { CurX, CurY - 1};
        $< ->
            { CurX - 1, CurY};
        _ ->
            Ent0
    end,
    NewVisited = Visited#{NewEnt0 => 1},
    move(Rest, Ent1, NewEnt0, NewVisited).


main() ->
    Santa = {0,0},
    Robo = {0,0},
    Visited = #{{0,0} => 1},
    case file:read_file("input.txt") of
        {ok, BinaryData} ->
            Instructions = binary_to_list(BinaryData),
            Result = move(Instructions, Santa, Robo, Visited),
            io:format("answer: ~p~n", [Result]);
        {error, _} ->
                io:format("something went wrong reading file")
    end.




    
    



 %
 % the following year santa creates a robot version of himself to speed up the process
 %
 % santa and robo-santa start at the same location (delivering two presents to the same starting house)
 %
 % they take turns.... moving based on instructiohns from the elf, who is eggnoggedly reading from the same script as the previous year.
 %
 % this year, how many houses receive at least one present.
 %
 %
 % example 1:
 %
 % ^ v
 %
 % two santas... starting state (2) -> santa -> robo... (2) + 1 + 1 (3) houses...
 %
 %
 %
 % notes:
 %
 % what do i have???
 %
 % instructions are in 4 directions (x%y coordinate system)
 %
 % we can have a position abstraction % position can be thought of as a house
 %
 % position(x,y, visited)
 %
 %
 % observations:
 %
 % erlang is about data and operations on that data
 % , it is very clear about what state transitions are occuring.
 %
 % in comparision to C. before we do anything, we need to understand the memory situation before solving the problem. 
 %
 % and the standard library offers some basic data structures like map, sets, list to make implementation clean(you don't have you implement it yourself).
 % in C we are not given this luxary, we have to implement some basic data structures ourselves. (which makes C a good programming language to understand
 % how the machine works at a low level, but forces us to really understand fundamental structures)
 %
 %
 %
