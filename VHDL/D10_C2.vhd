library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D10_C2 is
	 port(
		 clk : in STD_LOGIC;
		 y : out STD_LOGIC
	     );
end D10_C2;

architecture D10_C2 of D10_C2 is
begin
	process(clk)
	begin
		if(clk='1') then y<='1';
		else y<='0';
		end if;
	end process;
end D10_C2;
--clk=0.5hz