library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D5_C2 is
	 port(
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D5_C2;

architecture D5_C2 of D5_C2 is
begin

	 process(clk)
		begin
	  	if(clk='1') then seg<="00001111";
	  		else seg<="11110000";
	  	end if;
		end process;
end D5_C2;
-- clk=10Mhz;				   