library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;

entity D8_C2 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D8_C2;
architecture D8_C2 of D8_C2 is
begin
	process(rst,clk)
	variable dem:integer range 0 to 127;
	begin
		if (rst='1') then dem:=0;
		else
			if (rising_edge(clk)) then
				if(dem=0) then dem:=127;
				else dem:=dem-1;
				end if;
			end if;
		end if;		  
		seg<=conv_std_logic_vector(dem,8);
	end process;
end D8_C2;
-- rst=0 or 78Khz; clk=25Mhz;